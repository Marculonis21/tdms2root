#include "tdmsReader/TdmsParser.h"
#include "tdmsReader/TdmsGroup.h"
#include "tdmsReader/TdmsChannel.h"
#include <TBranch.h>
#include <TParameter.h>
#include <TString.h>
#include <TObjString.h>
#include <TList.h>
#include <TDatime.h>
#include <cstdint>
#include <cstdio>
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

class BranchStruct
{
public:
	uint8_t WCM;
	uint16_t MAX;
	uint32_t TOT;
	uint32_t INTEGRAL;
	uint32_t TIME;
	uint64_t COUNTER;
};

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
	/* std::string	vars = "wcm"+j+"/b:max"+j+"/s:tot"+j+"/i:integral"+j+"/i:time"+j+"/i:counter"+j+"/l"; */
	/* std::cout << cnt << std::endl; */
	/* std::cout << vars << std::endl; */

	/* Int_t count; */
	/* tree->Branch("count", &count, "count/I"); */
	/* tree->Branch("Count", &count, "count/I"); */
	/* tree->Branch(("channel_"+std::to_string(channelsID)).c_str(), &branchStruct, vars.c_str()); */

	/* std::vector<uint8_t>WCM; */
	/* uint8_t wcm[1000000]; */
	/* tree->Branch("Wcm", wcm, "wcm[count]/b"); */

	BranchStruct bs{};

	tree->Branch(("group"+std::to_string(groupID)).c_str(), &bs, 1);

	std::vector<uint8_t>WCM;
/* 	tree->Branch(("group"+std::to_string(channelsID)+"/wcm").c_str(), &WCM); */

	std::vector<uint16_t>MAX;
/* 	tree->Branch(("group"+std::to_string(channelsID)+"/max").c_str(), &MAX); */

	std::vector<uint32_t>TOT;
/* 	tree->Branch(("group"+std::to_string(channelsID)+"tot").c_str(), &TOT); */

	std::vector<uint32_t>INTEGRAL;
/* 	tree->Branch(("group"+std::to_string(channelsID)+"integral").c_str(), &INTEGRAL); */

	std::vector<uint32_t>TIME;
/* 	tree->Branch(("group"+std::to_string(channelsID)+"time").c_str(), &TIME); */

	std::vector<uint64_t>COUNTER;
/* 	tree->Branch(("group"+std::to_string(channelsID)+"counter").c_str(), &COUNTER); */

	TdmsChannel *ch1 = group->getChannel(channelsID*6 + 0);
	TdmsChannel *ch2 = group->getChannel(channelsID*6 + 1);
	TdmsChannel *ch3 = group->getChannel(channelsID*6 + 2);
	TdmsChannel *ch4 = group->getChannel(channelsID*6 + 3);
	TdmsChannel *ch5 = group->getChannel(channelsID*6 + 4);
	TdmsChannel *ch6 = group->getChannel(channelsID*6 + 5);

	WCM		 = std::vector<uint8_t>(ch1->getDataVector().begin(),ch1->getDataVector().end());
	MAX		 = std::vector<uint16_t>(ch2->getDataVector().begin(),ch2->getDataVector().end());
	TOT 	 = std::vector<uint32_t>(ch3->getDataVector().begin(),ch3->getDataVector().end());
	INTEGRAL = std::vector<uint32_t>(ch4->getDataVector().begin(),ch4->getDataVector().end());
	TIME     = std::vector<uint32_t>(ch5->getDataVector().begin(),ch5->getDataVector().end());
	COUNTER  = std::vector<uint64_t>(ch6->getDataVector().begin(),ch6->getDataVector().end());
	for (int i = 0; i < WCM.size(); ++i) {
		bs.WCM		  = WCM[i];
		bs.MAX		  = MAX[i];
		bs.TOT	   	  = TOT[i];
		bs.INTEGRAL   = INTEGRAL[i];
		bs.TIME       = TIME[i];
		bs.COUNTER    = COUNTER[i];
		tree->Fill();
	}

	/* tree->Fill(); */
	/* tree->ResetBranchAddresses(); */

	ch1->freeMemory();
	ch2->freeMemory();
	ch3->freeMemory();
	ch4->freeMemory();
	ch6->freeMemory();
	ch5->freeMemory();
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

	/* for (unsigned int i = 0; i < groupCount; i++){ */

	for (unsigned int i = 0; i < 5; i++){
		printf("START group %d\n", i);

		TdmsGroup *group = parser.getGroup(i);
		if (!group) continue;

		auto tName = "T_Pulse" + std::to_string(i);
		auto tree = std::make_unique<TTree>(tName.c_str(), "");

		printf("Group object property count %d\n",group->getObject()->getPropertyCount());
		printf("Properties:\n");
		
		int _item = 0;
		for (auto item : group->getObject()->getProperties()) {
			printf(" - %s, %s\n", item.first.c_str(), item.second.c_str());

			if (_item == 3 || _item == 13 || _item == 22) {
				auto p = new TObjString((item.first + ": " + item.second).c_str());
				tree->GetUserInfo()->Add(p);
			}
			else if (_item == 12) {
				auto p = new TParameter<bool>(item.first.c_str(), item.second == "True");
				tree->GetUserInfo()->Add(p);
			}
			else {
				auto p = new TParameter<float>(item.first.c_str(), std::stof(item.second));
				tree->GetUserInfo()->Add(p);
			}

			_item++;
		}


		unsigned int channelsCount = group->getGroupSize();
		if (channelsCount == 0) continue;

		printf("\nGroup %s (%d/%d) has %d channels:\n\n", group->getName().c_str(), i + 1, groupCount, channelsCount);

		for (unsigned int j = 0; j < channelsCount; j++) {
			/* std::cout << j << std::endl; */
			/* treeFill(tree, group, j, i); */
			TdmsChannel *ch = group->getChannel(j);
			if (!ch) continue;
			if (ch->getDataCount() == 0) continue; 
			printf("%d: Channel %s has %lld data, %lld values, %d properties\n", j + 1, 
																				 ch->getName().c_str(), 
																				 ch->getDataCount(), 
																				 ch->getValuesCount(), 
																				 ch->getPropertyCount());

			/* for (int i = 0; i < std::min({(int)ch->getValuesCount(),100}); ++i) { */
				/* std::cout << ch->getValue(unsigned int) << std::endl; */
			/* double value = ch->getValue(10); */
			/* uint8_t _value = static_cast<uint8_t>(value); */
			/* } */
			/* std::cout << value << ", " << _value << std::endl; */
			/* printf("%lf, %u\n", value, _value); */

			/* printf("channel %d and %d properties:\n%s\n", j, ch->getPropertyCount(), ch->propertiesToString().c_str()); */
		}

	}

	/* tree->Write(); */
	/* outFile->Close(); */

	printf("\nSuccessfully parsed file '%s' (size: %lld bytes).\n", fileName.c_str(), parser.fileSize());
	printf("Done!\n");
	return 0;
}
