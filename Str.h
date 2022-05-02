#ifndef STR_H
#define STR_H

#include <iostream>

char *StrCrypt(char *SrcStr, int Length, char Key);

std::string StrCrypt(std::string &SrcStr, int Length, char Key);


#endif