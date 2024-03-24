#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace Core
{
    inline std::vector<std::string> SplitStrings(std::string _String, const char& _rDelimiter);
}

namespace Core
{
    inline std::vector<std::string> SplitStrings(std::string _String, const char& _rDelimiter)
    {
        std::string TmpSubString;
        std::stringstream StringStream(_String);
        std::vector<std::string> SubStrings;

        while (getline(StringStream, TmpSubString, _rDelimiter))
        {
            SubStrings.push_back(TmpSubString);
        }

        return SubStrings;
    }
}