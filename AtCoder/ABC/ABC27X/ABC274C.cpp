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

int N;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[810000];
ROPNEW;
Edge* head[410000];

int dep[410000];

void dfs(int p = 1, int fa = 0){
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(SON, p);
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int val = read();
        head[val] = new Edge{head[val], 2 * i};
        head[2 * i] = new Edge{head[2 * i], val};
        head[val] = new Edge{head[val], 2 * i + 1};
        head[2 * i + 1] = new Edge{head[2 * i + 1], val};
    }dep[0] = -1, dfs();
    for(int i = 1; i <= N * 2 + 1; ++i)printf("%d\n", dep[i]);

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