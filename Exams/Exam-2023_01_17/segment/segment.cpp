#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

struct Range{int l, r;};
Range R[11];
int N, Q;

int main(){
    freopen("segment.in", "r", stdin);
    freopen("segment.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)R[i].l = read(), R[i].r = read();
    sort(R + 1, R + N + 1, [](const Range &a, const Range &b)->bool{return a.l < b.l;});
    int Smx = (1 << N) - 1;
    while(Q--){
        int l = read(), r = read();
        ll F(0), G(0);
        for(int S = Smx; S; S = (S - 1) & Smx){
            int curl(-1), curr(-1);
            bool flag(true);
            for(int i = 0; i < N; ++i){
                if(S & (1 << i)){
                    if(!~curl)curl = R[i + 1].l;
                    if(!~curr)curr = R[i + 1].r;
                    else{
                        if(R[i + 1].l > curr)flag = false;
                        else curr = R[i + 1].r;
                    }
                }
            }
            if(flag && curl == l && curr == r){
                if(__builtin_popcount(S) & 1)++G;
                else ++F;
            }
        }
        printf("%lld\n", ((F - G) % MOD + MOD) % MOD);
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