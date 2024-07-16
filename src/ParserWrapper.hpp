#pragma once

#include "tdmsReader/TdmsChannel.h"
#include "tdmsReader/TdmsGroup.h"
#include "tdmsReader/TdmsParser.h"
#include <memory>
#include <string>
#include <TObjString.h>
#include <TParameter.h>
#include <TString.h>
#include <TTree.h>

class BranchStruct {
  public:
    std::vector<uint8_t> WCM;
    std::vector<uint16_t> MAX;
    std::vector<uint32_t> TOT;
    std::vector<uint32_t> INTEGRAL;
    std::vector<uint32_t> TIME;
    std::vector<uint64_t> COUNTER;
};

class ParserWrapper {
  public:
    ParserWrapper(std::string filePath);

    bool IsValid() const;
    size_t GroupCount() const;
    size_t ChannelCount(size_t groupIndex) const;
    bool ShouldSkipGroup(size_t groupIndex) const;
    TdmsChannel *GetChannel(size_t groupIndex, size_t channelIndex) const;
    void GetGroupProperties(TTree *tree, size_t groupIndex, bool debug=false) const;
    void ParseBranch(TdmsChannel *ch, TTree *tree, size_t &dataID, size_t &channelID);

    long long fileSize;
    std::string fileName;

  private:
    std::unique_ptr<TdmsParser> ptr;
    BranchStruct bs[8];
    bool valid=true;

    void FinalizeChannel(TTree *tree, size_t &channelID);
    std::string GetFileName(const std::string filePath);
};
