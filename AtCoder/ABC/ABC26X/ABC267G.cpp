#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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
int A[5100];
int w[5100];
ll dp[5100][5100];

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    sort(A + 1, A + N + 1);
    for(int i = 2; i <= N; ++i)if(A[i] == A[i - 1])w[i] = w[i - 1] + 1;
    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i){
        dp[i][0] = dp[i - 1][0] * (w[i] + 1) % MOD;
        for(int j = 1; j <= i; ++j)
            dp[i][j] = (dp[i - 1][j] * (j + w[i] + 1) % MOD + dp[i - 1][j - 1] * (i - j - w[i]) % MOD) % MOD;
    }
    printf("%lld\n", dp[N][K]);
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