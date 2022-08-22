#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

struct Trie{
    int size;
    Trie *ls, *rs;
    Trie(int size){
        this->size = size;
        this->ls = this->rs = nullptr;
    }
};
void Insert(Trie *node, int val){

}
int main(){
    (void)read(); int x = read();
    Trie tmp(0); Trie *root = &tmp;
    int N = read();
    while(N--){
        int opt = read(), x = read();
        switch(opt){
            case 1:{}
        }
    }


    return 0;
}


template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}