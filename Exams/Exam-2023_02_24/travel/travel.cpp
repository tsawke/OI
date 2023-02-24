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

int N, M;
int C[310], W[310];
bitset < 310 > vis;
bitset < 10 > col;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100000];
ROPNEW;
Edge* head[310];

ll ret(LONG_LONG_MAX);

void dfs(int p, ll cur, int endp){
    // printf("In dfs p = %d, cur = %lld, endp = %d\n", p, cur, endp);
    if(p == endp)return ret = min(ret, cur), void();
    for(auto i = head[p]; i; i = i->nxt)
        if(col[SON] && C[p] != C[SON])cur -= W[SON], col[SON] = false;
    for(auto i = head[p]; i; i = i->nxt){
        if(vis[SON])continue;
        vis[SON] = col[SON] = true;
        dfs(SON, cur + W[SON], endp);
        vis[SON] = col[SON] = false;
    }
}

ll Cal(int s, int t){
    // printf("cal s = %d, t = %d\n", s, t);
    ret = LONG_LONG_MAX;
    col.reset();
    vis[s] = col[s] = true;
    dfs(s, W[s], t);
    vis[s] = col[s] = false;
    return ret;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int T = read();
    while(T--){
        memset(head, 0, sizeof head);
        N = read(), M = read();
        for(int i = 1; i <= N; ++i)C[i] = read();
        for(int i = 1; i <= N; ++i)W[i] = read();
        for(int i = 1; i <= M; ++i){
            int s = read(), t = read();
            head[s] = new Edge{head[s], t};
            head[t] = new Edge{head[t], s};
        }
        if(N <= 10){
            for(int i = 1; i <= N; ++i){
                for(int j = 1; j <= N; ++j){
                    printf("%lld%c", Cal(i, j), j == N ? '\n' : '\n');
                }
            }
        }
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
/*
1
4 4
1 1 2 3
1 2 4 5
1 2
2 3
3 4
1 4
*/

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