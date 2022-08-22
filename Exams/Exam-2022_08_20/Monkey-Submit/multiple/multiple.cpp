#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define MOD 998244353

#define abbr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

template<typename T = int>
inline T read(void);

int arr[1100000];
int N, M, Q;

int anss[1100000];
signed main(){
    freopen("multiple.in", "r", stdin);
    freopen("multiple.out", "w", stdout);
    N = read(), M = read(), Q = read();
    for(int i = 1; i <= M; ++i){
        int p = read(), x = read();
        for(int j = 1; j <= N / p; ++j)arr[p * j] += x * j, arr[p * j] %= MOD;
    }
    for(int i = 1; i <= Q; ++i){
        int k = read();
        if(anss[k]){printf("%lld\n", anss[k]); continue;}
        int ans(0);
        for(int j = 1; j <= N / k; ++j)ans = (ans + j * arr[k * j] % MOD) % MOD;
        printf("%lld\n", ans);
        anss[k] = ans;
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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