#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)
#define RV(i) (vdata.at(i - 1))

template < typename T = int >
inline T read(void);

ll dp[600];
ll C[600];
int N, M;
int L[510], R[510];
int idL[510], idR[510];
basic_string < int > vdata;
// ll dp[2][1100][510];
ll inv[1100];
ll sum[1100];

// ll fact[1100], inv[1100];

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul % MOD;
            b >>= 1;
            mul = mul * mul % MOD;
        }return ret;
    };
    // auto Init = [qpow](void)->void{
    //     fact[0] = 1;
    //     for(int i = 1; i <= 1010; ++i)fact[i] = fact[i - 1] * i % MOD;
    //     inv[1010] = qpow(fact[1010], MOD - 2);
    //     for(int i = 1009; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
    // }; Init();
    // auto C = [](ll n, ll m)->ll{
    //     if(n < m)return 0;
    //     return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
    // };
    // vdata += {0, 0x3f3f3f3f};
    N = read();
    for(int i = 1; i <= N; ++i){
        L[i] = read(), R[i] = read() + 1;
        vdata += {L[i], R[i]};
    }sort(vdata.begin(), vdata.end());
    vdata.erase(unique(vdata.begin(), vdata.end()), vdata.end());
    M = vdata.size();
    for(int i = 1; i <= N; ++i)
        idL[i] = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), L[i]))),
        idR[i] = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), R[i])));
    for(int i = 1; i <= 1010; ++i)inv[i] = qpow(i, MOD - 2);
    dp[0] = C[0] = 1;
    // vdata += 0x3f3f3f3f;
    // vdata.insert(vdata.begin(), 0);
    for(int j = 1; j < M; ++j){
        ll len = RV(j + 1) - RV(j);
        for(int i = 1; i <= N; ++i)C[i] = C[i - 1] * (len + i - 1) % MOD * inv[i] % MOD;
        for(int i = N; i >= 1; --i)if(idL[i] <= j && j + 1 <= idR[i]){
            int cur(1);
            // for(int k = 0; k <= i - 1; ++k)(dp[i] += dp[k] * C[cur] % MOD) %= MOD, cur += idL[k] <= j && j + 1 <= idR[k];
            for(int k = i - 1; k >= 0; --k)(dp[i] += dp[k] * C[cur] % MOD) %= MOD, cur += idL[k] <= j && j + 1 <= idR[k];
        }
        // for(int i = 1; i <= N; ++i)printf("j = %d, dp[%d] = %lld\n", j, i, dp[i]);
    }ll ans(0);
    for(int i = 1; i <= N; ++i)(ans += dp[i]) %= MOD;
    printf("%lld\n", ans);
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