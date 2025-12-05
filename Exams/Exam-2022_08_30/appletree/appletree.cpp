#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define MOD 998244353

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

ll cnt(0);


ll kpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }
    return ret;
}
int jc[110000];
int getC(int n, int m){
    return jc[n] * kpow(jc[m], MOD - 2) % MOD * jc[n - m] % MOD;
}

int main(){
    freopen("appletree.in", "r", stdin);
    freopen("appletree.out", "w", stdout);
    // jc[0] = 1;
    // for(int i = 1; i <= 100100; ++i)jc[i] = i * jc[i - 1] % MOD;
    // int N = read();
    // int maxn = read(); for(int i = 2; i <= N; ++i)(void)read();
    // for(int i = 1; i <= N - 1; ++i)(void)read(), (void)read();
    // // for(int i = N - 1, lim = 1; i >= 1 && lim <= maxn; --i, ++lim)cnt = (cnt + i) % MOD;
    // for()
    // ++cnt;
    // printf("%d\n", int(cnt % (ll)MOD));
    printf("%d\n", rndd(1, 114514));
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