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

int B, K;
int Sx, Sy, Tx, Ty;

signed main(){
    int T = read();
    while(T--){
        B = read(), K = read();
        Sx = read(), Sy = read(), Tx = read(), Ty = read();
        pair < ll, ll > S[10] = {
            {0, 0},
            {Sx / B * B, Sy},
            {Sx, ll(ceil((double)Sy / B)) * B},
            {ll(ceil((double)Sx / B)) * B, Sy},
            {Sx, Sy / B * B}
        };
        pair < ll, ll > T[10] = {
            {0, 0},
            {Tx / B * B, Ty},
            {Tx, ll(ceil((double)Ty / B)) * B},
            {ll(ceil((double)Tx / B)) * B, Ty},
            {Tx, Ty / B * B}
        };
        // pair < ll, ll > S[10] = {
        //     {0, 0},
        //     {Sx / B * B, Sy},
        //     {Sx, Sy / B * B + B},
        //     {Sx / B * B + B, Sy},
        //     {Sx, Sy / B}
        // };
        // pair < ll, ll > T[10] = {
        //     {0, 0},
        //     {Tx / B * B, Ty},
        //     {Tx, Ty / B * B + B},
        //     {Tx / B * B + B, Ty},
        //     {Tx, Ty / B}
        // };
        // pair < ll, ll > S[10] = {
        //     {0, 0},
        //     {Sx / B * B, Sy},
        //     {Sx, (Sy + B - 1) / B * B},
        //     {(Sx + B - 1) / B * B, Sy},
        //     {Sx, Sy / B}
        // };
        // pair < ll, ll > T[10] = {
        //     {0, 0},
        //     {Tx / B * B, Ty},
        //     {Tx, (Ty + B - 1) / B * B},
        //     {(Tx + B - 1) / B * B, Ty},
        //     {Tx, Ty / B}
        // };
        // for(int i = 1; i <= 4; ++i){
        //     if(!S[i].first)S[i].first = B;
        //     if(!S[i].second)S[i].second = B;
        //     if(!T[i].first)T[i].first = B;
        //     if(!T[i].second)T[i].second = B;
        // }
        #define SSx S[s].first
        #define SSy S[s].second
        #define TTx T[t].first
        #define TTy T[t].second
        // for(int i = 1; i <= 4; ++i)printf("S[%d] = %lld, %lld\n", i, S[i].first, S[i].second);
        // for(int i = 1; i <= 4; ++i)printf("T[%d] = %lld, %lld\n", i, T[i].first, T[i].second);
        ll ans = ll(abs(Sx - Tx) + abs(Sy - Ty)) * K;
        for(int s = 1; s <= 4; ++s)
            for(int t = 1; t <= 4; ++t){
                ll cur = (ll)(abs(SSx - Sx) + abs(SSy - Sy)) * K +
                        (ll)(abs(TTx - Tx) + abs(TTy - Ty)) * K;
                
                if(SSx % B == 0 && TTx % B == 0 && SSy / B == TTy / B){
                    if(SSx == TTx)cur += abs(SSy - TTy);
                    else cur += abs(SSx - TTx) + min(SSy % B + TTy % B, B - SSy % B + B - TTy % B);
                }else if(SSy % B == 0 && TTy % B == 0 && SSx / B == TTx / B){
                    if(SSy == TTy)cur += abs(SSx - TTx);
                    else cur += abs(SSy - TTy) + min(SSx % B + TTx % B, B - SSx % B + B - TTx % B);
                }else
                    cur += abs(SSx - TTx) + abs(SSy - TTy);
                ans = min(ans, cur);
            }
                // printf("%lld + %lld + %lld + %lld = %lld\n", abs(SSx - TTx),
                // abs(SSy - TTy),
                // (ll)(abs(SSx - Sx) + abs(SSy - Sy)) * K,
                // (ll)(abs(TTx - Tx) + abs(TTy - Ty)) * K,
                // abs(SSx - TTx) + abs(SSy - TTy) +
                //     (
                //         (ll)(abs(SSx - Sx) + abs(SSy - Sy)) * K +
                //         (ll)(abs(TTx - Tx) + abs(TTy - Ty)) * K
                //     ));
        printf("%lld\n", ans);
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