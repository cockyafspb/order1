#include "Str.h"
int main() {
    char* cSrcStr = "Hello World!";
    int cStrLen = 12;
    char key = 'k';
    char* cRes = StrCrypt(cSrcStr, cStrLen, key);
    char* cRes2 = StrCrypt(cRes, cStrLen, key);

    bool flag = true;
    for (size_t i = 0; i < cStrLen; ++i)
        if (cSrcStr[i] != cRes2[i])
            flag = false;

    if (flag){
        std::cout << "cSrcStr == cRes2" << std::endl;
    }
    else{
        std::cout << "cSrcStr != cRes2" << std::endl;
    }

    delete [] cRes;
    delete [] cRes2;

    std::string cppSrcStr = "Hello World!";
    int cppStrLen = 12;
    std::string cppRes = StrCrypt(cppSrcStr, cppStrLen, key);
    std::string cppRes2 = StrCrypt(cppRes, cppStrLen, key);

    if (cppSrcStr == cppRes2){
        std::cout << "cppSrcStr == cppRes2" << std::endl;
    }
    else{
        std::cout << "cppSrcStr != cppRes2" << std::endl;
    }

    return 0;
}
