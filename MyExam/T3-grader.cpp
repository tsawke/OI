#include <bits/stdc++.h>

using namespace std;

extern std::string EncryptMD5(std::string);
extern std::string HackLLQ(std::string);

map < string, string > idx;
bool inited(false);

void Init(void){
    for(int i = 0; i <= 9999; ++i){
        char* tmp = new char[10];
        sprintf(tmp, "%d", i);
        string tmps(tmp);
        string md5s = EncryptMD5(tmps);
        idx.insert(make_pair(md5s, tmps));
        delete[] tmp;
    }
}

std::string HackLLQ(std::string md5){
    if(!inited)Init(), inited = true;
    return idx[md5];
}