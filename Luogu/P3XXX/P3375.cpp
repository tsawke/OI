#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define S1(idx) S1.at(idx - 1)
#define S2(idx) S2.at(idx - 1)

template < typename T = int >
inline T read(void);

string S1, S2;
int len1, len2;
int kmp[1100000];

int main(){
    cin >> S1 >> S2;
    len1 = S1.size(), len2 = S2.size();
    int lst(0);
    for(int i = 2; i <= len2; ++i){
        while(lst && S2(lst + 1) != S2(i))lst = kmp[lst];
        if(S2(lst + 1) == S2(i))++lst;
        kmp[i] = lst;
    }lst = 0;
    for(int i = 1; i <= len1; ++i){
        while(lst && S2(lst + 1) != S1(i))lst = kmp[lst];
        if(S2(lst + 1) == S1(i))++lst;
        if(lst == len2)printf("%d\n", i - lst + 1), lst = kmp[lst];
    }for(int i = 1; i <= len2; ++i)printf("%d%c", kmp[i], i == len2 ? '\n' : ' ');
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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