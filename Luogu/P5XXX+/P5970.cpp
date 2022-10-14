#define _USE_MATH_DEFINES
#include <bits/extc++.h>

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
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

#define MOD (int)(1e9 + 7)
int dp[11][2100000];
int tmp[2100000];
int N, D;
int xors(0);
int a[510000];

int main(){
    N = read(), D = read();
    for(int i = 1; i <= N; ++i)a[i] = read(), xors ^= a[i];
    sort(a + 1, a + N + 1);
    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i){
        int lim = 1 << (32 - __builtin_clz(a[i]));
        for(int k = 0; k <= lim; ++k)
            tmp[k] = (dp[0][k] + dp[D - 1][k ^ a[i]]) % MOD;
        for(int j = D - 1; j; --j)
            for(int k = 0; k <= lim; ++k)
                dp[j][k] = ll(dp[j][k] + dp[j - 1][k ^ a[i]]) % MOD;
        for(int k = 0; k <= lim; ++k)
            dp[0][k] = tmp[k];
    }
    if(N % D == 0)dp[0][xors] = (dp[0][xors] - 1 + MOD) % MOD;
    printf("%d\n", dp[0][xors]);

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