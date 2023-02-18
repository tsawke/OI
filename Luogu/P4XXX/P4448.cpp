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

#define LIM (110000)
#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

int N;
ll A[310];
ll s[310];
ll dp[2][310][310];
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;

int main(){
    for(int i = 2; i <= LIM; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if((ll)i * p > LIM)break;
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }
    N = read();
    for(int i = 1; i <= N; ++i){
        A[i] = read();
        for(auto p : Prime){
            if((ll)p * p > A[i])break;
            while(A[i] % (ll)(p * p) == 0)A[i] /= (ll)p * p;
        }
    }
    sort(A + 1, A + N + 1);
    int cnt(0);
    for(int i = 1; i < N; ++i)
        if(A[i] != A[i + 1])s[i] = 0, cnt = 0;
        else s[i] = ++cnt;
    dp[0][0][0] = 1; bool cur(0);
    for(int i = 0; i < N; ++i){
        memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
        if(A[i] != A[i + 1])
            for(int j = 0; j <= N; ++j)
                for(int k = 1; k <= N; ++k)
                    if(j + k <= N)(dp[cur][j + k][0] += dp[cur][j][k]) %= MOD, dp[cur][j][k] = 0;
        for(int j = 0; j <= N; ++j)
            for(int k = 0; k <= N; ++k){
                if(2 * s[i] - k > 0)(dp[cur ^ 1][j][k + 1] += dp[cur][j][k] * (2 * s[i] - k) % MOD) %= MOD;
                if(j - 1 >= 0)(dp[cur ^ 1][j - 1][k] += dp[cur][j][k] * j % MOD) %= MOD;
                if(i + 1 - (2 * s[i] - k) - j >= 0)(dp[cur ^ 1][j][k] += dp[cur][j][k] * (i + 1 - (2 * s[i] - k) - j) % MOD) %= MOD;
            }
        cur ^= 1;
    }printf("%lld\n", dp[cur][0][0]);
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