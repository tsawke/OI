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

#define int __int128

int scat[1100000];
int ccat[1100000];


template<typename T = int>
inline T read(void);

ll kpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }
    return ret;
}

int inv[1100000];
signed main(){
    freopen("scat.txt", "w", stdout);
    scat[0] = 1;scat[1] = 1;scat[2] = 2;
    // printf("%d\n\n", kpow(2, 10));
    for(int i = 1; i <= 1000100; ++i)inv[i] = kpow(i, MOD - 2);
    // for(int i = 1; i <= 1000100; ++i)printf("%d\n", inv[i]);
    printf("int scat[1000100] = {1, 1, 2, ");
    for(int i = 3; i <= 1000100; ++i){
        for(int j = 0; j <= i - 1; ++j){
            scat[i] = (scat[i] + scat[j] * scat[i - j - 1] % MOD) % MOD;

        }
        printf("%d%c", (signed)(scat[i] % MOD), i == 1000100 ? '}' : ',');
        if(i % 100 == 0)printf("\n");
        fflush(stdout);
    }

    

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