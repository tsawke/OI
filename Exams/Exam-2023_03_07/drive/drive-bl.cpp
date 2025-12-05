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

#define MOD (10000000)

template < typename T = int >
inline T read(void);

int N, M;
struct Edge{
    Edge* nxt;
    int to;
    int idx;
    OPNEW;
}ed[610000];
ROPNEW;
Edge* head[310000];
ll ans[310000];

ll cnt[310000];
ll rcnt[310000];

int main(){
    freopen("drive.in", "r", stdin);
    freopen("drive.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t, i};
        head[t] = new Edge{head[t], s, i};
    }
    cnt[1] = 1;
    for(int s = 1; s < N; ++s)
        for(auto i = head[s]; i; i = i->nxt)
            if(SON > s)(cnt[SON] += cnt[s]) %= MOD;
    printf("%lld\n", cnt[N]);
    for(int id = 1; id <= N; ++id){
        for(int i = 1; i <= N; ++i)cnt[i] = 0;
        cnt[1] = 1;
        for(int s = 1; s < N; ++s)
            for(auto i = head[s]; i; i = i->nxt)
                if(SON > s && i->idx != id)(cnt[SON] += cnt[s]) %= MOD;
        ans[id] = cnt[N];
    }
    for(int i = 1; i <= M; ++i)printf("%lld%c", ans[i], i == M ? '\n' : ' ');
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
4 5
2 1
3 4
1 4
3 2
2 4
*/