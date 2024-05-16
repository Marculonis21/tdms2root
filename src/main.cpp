#include "tdmsReader/TdmsParser.h"
#include "tdmsReader/TdmsGroup.h"
#include "tdmsReader/TdmsChannel.h"
#include <TBranch.h>
#include <cstdint>

#include <math.h>
#include <memory>
#include <string.h>
#include <cstdlib>
#include <TTree.h>
#include <TFile.h>
#include <string>
#include <vector>

void help()
{
	std::cout << "Use: tdmsreader -option your_file_name.tdms" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "-h: print help information and exit" << std::endl;
	std::cout << "-p: display channel properties" << std::endl;
	std::cout << "-s: store channel data values" << std::endl;
	std::cout << "-v: verbose output" << std::endl;
}

void errorMessage()
{
	std::cout << "\nInput error: please provide a single valid *.tdms file name!" << std::endl;
}

void treeFill(TTree *tree, TdmsGroup *group, int channelsID, int groupID)
{
	TdmsChannel *ch = group->getChannel(channelsID*6);
	if (!ch) return;

	Int_t c = ch->getDataCount();
	if (c== 0) return;

	/* std::string	vars = "wcm["+count+"]/b:max["+count+"]/s:tot["+count+"]/i:integral["+count+"]/i:time["+count+"]/i:counter["+count+"]/l"; */
	/* std::cout << cnt << std::endl; */

	/* BranchStruct branchStruct; */
	std::string j = std::to_string(channelsID);
	/* std::string	vars = "wcm[count"+j+"]/b:max[count"+j+"]/s:tot[count"+j+"]/i:integral[count"+j+"]/i:time[count"+j+"]/i:counter[count"+j+"]/l"; */
	/* std::cout << cnt << std::endl; */
	/* std::cout << vars << std::endl; */

	/* Int_t count; */
	/* tree->Branch("count", &count, "count/I"); */
	/* tree->Branch("Count", &count, "count/I"); */
	/* tree->Branch(("channel_"+std::to_string(channelsID)).c_str(), &branchStruct, vars.c_str()); */

	/* std::vector<uint8_t>WCM; */
	/* uint8_t wcm[1000000]; */
	/* tree->Branch("Wcm", wcm, "wcm[count]/b"); */

	std::vector<uint8_t>WCM;
	tree->Branch(("wcm"+std::to_string(channelsID)).c_str(), &WCM);

	std::vector<uint16_t>MAX;
	tree->Branch(("max"+std::to_string(channelsID)).c_str(), &MAX);

	std::vector<uint32_t>TOT;
	tree->Branch(("tot"+std::to_string(channelsID)).c_str(), &TOT);

	std::vector<uint32_t>INTEGRAL;
	tree->Branch(("integral"+std::to_string(channelsID)).c_str(), &INTEGRAL);

	std::vector<uint32_t>TIME;
	tree->Branch(("time"+std::to_string(channelsID)).c_str(), &TIME);

	std::vector<uint64_t>COUNTER;
	tree->Branch(("counter"+std::to_string(channelsID)).c_str(), &COUNTER);

	TdmsChannel *ch1 = group->getChannel(channelsID*6 + 0);
	TdmsChannel *ch2 = group->getChannel(channelsID*6 + 1);
	TdmsChannel *ch3 = group->getChannel(channelsID*6 + 2);
	TdmsChannel *ch4 = group->getChannel(channelsID*6 + 3);
	TdmsChannel *ch5 = group->getChannel(channelsID*6 + 4);
	TdmsChannel *ch6 = group->getChannel(channelsID*6 + 5);

	WCM		 = std::vector<uint8_t>(ch1->getDataVector().begin(),ch1->getDataVector().end());
	MAX 	 = std::vector<uint16_t>(ch2->getDataVector().begin(),ch2->getDataVector().end());
	TOT 	 = std::vector<uint32_t>(ch3->getDataVector().begin(),ch3->getDataVector().end());
	INTEGRAL = std::vector<uint32_t>(ch4->getDataVector().begin(),ch4->getDataVector().end());
	TIME     = std::vector<uint32_t>(ch5->getDataVector().begin(),ch5->getDataVector().end());
	COUNTER  = std::vector<uint64_t>(ch6->getDataVector().begin(),ch6->getDataVector().end());

	ch2->freeMemory();
	ch1->freeMemory();
	ch3->freeMemory();
	ch4->freeMemory();
	ch6->freeMemory();
	ch5->freeMemory();

	tree->Fill();
	tree->ResetBranchAddresses();
}

int main(int argc, char *argv[])
{
	std::cout << "\nNational Instruments TDMS file reader by Ion Vasilief (C) 2017 - 2020" << std::endl;

	if (argc < 2){
		std::cout << "Use: tdmsreader your_file_name.tdms" << std::endl;
		errorMessage();
		return 0;
	}

	if ((argc == 2) && (strcmp(argv[1], "-h") == 0)){
		help();
		exit(0);
	}

	bool verbose = false, storeValues = true, showProperties = false;
	if ((argc == 3) && (strchr(argv[1], '-'))){
		if (strchr(argv[1], 'p'))
			showProperties = true;
		if (strchr(argv[1], 's'))
			storeValues = true;
		if (strchr(argv[1], 'v'))
			verbose = true;
	}

	std::string fileName = (argc == 3) ? argv[2] : argv[1];
	TdmsParser parser(fileName, storeValues);
	if (parser.fileOpeningError()){
		errorMessage();
		return 0;
	}

	parser.read(verbose);

	unsigned int groupCount = parser.getGroupCount();
	printf("\nNumber of groups: %d\n", groupCount);

	std::unique_ptr<TFile> outFile(TFile::Open("testFile.root", "RECREATE"));
	TTree *tree = new TTree("T", "ACTUALLY THE TREE");
	for (unsigned int i = 0; i < groupCount; i++){
		TdmsGroup *group = parser.getGroup(i);
		if (!group)
			continue;

		unsigned int channelsCount = group->getGroupSize();
		if (channelsCount)
			printf("\nGroup %s (%d/%d) has %d channels:\n\n", group->getName().c_str(), i + 1, groupCount, channelsCount);
		else
			printf("\nGroup %s (%d/%d) has 0 channels.\n", group->getName().c_str(), i + 1, groupCount);

		
		for (unsigned int j = 0; j < channelsCount/6; j++) {
			std::cout << j << std::endl;
			treeFill(tree, group, j, i);
		}
	}

	tree->Write();
	outFile->Close();

	printf("\nSuccessfully parsed file '%s' (size: %lld bytes).\n", fileName.c_str(), parser.fileSize());
	printf("Done!\n");
	return 0;
}
