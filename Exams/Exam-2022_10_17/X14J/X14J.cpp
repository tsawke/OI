#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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
typedef long double ld;

// #define P 1145141
#define MOD 998244353

template<typename T = int>
inline T read(void);

int N, M;
// int a[5100000];
// unll hash(void){
//     int p(0);
//     unll ret(0);
//     for(int i = 1; i <= N; ++i)
//         ret *= P, ret += a[i];
//     return ret;
// }
// set < unll > exist;
ll dp[1100000][22];
int main(){
    freopen("X14J.in", "r", stdin);
    freopen("X14J.out", "w", stdout);
    N = read(), M = read();
    for(int j = 0; j <= M * 2 + 1; ++j)dp[1][j] = 1;
    for(int i = 2; i <= N; ++i){
        for(int j = 0; j <= M * 2 + 1; ++j){
            for(int k = 0; k <= j; ++k){
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    // for(int i = 1; i <= N; ++i){
    //     for(int j = 0; j <= M * 2 + 1; ++j){
    //         printf("%lld%c", dp[i][j], ' ');
    //     }printf("\n");
    // }
    // ll ans(0);
    // for(int j = 0; j <= M; ++j)ans = (ans + dp[N][j]) % MOD;
    printf("%lld\n", dp[N][M * 2 + 1]);
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