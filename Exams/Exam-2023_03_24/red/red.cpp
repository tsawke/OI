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
#define RV(i) (i == 0 ? 1 : vdata.at(i - 1))

template < typename T = int >
inline T read(void);

int N, M;
int L[510], R[510];
int idL[510], idR[510];
basic_string < int > vdata;
ll dp[2][1100][510];
ll inv[1100];
ll sum[1100];

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul % MOD;
            b >>= 1;
            mul = mul * mul % MOD;
        }return ret;
    };
    N = read();
    for(int i = 1; i <= N; ++i){
        L[i] = read(), R[i] = read();
        vdata += {L[i], R[i]};
    }sort(vdata.begin(), vdata.end());
    vdata.erase(unique(vdata.begin(), vdata.end()), vdata.end());
    M = vdata.size();
    for(int i = 1; i <= N; ++i)
        idL[i] = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), L[i]))),
        idR[i] = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), R[i])));
    for(int i = 1; i <= 1010; ++i)inv[i] = qpow(i, MOD - 2);
    dp[0][0][0] = dp[0][1][0]  = dp[0][2][0] =  1;// sum[0] = 1;
    for(int i = 1; i <= N; ++i){
        memset(dp[i & 1], 0, sizeof dp[i & 1]);
        for(int j = 1; j <= M; ++j){
            for(int k = 0; k <= i; ++k){
                dp[i & 1][j][k] += dp[(!i & 1)][j][k];
            }
            // (dp[i & 1][j][1] += sum[j - 1]) %= MOD;
            // sum[j] = 0;
        }
        for(int j = 1; j < idR[i]; ++j){
            for(int k = 0; k <= i; ++k){
                (dp[i & 1][idR[i]][1] += dp[!(i & 1)][j][k]) %= MOD;
                
            }
        }
        for(int k = 1; k <= i; ++k)
            (dp[i & 1][idR[i]][k] += dp[!(i & 1)][idR[i]][k - 1] * (RV(idR[i]) - RV(idL[i]) + 1 - k + 1) % MOD * inv[k] % MOD) %= MOD,
            printf("len = %d, val = %lld, idx is %d, %d, %d\n", RV(idR[i]) - RV(idL[i]) + 1, (RV(idR[i]) - RV(idL[i]) + 1 - k + 1) % MOD * inv[k], !(i & 1), idR[i], k - 1);
        
for(int j = 1; j <= M; ++j)
            for(int k = 0; k <= i; ++k)
                printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i & 1][j][k]);
        // for(int j = 1; j <= idR[i]; ++i){
        //     for(int k = 1; k <= i; ++k){
        //         (dp[i & 1][idR[i]][1] += dp[!(i & 1)][j][k]) %= MOD;
                
        //     }
        // }
        // (dp[i & 1][idR[i]][k] += dp[!(i & 1)][idR[i]][k - 1] * (RV(j) - RV(j - 1) + 1 - k + 1) % MOD * inv[k] % MOD) %= MOD;
        //         (sum[j] += dp[i & 1][j][k]) %= MOD;
        //         printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i & 1][j][k]);
            
            
    }ll ans(0);
    for(int j = 1; j <= M; ++j)for(int k = 1; k <= N; ++k)(ans += dp[N & 1][j][k]) %= MOD;
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