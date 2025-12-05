#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (1000000007)


template<typename T = int>
T read(void);

unll kpow(unll, unll);

int N, p;
int a[110000];
unll ans(0ull);
void dfs(int, unll, unll);
unll GetC(unll, unll);
int main(){
    freopen("./3.in", "r", stdin);
    // freopen("polynomial.out", "w", stdout);
    N = read(), p = read(); //TODO p <= 10^10^6
    for(int i = 0; i <= N; ++i)a[i] = read();
    // a[N] = 0;
    if(N == 0){
        unll anss = kpow(a[0], p);
        printf("%llu\n", anss);
        return 0;
    }
    if(N == 1){
        for(int i = 0; i <= p; i += 2){
            ans = (ans + GetC(p, p - i) * kpow(a[0], p - i) * kpow(a[1], i) % MOD) % MOD;
            // printf("ans=%lld,  GetC(p, p - i) %lld  kpow(a[0], p - i) %lld  kpow(a[1], i) %lld\n", ans, GetC(p, p - i), kpow(a[0], p - i), kpow(a[1], i));
            // printf("p=%d, i=%d\n", p, i);
        }
        printf("%llu\n", ans);
        return 0;
    }
    //TODO N == 1
    dfs(0, 0, 1);
    printf("%llu\n", ans);
    return 0;
}
unll GetC(unll n, unll m){
    if(!m || n == m)return 1ull;
    return GetC(n - 1, m) + GetC(n - 1, m - 1);
}
void dfs(int deep, unll k, unll cur){
    // printf("search");
    if(deep >= p){
        if(!(k & 1))
            ans = (ans + cur) % MOD;
        return;
    }
    for(int i = 0; i <= N; ++i){
        dfs(deep + 1, (k + i) % MOD, (cur * a[i]) % MOD);
    }
}
unll kpow(unll a, unll b){
    unll ret(1);
    unll MUL(a);
    while(b){
        if(b & 1ull)ret = (ret * MUL) % MOD;
        MUL = (MUL * MUL) % MOD;
        b >>= 1;
    }
    return ret;
}

template<typename T>
T read(void){
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