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

string filename = "dec-build/dress_up";

int main(){
    for(int id = 1; id <= 4; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd(80, 100), M = rndd(80, 100);
        fprintf(input, "%lld %lld\n", N, M);
        ll lst(114514);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rnddd(50) ? lst : lst = rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 2);
            if(opt == 1){
                ll L = rndd(1, N), R = rndd(L, N), X = rndd((ll)1e9 - (ll)1e8, (ll)1e9);
                fprintf(input, "R %lld %lld %lld\n", L, R, X);
            }else{
                ll L = rndd(1, N), R = rndd(L, N), K = rndd(0, (ll)1e3);
                if(rnddd(40))K = 0;
                fprintf(input, "Q %lld %lld %lld\n", L, R, K);
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
        ll N = rndd((ll)2e5 - (ll)1e4, (ll)2e5), M = rndd((ll)2e5 - (ll)1e4, (ll)2e5);
        fprintf(input, "%lld %lld\n", N, M);
        ll lst(114514);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rnddd(20) ? lst : lst = rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 2);
            if(opt == 1){
                ll L = rndd(1, N), R = L, X = rndd((ll)1e9 - (ll)1e8, (ll)1e9);
                fprintf(input, "R %lld %lld %lld\n", L, R, X);
            }else{
                ll L = rndd(1, (ll)1e4), R = rndd(N - (ll)1e4, N), K = rndd(0, (ll)1e3);
                if(rnddd(100))K = 0;
                fprintf(input, "Q %lld %lld %lld\n", L, R, K);
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 7; id <= 8; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)2e5 - (ll)1e4, (ll)2e5), M = rndd((ll)2e5 - (ll)1e4, (ll)2e5);
        fprintf(input, "%lld %lld\n", N, M);
        ll lst(114514);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rnddd(20) ? lst : lst = rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(2, 2);
            if(opt == 1){
                ll L = rndd(1, N), R = L, X = rndd((ll)1e9 - (ll)1e8, (ll)1e9);
                fprintf(input, "R %lld %lld %lld\n", L, R, X);
            }else{
                ll L = rndd(1, (ll)1e5), R = rndd(L, N), K = rndd(0, (ll)1e3);
                if(rnddd(40))K = 0;
                fprintf(input, "Q %lld %lld %lld\n", L, R, K);
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
    for(int id = 9; id <= 20; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        ll N = rndd((ll)2e5 - (ll)1e4, (ll)2e5), M = rndd((ll)2e5 - (ll)1e4, (ll)2e5);
        fprintf(input, "%lld %lld\n", N, M);
        ll lst = 114514;
        for(int i = 1; i <= N; ++i)
            fprintf(input, "%lld%c", rnddd(20) ? lst : lst = rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 2);
            if(opt == 1){
                ll L = rndd(1, N), R = L + rnddd(50), X = rndd((ll)1e9 - (ll)1e8, (ll)1e9);
                fprintf(input, "R %lld %lld %lld\n", L, R, X);
            }else{
                ll L = rndd(1, (ll)1e4), R = rndd(N - (ll)1e4, N), K = rndd(0, (ll)1e3);
                if(rnddd(40))K = 0;
                fprintf(input, "Q %lld %lld %lld\n", L, R, K);
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
        ll N = rndd((ll)2e5 - (ll)1e4, (ll)2e5), M = rndd((ll)2e5 - (ll)1e4, (ll)2e5);
        fprintf(input, "%lld %lld\n", N, M);
        ll lst(114514);
        for(int i = 1; i <= N; ++i)fprintf(input, "%lld%c", rnddd(50) ? lst : lst = rndd((ll)1e9 - (ll)1e8, (ll)1e9), i == N ? '\n' : ' ');
        for(int m = 1; m <= M; ++m){
            int opt = rndd(1, 2);
            if(opt == 1){
                ll L = rndd(1, N), R = rndd(L, N), X = rndd((ll)1e9 - (ll)1e8, (ll)1e9);
                fprintf(input, "R %lld %lld %lld\n", L, R, X);
            }else{
                ll L = rndd(1, N), R = rndd(L, N), K = rndd(0, (ll)1e3);
                if(rnddd(40))K = 0;
                fprintf(input, "Q %lld %lld %lld\n", L, R, K);
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