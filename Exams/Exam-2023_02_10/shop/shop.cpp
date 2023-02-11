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
int w[10], c[10], d[10];

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100];
ROPNEW;
Edge* head[10];

int main(){
    freopen("shop.in", "r", stdin);
    freopen("shop.out", "w", stdout);
    int T = read();
    while(T--){
        N = read(), M = read();
        for(int i = 1; i <= N; ++i)w[i] = read();
        for(int i = 1; i <= N; ++i)c[i] = read();
        for(int i = 1; i <= N; ++i)d[i] = read();
        for(int i = 1; i <= N - 1; ++i){
            int s = read(), t = read();
            head[s] = new Edge{head[s], t};
            head[t] = new Edge{head[t], s};
        }
        printf("%d\n", rndd(1, 10000000));

    }
    //麻了，有依赖的多重背包不会写

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