#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define log10_(x) (int(logl((ld)x) / logl((ld)10.0)) + 1)

template < typename T = int >
inline T read(void);

int N, MOD;
ll ans(0);
ll dp[3100][3100];
ll sum[3100][3100];
int pow10[5] = {1, 10, 100, 1000, 10000};

int main(){
    N = read(), MOD = read();
    for(int i = 1; i <= N; ++i){
        dp[i][(int)log10(i) + 2] = 26;
        for(int j = 1; j <= N; ++j){
            for(int len = 0; len <= 3; ++len)
                if(i >= pow10[len] && j - 2 - len > 0)
                    (dp[i][j] += ((sum[i - pow10[len]][j - 2 - len] - sum[max(i - pow10[len + 1], 0)][j - 2 - len] + MOD) % MOD * 25ll % MOD)) %= MOD;
            sum[i][j] = (sum[i - 1][j] + dp[i][j]) % MOD;
        }
    }
    for(int i = 1; i < N; ++i)(ans += dp[N][i]) %= MOD;
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