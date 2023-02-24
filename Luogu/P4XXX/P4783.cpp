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

int N;
ll G[410][810];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

void Gauss(void){
    for(int i = 1; i <= N; ++i){
        int mxp(i);
        for(int j = i + 1; j <= N; ++j)
            if(G[j][i] > G[mxp][i])mxp = j;
        swap(G[i], G[mxp]);
        if(!G[i][i])printf("No Solution\n"), exit(0);
        ll inv = qpow(G[i][i], MOD - 2);
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            ll tmp = G[j][i] * inv % MOD;
            for(int k = i + 1; k <= N * 2; ++k)
                G[j][k] = (G[j][k] - G[i][k] * tmp % MOD + MOD) % MOD;
        }
    }
    for(int i = 1; i <= N; ++i)
        for(int j = N + 1; j <= N * 2; ++j)
            (G[i][j] *= qpow(G[i][i], MOD - 2)) %= MOD;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            G[i][j] = read();
    for(int i = 1; i <= N; ++i)
        G[i][N + i] = 1;
    Gauss();
    for(int i = 1; i <= N; ++i)
        for(int j = N + 1; j <= N * 2; ++j)
            printf("%lld%c", G[i][j], j == N * 2 ? '\n' : ' ');
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