#include "tdmsReader/TdmsParser.h"
#include "tdmsReader/TdmsGroup.h"
#include "tdmsReader/TdmsChannel.h"
#include <math.h>
#include <memory>
#include <string.h>
#include <cstdlib>
#include <TTree.h>
#include <TFile.h>
#include <string>

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
	int i = 20;
	/* for (unsigned int i = 0; i < groupCount; i++){ */
	TdmsGroup *group = parser.getGroup(i);
	/* if (!group) */
	/* 	continue; */

	unsigned int channelsCount = group->getGroupSize();
	if (channelsCount)
		printf("\nGroup %s (%d/%d) has %d channels:\n\n", group->getName().c_str(), i + 1, groupCount, channelsCount);
	else
		printf("\nGroup %s (%d/%d) has 0 channels.\n", group->getName().c_str(), i + 1, groupCount);

	std::unique_ptr<TFile> outFile(TFile::Open("testFile.root", "RECREATE"));
	auto tree = std::make_unique<TTree>("TRREEEE", "ACTUALLY THE TREE");

	/* Branch branch; */
	/* tree->Branch("channel", &branchStruct, vars.c_str()); */

	std::vector<uint8_t>WCM;
	tree->Branch("wcm", &WCM);

	std::vector<uint16_t>MAX;
	tree->Branch("max", &MAX);

	std::vector<uint32_t>TOT;
	tree->Branch("tot", &TOT);

	std::vector<uint32_t>INTEGRAL;
	tree->Branch("intergral", &INTEGRAL);

	std::vector<uint32_t>TIME;
	tree->Branch("time", &TIME);

	std::vector<uint64_t>COUNTER;
	tree->Branch("counter", &COUNTER);

	for (unsigned int j = 0; j < 6; j++) {
		TdmsChannel *ch = group->getChannel(j);
		if (ch) {
			unsigned long long dataCount = ch->getDataCount();
			if (dataCount == 0) {
				continue;
			}

			printf("%d) Channel %s has %lld values\n", j + 1, ch->getName().c_str(), dataCount);

			unsigned int type = ch->getDataType();
			std::cout << "type: " << type << std::endl;

			if (dataCount){
				std::vector<double> data = ch->getDataVector();

				if (j % 6 == 0) { // WCM
					auto count = std::to_string(dataCount);
					/* std::string	vars = "wcm["+count+"]/b:max["+count+"]/s:tot["+count+"]/i:integral["+count+"]/i:time["+count+"]/i:counter["+count+"]/l"; */
					/* tree->Branch(("channel_"+std::to_string(j/6)).c_str(), &branchStruct, vars.c_str()); */
					/* tree->Branch(("channel_"+std::to_string(j/6)).c_str(), &branch); */

					std::cout << "wcm" << std::endl;
					WCM = std::vector<uint8_t>(data.begin(),data.end());
				}
				else if (j % 6 == 1) { // MAXIMUM
					std::cout << "MAX" << std::endl;
					MAX = std::vector<uint16_t>(data.begin(),data.end());
				}
				else if (j % 6 == 2) { // ToT
					std::cout << "Tot" << std::endl;
					TOT = std::vector<uint32_t>(data.begin(),data.end());
				}
				else if (j % 6 == 3) { // Integral
					std::cout << "Integral" << std::endl;
					INTEGRAL = std::vector<uint32_t>(data.begin(),data.end());
				}
				else if (j % 6 == 4) { // Time
					std::cout << "Time" << std::endl;
					TIME = std::vector<uint32_t>(data.begin(),data.end());
				}
				else if (j % 6 == 5) { //Counter
					std::cout << "Counter" << std::endl;
					COUNTER = std::vector<uint64_t>(data.begin(),data.end());

					tree->Fill();
				}

				std::cout << data.size() << std::endl;
				if ((type == TdmsChannel::tdsTypeComplexSingleFloat) || (type == TdmsChannel::tdsTypeComplexDoubleFloat)){
					std::vector<double> imData = ch->getImaginaryDataVector();
					if (!imData.empty()){
						double iVal1 = imData.front(), iVal2 = imData.back();
						std::string fmt = "\t%g";
						fmt.append((iVal1 < 0) ? "-i*%g ... %g" : "+i*%g ... %g");
						fmt.append((iVal2 < 0) ? "-i*%g\n" : "+i*%g\n");
						printf(fmt.c_str(), data.front(), fabs(iVal1), data.back(), fabs(iVal2));
					}
				} else {
					if (!data.empty())
						printf("\t[begin...end]: %g ... %g\n", data.front(), data.back());

					printf("\t[min...max]: %g ... %g\n", ch->getMinDataValue(), ch->getMaxDataValue());

					if (dataCount)
						printf("\taverage data value: %g\n", ch->getDataSum()/dataCount);
				}
			}

			if (showProperties){
				auto propertyCount = ch->getPropertyCount();
				printf("and %d properties:\n%s\n", propertyCount, ch->propertiesToString().c_str());

				if (propertyCount) {
					auto m = ch->getProperties();

					std::vector<string> key, value;
					for(std::map<string,string>::iterator it = m.begin(); it != m.end(); ++it) {
					  key.push_back(it->first);
					  value.push_back(it->second);
					  std::cout << "Key: " << it->first << std::endl;
					  std::cout << "Value: " << it->second << std::endl;
					}
				}
			}
			if (storeValues)
				ch->freeMemory();
		}
	}
	/* tree->Fill(); */
	tree->Write();

	printf("\nSuccessfully parsed file '%s' (size: %lld bytes).\n", fileName.c_str(), parser.fileSize());
	printf("Done!\n");
	return 0;
}
