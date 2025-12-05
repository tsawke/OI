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

string filename = "dec-build/lets_play_dice";

void Build(int ids, int idt, ll limN, ll limM, bool limited = false, ll minusN = 100, ll minusM = 5){
    for(int id = ids; id <= idt; ++id){
        char inS[10000]; sprintf(inS, "%s%d.in", filename.c_str(), id);
        FILE* input = fopen(inS, "w");
        int T = rndd(7, 10);
        fprintf(input, "%d\n", T);
        for(int t = 1; t <= T; ++t){
            ll N, M;
            if(limited){
                N = rndd(5, 10), M = rndd(5, 10);
                while(qpow_unmod(M, N) > (ll)1e7)N = rndd(5, 10), M = rndd(5, 10);
            }else{
                N = rndd(max(1ll, limN - minusN), limN), M = rndd(max(1ll, limM - minusM), limM);
            }
            fprintf(input, "%lld %lld\n", M, N);
            ll lim = (M - 1) * N;
            for(int cnt = 1; cnt <= 10; ++cnt){
                ll A = rndd(0, max(0ll, lim - 10)), B = rndd(min(lim, A + 100), lim);
                if(rnddd(5))A = 0;
                if(rnddd(3))B = A;
                fprintf(input, "%lld %lld\n", A, B);
            }
        }
        fcloseall();
        char outS[10000]; sprintf(outS, "%s%d.out", filename.c_str(), id);
        string inStr(inS), outStr(outS);
        char opt[10000]; sprintf(opt, "./std < %s > %s", inStr.c_str(), outStr.c_str());
        system(opt);
    }
}

int main(){
    // Build(1, 1, 0, 0, true);
    // Build(2, 4, (ll)1.6e3, 20);
    // Build(5, 10, (ll)8e3, 20);
    // Build(11, 12, (ll)2e5, 2, false, 1000, 0);
    // Build(13, 20, (ll)2e5, 20, false, 1000, 5);
    Build(0, 0, (ll)2e5, 20, false, 1000, 5);
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