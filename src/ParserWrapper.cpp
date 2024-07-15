#include "ParserWrapper.hpp"

ParserWrapper::ParserWrapper(std::string filePath) {
    TdmsParser *parser = new TdmsParser(filePath, true);
    if (parser->fileOpeningError()) {
        printf("File Opening Error - there was a problem opening selected file (%s)\n",
               filePath.c_str());
        this->valid = false;
        return;
    }

    printf("Parsing TDMS File: %s \n", filePath.c_str());
    bool verbose = false;
    parser->read(verbose);

    this->ptr = std::unique_ptr<TdmsParser>(parser);
    this->fileSize = ptr->fileSize();
    this->valid = true;
    this->fileName = GetFileName(filePath);
}

bool ParserWrapper::IsValid() const { return this->valid; }

size_t ParserWrapper::GroupCount() const { return ptr->getGroupCount(); }

size_t ParserWrapper::ChannelCount(size_t groupIndex) const {
    return ptr->getGroup(groupIndex)->getGroupSize();
}

bool ParserWrapper::ShouldSkipGroup(size_t groupIndex) const {
    TdmsGroup *group = ptr->getGroup(groupIndex);
    return !group || group->getGroupSize() == 0;
}

TdmsChannel *ParserWrapper::GetChannel(size_t groupIndex, size_t channelIndex) const {
    TdmsChannel *channel = ptr->getGroup(groupIndex)->getChannel(channelIndex);
    if (!channel || channel->getDataCount() == 0) {
        return nullptr;
    }

    return channel;
}

void ParserWrapper::GetGroupProperties(TTree *tree, size_t groupIndex, bool debug) const {
    TdmsGroup *group = ptr->getGroup(groupIndex);

    size_t i = 0;
    for (auto item : group->getObject()->getProperties()) {
        if (debug) {
            printf(" - %s, %s\n", item.first.c_str(), item.second.c_str());
        }

        if (i == 3 || i == 13 || i == 22) {
            auto p = new TObjString((item.first + ": " + item.second).c_str());
            tree->GetUserInfo()->Add(p);
        } else if (i == 12) {
            auto p =
                new TParameter<bool>(item.first.c_str(), item.second == "True");
            tree->GetUserInfo()->Add(p);
        } else {
            auto p = new TParameter<float>(item.first.c_str(),
                                           std::stof(item.second));
            tree->GetUserInfo()->Add(p);
        }

        i++;
    }
}

void ParserWrapper::ParseBranch(TdmsChannel *ch, TTree *tree, size_t &dataID, size_t &channelID) {
    // This catches even the empty channel problem because of how GetChannel works
    if (!ch) return;

    // fill data into prepared branch structure - with correct types!
    if (dataID == 0) {
        bs[channelID].WCM = std::vector<uint8_t>(ch->getDataVector().begin(),
                                                 ch->getDataVector().end());
    } else if (dataID == 1) {
        bs[channelID].MAX = std::vector<uint16_t>(ch->getDataVector().begin(),
                                                  ch->getDataVector().end());
    } else if (dataID == 2) {
        bs[channelID].TOT = std::vector<uint32_t>(ch->getDataVector().begin(),
                                                  ch->getDataVector().end());
    } else if (dataID == 3) {
        bs[channelID].INTEGRAL = std::vector<uint32_t>(
            ch->getDataVector().begin(), ch->getDataVector().end());
    } else if (dataID == 4) {
        bs[channelID].TIME = std::vector<uint32_t>(ch->getDataVector().begin(),
                                                   ch->getDataVector().end());
    } else if (dataID == 5) {
        bs[channelID].COUNTER = std::vector<uint64_t>(
            ch->getDataVector().begin(), ch->getDataVector().end());

        // when all branch data is prepared -> put all into the tree
        FinalizeChannel(tree, dataID, channelID);
        dataID = -1;
    }

    dataID++;
}

void ParserWrapper::FinalizeChannel(TTree *tree, size_t &dataID, size_t &channelID) {
    auto wcm_n      = "wcm"      + std::to_string(channelID);
    auto max_n      = "max"      + std::to_string(channelID);
    auto tot_n      = "tot"      + std::to_string(channelID);
    auto integral_n = "integral" + std::to_string(channelID);
    auto time_n     = "time"     + std::to_string(channelID);
    auto counter_n  = "counter"  + std::to_string(channelID);

    tree->Branch(wcm_n.c_str(),      &(bs[channelID].WCM));
    tree->Branch(max_n.c_str(),      &(bs[channelID].MAX));
    tree->Branch(tot_n.c_str(),      &(bs[channelID].TOT));
    tree->Branch(integral_n.c_str(), &(bs[channelID].INTEGRAL));
    tree->Branch(time_n.c_str(),     &(bs[channelID].TIME));
    tree->Branch(counter_n.c_str(),  &(bs[channelID].COUNTER));

    channelID++;
}

std::string ParserWrapper::GetFileName(const std::string filePath) {
    // extract fileName from the filePath - remove directories and .tdms at the end
    return filePath.substr(0, filePath.length()-5).substr(filePath.find_last_of("/") + 1);
}
