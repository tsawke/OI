#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937_64 rnd(random_device{}());
long long rndd(long long l, long long r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template < typename T = int >
inline T read(void);

ll qpow_unmod(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

string filename = "dec-build/dote___strvct";

int main(){
    for(int id = 1; id <= 2; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)1e3 - (ll)1e2, (ll)1e3), M = rndd((ll)1e3 - (ll)1e2, (ll)1e3);
        fprintf(input, "%lld %lld\n", N, M);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 6);
            switch(opt){
                case 1:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
                case 2:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "2 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 3:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "3 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 4:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "4 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 5:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "5 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 6:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 3; id <= 4; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)5e4 - (ll)1e4, (ll)5e4), M = rndd((ll)5e4 - (ll)1e4, (ll)5e4);
        fprintf(input, "%lld %lld\n", N, M);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 6);
            switch(opt){
                case 1:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
                case 2:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "2 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 3:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "3 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 4:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "4 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 5:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "5 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 6:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 5; id <= 6; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)1.5e5 - (ll)5e4, (ll)1.5e5), M = rndd((ll)1.5e5 - (ll)5e4, (ll)1.5e5);
        fprintf(input, "%lld %lld\n", N, M);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 6);
            switch(opt){
                case 1:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
                case 2:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "2 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 3:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "3 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 4:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "4 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 5:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "5 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 6:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 7; id <= 10; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)3e5 - (ll)1e5, (ll)3e5), M = rndd((ll)3e5 - (ll)1e5, (ll)3e5);
        fprintf(input, "%lld %lld\n", N, M);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 6);
            while(opt == 4)opt = rndd(1, 6);
            switch(opt){
                case 1:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
                case 2:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "2 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 3:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "3 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 4:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "4 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 5:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "5 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 6:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 11; id <= 20; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)3e5 - (ll)1e5, (ll)3e5), M = rndd((ll)3e5 - (ll)1e5, (ll)3e5);
        fprintf(input, "%lld %lld\n", N, M);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 6);
            switch(opt){
                case 1:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
                case 2:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "2 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 3:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "3 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 4:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "4 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 5:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "5 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 6:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 0; id <= 0; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)3e5 - (ll)1e5, (ll)3e5), M = rndd((ll)3e5 - (ll)1e5, (ll)3e5);
        fprintf(input, "%lld %lld\n", N, M);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 6);
            switch(opt){
                case 1:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
                case 2:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "2 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 3:{
                    ll L = rndd(1, N), R = rndd(L, N), V = rndd(0, (ll)1e9);
                    fprintf(input, "3 %lld %lld %lld\n", L, R, V);
                    break;
                }
                case 4:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "4 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 5:{
                    ll L1 = rndd(1, N >> 1), R1 = rndd(L1, N >> 1), L2 = rndd(R1 + 1, N - (R1 - L1 + 1) + 1), R2 = L2 + (R1 - L1 + 1) - 1;
                    if(rnddd(50))swap(L1, L2), swap(R1, R2);
                    fprintf(input, "5 %lld %lld %lld %lld\n", L1, R1, L2, R2);
                    break;
                }
                case 6:{
                    ll L = rndd(1, N), R = rndd(L, N);
                    fprintf(input, "1 %lld %lld\n", L, R);
                    break;
                }
            }
        }
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