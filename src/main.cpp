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

void printProgress(double percentage) {
    int barWidth = 70;

    std::cout << "[";
    int pos = barWidth * percentage;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(percentage * 100.0) << " %\r";
    std::cout.flush();
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {

        printf("TDMS2ROOT v1.1 - ISOLDE CERN 2024 - MBecvar\n"
               "Use: tdms2root <file_name.tdms> <output_directory>\n");
        return 1;
    }

    bool showProgress = false;

    std::string filePath = argv[1];
    std::string outputDirectory = argv[2];
    if (argc == 4) {
        std::string printProgressArg = argv[3];
        showProgress = printProgressArg == "1";
    }

    // Parse from the fileName
    ParserWrapper parser(filePath);

    if (!parser.IsValid()) {
        return 2;
    }

    std::unique_ptr<TFile> outFile(TFile::Open((outputDirectory + "/" + parser.fileName +".root").c_str(), "RECREATE"));

    size_t groupCount = parser.GroupCount();
    if (showProgress) {
        printf("Number of groups: %zu\n", groupCount);
    }

    for (size_t gi = 0; gi < groupCount; gi++) {
        if (parser.ShouldSkipGroup(gi)) { 
            continue; 
        }

        if (showProgress && (gi % 10 == 0 || gi == groupCount-1)) {
            printProgress(double(gi+1)/groupCount);
        }

        // TTree for each group! 
        auto treeName = ("T_Pulse"+std::to_string(gi)).c_str();
        auto tree = std::make_unique<TTree>(treeName, "");

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

    printf("Successfully parsed file '%s' (size: %lld bytes).\n",
           filePath.c_str(), parser.fileSize);

    return 0;
}
