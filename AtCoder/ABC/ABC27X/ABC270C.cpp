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

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];
int fa[210000], dep[210000];
int N;

void dfs(int p = 1, int ffa = 0){
    fa[p] = ffa, dep[p] = dep[ffa] + 1;
    for(auto i = head[p]; i; i = i->nxt)if(SON != ffa)dfs(SON, p);
}

int main(){
    N = read();
    int S = read(), T = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs();
    basic_string < int > p1, p2;
    p1 += S, p2 += T;
    while(S != T)
        if(dep[S] < dep[T])T = fa[T], p2 += T;
        else S = fa[S], p1 += S;
    p1.pop_back();
    reverse(p2.begin(), p2.end());
    for(auto v : p1 + p2)printf("%d ", v);
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