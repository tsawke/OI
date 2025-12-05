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

template < typename T = int >
inline T read(void);

int N, M;
ll A[110000];
ll sum[110000], rsum[110000], ssum, srsum;
ll pow2s[110000], pow2[110000];
ll spow2s[110000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= N; ++i)sum[i] = (sum[i - 1] + A[i]) % MOD;
    for(int i = N; i >= 1; --i)rsum[i] = (rsum[i + 1] + A[i]) % MOD;
    for(int i = 1; i <= N; ++i)(ssum += sum[i]) %= MOD, (srsum += rsum[i]) %= MOD;
    ll base(N);
    for(int i = 1; i <= M - 1; ++i){
        ssum = (ssum + ssum + sum[N] * base % MOD) % MOD;
        srsum = (srsum + srsum + sum[N] * base % MOD) % MOD;
        (sum[N] *= 2) %= MOD;
        (base <<= 1) %= MOD;
    }
    printf("%lld\n", max((ssum + ssum + sum[N] * base % MOD) % MOD, (ssum + srsum + sum[N] * base % MOD) % MOD));
    // pow2s[0] = sum[N] * N % MOD, pow2[0] = 1;
    // for(int i = 1; i <= M; ++i)pow2s[i] = pow2s[i - 1] * 4 % MOD, pow2[i] = pow2[i - 1] * 2 % MOD;
    // for(int i = 0; i <= M; ++i)spow2s[i] = ((i - 1 >= 0 ? spow2s[i - 1] : 0) + pow2s[i]) % MOD;
    // ll ans((ssum * pow2[M] % MOD + spow2s[M - 1]) % MOD);
    // ssum = (ssum * pow2[M - 1] % MOD + (M - 2 >= 0 ? spow2s[M - 2] : 0)) % MOD;
    // srsum = (srsum * pow2[M - 1] % MOD + (M - 2 >= 0 ? spow2s[M - 2] : 0)) % MOD;
    // ll tmp = ssum;
    // ssum = ((ssum + srsum) % MOD + pow2s[M - 1]) % MOD;
    // ans = max(ans, ssum);
    // //unreverse todo
    // ll origin_ssum = ssum, origin_srsum = srsum;
    // for(int rev = 1; rev <= M; ++rev){
    //     ssum = origin_ssum, srsum = origin_srsum;
    //     int d = rev - 1;
    //     ssum = (ssum * pow2[d] % MOD + (rev - 2 >= 0 ? spow2s[rev - 1] : 0)) % MOD;
    //     srsum = (srsum * pow2[d] % MOD + (rev - 2 >= 0 ? spow2s[rev - 1] : 0)) % MOD;
    //     ll tmp = ssum;
    //     (ssum += (srsum + pow2s[rev]) % MOD) %= MOD;
    //     (srsum += (tmp + pow2s[rev]) % MOD) %= MOD;
    //     d = M - rev;
    //     ssum = (ssum * pow2[d] % MOD + (spow2s[M] - spow2s[rev] + MOD) % MOD) % MOD;
    //     ans = max(ans, ssum);
    //     printf("rev = %d, ssum = %lld\n", rev, ssum);
    // }
    // printf("%lld\n", ans);
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