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
    if (argc < 2) {
        printf("Use: tdmsreader your_file_name.tdms\n");
        return 1;
    }

    std::unique_ptr<TFile> outFile(TFile::Open("testFile.root", "RECREATE"));

    std::string fileName = argv[1];

    // Parse from the fileName
    ParserWrapper parser(fileName);

    if (!parser.IsValid()) {
        return 2;
    }

    size_t groupCount = parser.GroupCount();
    printf("\nNumber of groups: %zu\n", groupCount);

    for (size_t gi = 0; gi < groupCount; gi++) {
        if (parser.SkipGroup(gi)) { continue; }
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

		parser.GetGroupProperties(tree.get(), gi, false);

        tree->Fill();
        tree->Write();
    }
    outFile->Close();

    printf("\nSuccessfully parsed file '%s' (size: %lld bytes).\n",
           fileName.c_str(), parser.fileSize);
    printf("Done '%s'!\n", fileName.c_str());

    return 0;
}
