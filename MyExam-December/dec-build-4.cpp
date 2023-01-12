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



template < typename T = int >
inline T read(void);

string filename = "dec-build/np_graph_isomorphism";
ll Prime[10] = {0, 114514123, 1145141, 998244353, (ll)1e9 + 7};

int main(){
    for(int id = 1; id <= 1; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = 4, P = Prime[rndd(1, 4)];
        fprintf(input, "%lld %lld\n", N, P);
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 2; id <= 2; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = 5, P = 11;
        fprintf(input, "%lld %lld\n", N, P);
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 3; id <= 4; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd(6, 10), P = Prime[rndd(1, 4)];
        fprintf(input, "%lld %lld\n", N, P);
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 5; id <= 9; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd(40, 59), P = Prime[rndd(1, 4)];
        fprintf(input, "%lld %lld\n", N, P);
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 10; id <= 10; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = 60, P = Prime[rndd(1, 4)];
        fprintf(input, "%lld %lld\n", N, P);
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 0; id <= 0; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd(30, 39), P = Prime[rndd(1, 4)];
        fprintf(input, "%lld %lld\n", N, P);
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
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