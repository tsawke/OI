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

template < typename T = int >
inline T read(void);

int N;
int a[310000];
ll dp[310000][2];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    memset(dp, 0x3f, sizeof dp);
    dp[1][1] = a[1];
    for(int i = 2; i <= N; ++i)
        dp[i][0] = dp[i - 1][1],
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i];
    // for(int i = 1; i <= N; ++i)printf("%d: 0 = %lld, 1 = %lld\n", i, dp[i][0], dp[i][1]);
    ll ans = min(dp[N][1], dp[N][0]);
    dp[1][0] = 0;
    for(int i = 2; i <= N; ++i)
        dp[i][0] = dp[i - 1][1],
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a[i];
    ans = min(ans, dp[N][1]);
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