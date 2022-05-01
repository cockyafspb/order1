#include <iostream>

const char Alph[] = "ABCDEFGHIJKLMOPQRYSTUVWXYZ1234567890";
size_t maxIter = sizeof(Alph) - 1;

size_t Hash(const char *Passwd, int Len) {
    unsigned int res = 0;
    for (int i = 0; i < Len; i++) {
        res += Passwd[i];
    }
    return (res << 16) ^ (Passwd[0] << 14) + ((Passwd[Len - 1] ^ Len) >> (Len >> 1));
}

bool RestorePasswd(size_t HashValue, int MaxLength, char *Result, int *ResLength) {
    for (size_t strLen = 1; strLen < MaxLength; ++strLen) {
            for (size_t j = 0; j < maxIter; ++j) {
                for (size_t k = 0, div = 1; k < strLen; k++) //Цикл № 3
                {
                    Result[k] = Alph[(j / div) % (sizeof(Alph) - 1)];
                    div *= (sizeof(Alph) - 1);
                }
                if (Hash(Result, strLen) == HashValue) {
                    *ResLength = strLen;
                    return true;
                }
            }
        maxIter *= (sizeof(Alph) - 1);
    }
    return false;
}


int main() {
    char Password[50] = "";
    int length = 50;
    size_t hash = Hash("AAA", 3);
    bool res = RestorePasswd(hash, 50, Password, &length);

    if (res) {
        std::cout << "Password: " << Password << " Length: " <<
                  length << std::hex << " Hash: 0x" << hash << std::endl;
    } else {
        std::cout << "Not cracked! " << std::endl;
    }
    
    return 0;
}
