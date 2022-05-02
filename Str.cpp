#include "Str.h"

char *StrCrypt(char *SrcStr, int Length, char Key) {
    char* resStr = new char[Length + 1];
    for (size_t i = 0; i < Length; ++i) {
        resStr[i] = SrcStr[i] ^ Key;
    }
    resStr[Length] = '\0';
    return resStr;
}

std::string StrCrypt(std::string &SrcStr, int Length, char Key) {
    std::string resStr;
    for (size_t i = 0; i < Length; ++i) {
        resStr.push_back(SrcStr[i] ^ Key);
    }
    return resStr;
}
