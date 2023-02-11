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

#define INFLL (0x3f3f3f3f3f3f3f3fll)

template < typename T = int >
inline T read(void);

int N, M, K;
struct{int s, t, v;}edg[210000];
ll dis[210000];

int main(){
    memset(dis, 0x3f, sizeof dis);
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i)edg[i].s = read(), edg[i].t = read(), edg[i].v = read();
    dis[1] = 0;
    for(int i = 1; i <= K; ++i){
        int idx = read();
        dis[edg[idx].t] = min(dis[edg[idx].t], dis[edg[idx].s] + edg[idx].v);
    }printf("%lld\n", dis[N] == INFLL ? -1ll : dis[N]);
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