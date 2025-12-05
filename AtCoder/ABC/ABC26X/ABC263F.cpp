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

#define LS (p << 1)
#define RS (LS | 1)
#define MID ((gl + gr) >> 1)

template < typename T = int >
inline T read(void);

int N, powN;
ll dp[(1 << 16) << 2][20];
ll C[(1 << 16) + 10][20];

ll MakeDP(int p, int i){
    if(~dp[p][i])return dp[p][i];
    if(p >= N)return dp[p][i] = C[(p ^ N) + 1][i];
    return dp[p][i] = max(MakeDP(LS, i + 1) + MakeDP(RS, 0), MakeDP(LS, 0) + MakeDP(RS, i + 1));
}

int main(){
    memset(dp, -1, sizeof dp);
    N = 1 << (powN = read());
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= powN; ++j)C[i][j] = read();
    printf("%lld\n", MakeDP(1, 0));
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