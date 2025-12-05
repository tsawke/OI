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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int N, K;
ll dp[11000000];
ll inv[11000000];

int main(){
    N = read(), K = read();
    if(K > N)printf("0\n"), exit(0);
    inv[1] = 1;
    for(int i = 2; i <= N + 100; ++i)inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    dp[0] = 1;
    dp[1] = K - 1;
    dp[2] = (ll)K * (K - 1) / 2 % MOD;
    for(int i = 0; i + 3 <= N - K + 1; ++i)
        dp[i + 3] = (
            dp[i] * 3 * i % MOD * (i + 1) % MOD +
            dp[i + 1] * ((5 * i + 3 * K + 6) % MOD) % MOD * (i + 1) % MOD +
            dp[i + 2] * (i + K + 1) % MOD * (i + K + 2) % MOD
        ) % MOD * inv[i + 3] % MOD * inv[i + K + 2] % MOD;
    printf("%lld\n", dp[N - K + 1]);
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