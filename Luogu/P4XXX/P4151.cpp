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

#define LIM (62)

template < typename T = int >
inline T read(void);

int N, M;
struct Edge{
    Edge* nxt;
    int to;
    ll val;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[51000];

ll LB[70];
ll sxor[51000];
bitset < 51000 > vis;

void InsertLB(ll x){
    for(int i = LIM; i >= 0; --i)
        if(x & (1ll << i)){
            if(LB[i])x ^= LB[i];
            else{LB[i] = x; break;}
        }
}
ll QueryMax(ll base){
    for(int i = LIM; i >= 0; --i)
        if((base ^ LB[i]) > base)base ^= LB[i];
    return base;
}
void dfs(int p = 1, ll cur = 0){
    sxor[p] = cur, vis[p] = true;
    for(auto i = head[p]; i; i = i->nxt)
        if(!vis[SON])dfs(SON, cur ^ i->val);
        else InsertLB(cur ^ i->val ^ sxor[SON]);
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(); ll v = read < ll >();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }
    dfs();
    printf("%lld\n", QueryMax(sxor[N]));
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