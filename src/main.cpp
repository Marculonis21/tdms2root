#include "tdmsReader/TdmsChannel.h"
#include "tdmsReader/TdmsGroup.h"
#include "tdmsReader/TdmsParser.h"
#include <TBranch.h>
#include <TDatime.h>
#include <TFile.h>
#include <TList.h>
#include <TObjString.h>
#include <TParameter.h>
#include <TString.h>
#include <TTree.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <memory>
#include <string.h>
#include <string>
#include <vector>

#include "ParserWrapper.hpp"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Use: tdms2root your_file_name.tdms output_directory/\n");
        return 1;
    }

    std::string filePath = argv[1];
    std::string outputDirectory = argv[2];

    // Parse from the fileName
    ParserWrapper parser(filePath);

    if (!parser.IsValid()) {
        return 2;
    }

    std::unique_ptr<TFile> outFile(TFile::Open((outputDirectory + "/" + parser.fileName +".root").c_str(), "RECREATE"));
    /* std::unique_ptr<TFile> outFile(TFile::Open("testFile.root", "RECREATE")); */

    size_t groupCount = parser.GroupCount();
    printf("\nNumber of groups: %zu\n", groupCount);

    for (size_t gi = 0; gi < groupCount; gi++) {
        if (parser.ShouldSkipGroup(gi)) { 
            continue; 
        }
        printf("Processing group %zu\n", gi);

        // TTree for each group! 
        auto tree = std::make_unique<TTree>("T_Pulse", "");

        // Run through channels
        size_t channelCount = parser.ChannelCount(gi);
        for (size_t chi = 0, dataID = 0, channelID = 0; chi < channelCount; chi++) {
            TdmsChannel *ch = parser.GetChannel(gi, chi);

            // dataID and channelID changed inside the parser
			parser.ParseBranch(ch, tree.get(), dataID, channelID);
        }

        // when data processed, get the group metadata (properties)
		parser.GetGroupProperties(tree.get(), gi, false);

        tree->Fill();
        tree->Write();
    }
    outFile->Close();

    printf("\nSuccessfully parsed file '%s' (size: %lld bytes).\n",
           filePath.c_str(), parser.fileSize);
    printf("Done '%s'!\n", filePath.c_str());

    return 0;
}
