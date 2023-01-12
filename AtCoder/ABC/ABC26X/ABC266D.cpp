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

template < typename T = int >
inline T read(void);

int N;
int prize[110000][10];
ll dp[110000][10];

int main(){
    memset(dp, 0xc0, sizeof dp); dp[0][0] = 0;
    N = read();
    for(int i = 1; i <= N; ++i){
        int T = read(), X = read(), A = read();
        prize[T][X] = A;
    }
    for(int i = 1; i <= 100000; ++i)
        for(int j = 0; j <= 4; ++j)
            dp[i][j] = max({j - 1 >= 0 ? dp[i - 1][j - 1] : (LONG_LONG_MIN >> 1), dp[i - 1][j + 1], dp[i - 1][j]}) + prize[i][j];
    ll ans(0);
    for(int j = 0; j <= 4; ++j)ans = max(ans, dp[100000][j]);
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