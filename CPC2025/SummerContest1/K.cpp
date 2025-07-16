#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (1000000007ll)

template<typename T = int>
inline T read(void);

ll fact[1100000];
int K[5100];
ll S[5100];
ll revolt(0);

ll G[5100], sumG[5100];

int main(){
    fact[0] = 1;
    for(int i = 1; i <= 1010000; ++i)fact[i] = (fact[i - 1] * i) % MOD;
    int N = read(), H = read();
    for(int i = 1; i <= H; ++i)K[i] = read(), S[i] = S[i - 1] + K[i];
    for(int r = 1; r <= H; ++r){
        ll add(0);
        for(int i = 1; i <= r - 1; ++i)add += G[i] * fact[S[r] - S[i]] % MOD, add %= MOD;
        G[r] = (fact[S[r]] - add + MOD) % MOD;
    }
    // for(int i = 1; i <= H; ++i){
    //     S[i] = (S[i - 1] + K[i]);
    //     if(i == 1)
    //         revolt = (revolt + fact[K[1]] * fact[N - K[1]] % MOD) % MOD;
    //     else
    //         revolt = (revolt + ((fact[S[i]] - fact[S[i - 1]] * fact[K[i]] % MOD + MOD) % MOD) * fact[N - S[i]] % MOD) % MOD;
    // }
    if(S[H] == N){printf("0\n"); return 0;}
    // printf("%lld\n", ((fact[N] - revolt) % MOD + MOD) % MOD);
    ll add(0);
    for(int i = 1; i <= H; ++i){
        add += G[i] * fact[N - S[i]] % MOD;
        add %= MOD;
    }
    printf("%lld\n", (fact[N] - add + MOD) % MOD);

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