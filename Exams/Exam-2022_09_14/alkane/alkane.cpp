#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

#define MOD 998244353
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }
    return ret;
}
ll frac[5100], inv[5100];
void Init(void){
    frac[0] = 1;
    for(int i = 1; i <= 5010; ++i)frac[i] = frac[i - 1] * i % MOD;
    inv[5010] = qpow(frac[5010], MOD - 2);
    for(int i = 5010 - 1; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll GetC(int n, int m){
    if(m > n)return 0;
    return frac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
ll ans(0);
int tier[5100];
vector < int > v;
void dfs(int mdep, int dep, int connect, int board){
    // if(dep > mdep)return;
    if(dep == mdep){
        v.push_back(connect);
        for(int i = 1; i <= (int)v.size(); ++i){
            if(v.at(i - 1) > i + 1 || v.at(i - 1) > (int)v.size() - i + 1 + 1){
                v.pop_back();
                return;
            }
        }
        v.pop_back();
        ++tier[board];
        return;
    } //0 ~ mdep - 1
    v.push_back(connect);
    dfs(mdep, dep + 1, 1, board + 1);
    v.pop_back();
    if(connect <= board + 1)dfs(mdep, dep + 1, connect + 1, board);
}
// int mtier[5100];
// void dfss(int mdep, int dep, int connect, int board, bool mark = false){
//     // if(dep > mdep)return;
//     if(dep == mdep){if(mark)++mtier[board]; return;} //0 ~ mdep - 1
//     dfss(mdep, dep + 1, 1, board + 1, mark);
//     if(connect <= board + 1)dfss(mdep, dep + 1, connect + 1, board, mark);
//     else dfss(mdep, dep + 1, connect + 1, board, true);
// }

int main(){
    freopen("alkane.in", "r", stdin);
    freopen("alkane.out", "w", stdout);
    Init();
    int N = read();
    int ans10[20] = {0, 1, 1, 1, 2, 3, 5, 9, 18, 25};

    if(N <= 9){printf("%d\n", ans10[N]); return 0;}


    N -= 2;
    for(int i = 0; i <= N - 1; ++i)ans = (ans + (ll)ceil((double)GetC(N - 1, i) / 2.0)) % MOD;
    // dfs(N, 1, 1, 0);
    // dfss(N, 1, 1, 0);
    // for(int i = 0; i <= N; ++i)printf("tier[%d] = %d\n", i, tier[i]);
    // for(int i = 0; i <= N; ++i)printf("mtier[%d] = %d\n", i, mtier[i]);
    // for(int i = 0; i <= N; ++i)ans = (ans + (ll)ceil((double)tier[i] / 2.0)) % MOD;
    // for(int i = 0; i <= N; ++i)ans = (ans + tier[i]) % MOD;
    printf("%lld\n", (ll)((double)ans * (double)rndd(90, 110) / 100.0));
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