#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int N, M;
ll A, B, C, D, E, F;
set < pair < ll, ll > > blk;
ll dp[310][310][310];
ll ans(0);
bool isBlocked(pair < ll, ll > pos){return blk.find({pos.first, pos.second}) != blk.end();}
pair < ll, ll > GetPos(int i, int j, int k){return {A * i + C * j + E * k, B * i + D * j + F * k};}

int main(){
    N = read(), M = read();
    A = read(), B = read(), C = read(), D = read(), E = read(), F = read();
    while(M--){int x = read(), y = read(); blk.insert({x, y});}
    dp[0][0][0] = 1;
    for(int i = 0; i <= N; ++i)
        for(int j = 0; j <= N; ++j)
            for(int k = 0; k <= N; ++k){
                if(i + j + k > N || isBlocked(GetPos(i, j, k)))continue;
                (dp[i][j][k] += ((i ? dp[i - 1][j][k] : 0) + (j ? dp[i][j - 1][k] : 0) + (k ? dp[i][j][k - 1] : 0)) % MOD) %= MOD;
                if(i + j + k == N)(ans += dp[i][j][k]) %= MOD;
            }
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