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

int N, M;
ll X[5100];
unordered_map < ll, ll > mp;
ll dp[5100][5100];
ll ans(0);
ll Y(int idx){
    if(mp.find(idx) == mp.end())return 0;
    return mp[idx];
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)X[i] = read();
    for(int i = 1; i <= M; ++i){
        int C = read(), Y = read();
        mp.insert({C, Y});
    }
    for(int i = 1; i <= N; ++i){
        for(int k = 0; k <= i - 1; ++k)dp[i][0] = max(dp[i][0], dp[i - 1][k]);
        for(int j = 1; j <= i; ++j)dp[i][j] = dp[i - 1][j - 1] + X[i] + Y(j);
    }
    for(int i = 0; i <= N; ++i)ans = max(ans, dp[N][i]);
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