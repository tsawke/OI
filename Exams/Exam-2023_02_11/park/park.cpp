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



template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[26000];
ROPNEW;
Edge* head[110];

int N, M, K;
int c[110], h1[110], h2[110];
int deg[110][500];
ld expA(0.0), expB(0.0);
ld dp[110][500];
ld rdp[110][500];

int main(){
    freopen("park.in", "r", stdin);
    freopen("park.out", "w", stdout);
    N = read(), M = read(), K = read();
    for(int i = 1; i <= N; ++i)c[i] = read(), h1[i] = read(), h2[i] = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }
    for(int p = 1; p <= N; ++p)
        for(int j = 0; j <= K; ++j)
            for(auto i = head[p]; i; i = i->nxt)
                    if(j + i->val + c[SON] <= K)++deg[p][j];
    for(int p = 1; p <= N; ++p){
        dp[p][c[p]] = 1.0 / (ld)N;
        for(int cost = 0; cost <= K; ++cost)
            for(auto i = head[p]; i; i = i->nxt)
                if(deg[p][cost] && deg[SON][cost + i->val + c[SON]] && cost + i->val * 2 + c[SON] + c[p] <= K)
                    dp[p][cost + i->val * 2 + c[SON] + c[p]] += dp[p][cost] * (1.0 / (ld)deg[p][cost]) * (1.0 / (ld)deg[SON][cost + i->val + c[SON]]);
    }
    memcpy(rdp, dp, sizeof dp);
    for(int p = 1; p <= N; ++p)
        for(int j = 0; j <= K; ++j)
            for(auto i = head[p]; i; i = i->nxt)
                if(deg[p][j] && j + i->val + c[SON] <= K)
                    rdp[SON][j + i->val + c[SON]] += dp[p][j] * (1.0 / (ld)deg[p][j]);
    for(int i = 1; i <= N; ++i)
        for(int j = 0; j <= K; ++j)
            // printf("dp[%d][%d] = %.5Lf, rdp[%d][%d] = %.5Lf\n", i, j, dp[i][j], i, j, rdp[i][j]),
            expA += (ld)h1[i] * rdp[i][j], expB += (ld)h2[i] * rdp[i][j];
    printf("%.5Lf %.5Lf\n", expA, expB);
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
/*
5 4 60
25 12 83
30 38 90
16 13 70
22 15 63
50 72 18
2 1 7
3 1 7
4 3 1
5 3 10
*/