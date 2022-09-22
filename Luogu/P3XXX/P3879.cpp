#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

// struct Trie{
//     Trie* son[26];
//     vector < int > exist;
//     char c;
//     void* operator new(size_t);
//     Trie(char c):c(c){;}
//     Trie(void) = default;
// }tData[510000];

map < string, set < int > > mp;

int main(){
    int N = read();
    for(int i = 1; i <= N; ++i){
        int len = read();
        while(len--){
            string str; cin >> str;
            decltype(mp.begin()) ptr;
            if((ptr = mp.find(str)) != mp.end())ptr->second.insert(i);
            else{
                set < int > tmp;
                tmp.insert(i);
                mp.insert({str, tmp});
            }
        }
    }
    int M = read();
    while(M--){
        string str; cin >> str;
        decltype(mp.begin()) ptr;
        if((ptr = mp.find(str)) != mp.end()){
            for(auto i : ptr->second)printf("%d ", i);
            printf("\n");
        }else printf("\n");
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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