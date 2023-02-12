#include "bin/EngineOptions.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <vadefs.h>

// i stole this template its mine now
template <class C, typename T>
bool contains(C&& c, T e) {
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};

namespace neoskye {

EngineOptions::EngineOptions() : title("Neoskye game") {
    this->InsertFlag("-width", "1280");
    this->InsertFlag("-height", "720");
    this->useVSync = true;
}

EngineOptions::EngineOptions(int argc, char** argv) {
    this->InsertFlag("-width", "1280");
    this->InsertFlag("-height", "720");
    this->useVSync = true;
    // i = 1 so we skip the first element which is the exectuable name
    for (int i = 1; i < argc; i++) {
        const auto item = argv[i];
        bool isFlag = contains(flagOpts, item);
        bool isSwitch = contains(switchOpts, item);
        if (isFlag && isSwitch)
            throw "Duplicate flag and switch!";
        if (isSwitch) {
            std::string flag(item);
            this->switches[flag] = true;
        }
        if (isFlag) {
            // can we look ahead one element?
            i++;
            if (i > argc) {
                std::cerr << "Failed to parse flag " << item << std::endl;
            }
            std::string _switch(item);
            std::string value(argv[i]);
            this->flags[_switch] = value;
        }
        // otherwise silently continue
    }
}

std::optional<uintptr_t> EngineOptions::GetUnsignedFlag(const std::string& key) const {
    std::optional<uintptr_t> retVal;
    if (this->flags.count(key) == 0) {
        return retVal;
    }
    retVal = std::make_optional(std::stoul(this->flags.at(key)));
    return retVal;
}

std::optional<intptr_t> EngineOptions::GetSignedFlag(const std::string& key) const {
    std::optional<intptr_t> retVal;
    if (this->flags.count(key) == 0) {
        return retVal;
    }
    retVal = std::make_optional(std::stoi(this->flags.at(key)));
    return retVal;
}

std::optional<std::string> EngineOptions::GetStringFlag(const std::string& key) const {
    std::optional<std::string> retVal;
    if (this->flags.count(key) == 0)
        return retVal;
    retVal = std::make_optional(this->flags.at(key));
    return retVal;
}

void EngineOptions::InsertFlag(const std::string& name, const std::string& value) { this->flags[name] = value; }

void EngineOptions::InsertFlagIfItDoesntExist(const std::string& name, const std::string& value) {
    if (this->flags.count(name) != 0)
        return;
    this->flags[name] = value;
}

void EngineOptions::DisableSwitch(const std::string& name) { this->switches[name] = false; }

void EngineOptions::EnableSwitch(const std::string& name) { this->switches[name] = true; }

} // namespace neoskye
