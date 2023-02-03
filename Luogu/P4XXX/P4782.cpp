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
    OPNEW;
}ed[4100000];
ROPNEW;
Edge* head[2100000];

int N, M;
int SCC(0);
int dfn[2100000], low[2100000];
bitset < 2100000 > inS;
int belong[2100000];

void Tarjan(int p){
    static int cdfn(0);
    static stack < int > cur; cur.push(p); inS[p] = true;
    dfn[p] = low[p] = ++cdfn;
    for(auto i = head[p]; i; i = i->nxt){
        if(!dfn[SON])Tarjan(SON), low[p] = min(low[p], low[SON]);
        else if(inS[SON])low[p] = min(low[p], low[SON]);
    }
    if(dfn[p] == low[p]){++SCC;
        while(cur.top() != p)belong[cur.top()] = SCC, inS[cur.top()] = false, cur.pop();
        belong[cur.top()] = SCC, inS[cur.top()] = false, cur.pop();
    }
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int x, y; bool a, b;
        x = read(), a = read(), y = read(), b = read();
        if(x == y && a ^ b)continue;
        head[((y << 1) + b) ^ 1] = new Edge{head[((y << 1) + b) ^ 1], (x << 1) + a};
        head[((x << 1) + a) ^ 1] = new Edge{head[((x << 1) + a) ^ 1], (y << 1) + b};
    }
    // for(int i = 2; i <= ((N << 1) | 1); ++i){
    //     printf("SON %d : ", i);
    //     for(auto j = head[i]; j; j = j->nxt)printf("%d ", j->to);
    //     printf("\n");
    // }
    for(int i = 2; i <= ((N << 1) | 1); ++i)if(!dfn[i])Tarjan(i);
    // for(int i = 2; i <= ((N << 1) | 1); ++i)printf("low[%d] = %d\n", i, low[i]);
    // for(int i = 2; i <= ((N << 1) | 1); ++i)printf("belong[%d] = %d\n", i, belong[i]);
    for(int i = 1; i <= N; ++i)if(belong[i << 1] == belong[(i << 1) | 1])printf("IMPOSSIBLE\n"), exit(0);
    printf("POSSIBLE\n");
    for(int i = 1; i <= N; ++i)printf("%d ", belong[i << 1] > belong[(i << 1) | 1]);
    printf("\n");
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