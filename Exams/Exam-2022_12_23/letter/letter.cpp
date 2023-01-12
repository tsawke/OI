#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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
    Edge* rev;
    int to;
    ll flow;
    ll c;
    OPNEW;
}ed[30000];
ROPNEW(ed);
Edge* head[2100];

const int S = 2001, RS = 2002, T = 2003, RT = 2004;
int N, K;
ll a[2100], b[2100];
Edge* edg[2100];
ll dis[2100];
ll cflow[2100];
bitset < 2100 > inq;
ll ans(0);

bool SPFA(void){
    memset(dis, 0x3f, sizeof dis);
    memset(edg, false, sizeof edg);
    queue < int > cur;
    dis[RS] = 0, cflow[RS] = 0x3f3f3f3f, inq[RS] = true;
    cur.push(RS);
    while(!cur.empty()){
        // printf("searching %d\n", cur.front());
        int p = cur.front(); cur.pop(); inq[p] = false;
        for(auto i = head[p]; i; i = i->nxt){
            if(i->flow <= 0 || dis[SON] <= dis[p] + i->c)continue;
            dis[SON] = dis[p] + i->c, cflow[SON] = min(cflow[p], i->flow), edg[SON] = i;
            if(!inq[SON])cur.push(SON), inq[SON] = true;
        }
    }return edg[RT];
}
void MCMF(void){
    while(SPFA()){
        ans += dis[RT] * cflow[RT];
        for(int p = RT; p != RS; p = edg[p]->rev->to)
            edg[p]->flow -= cflow[RT], edg[p]->rev->flow += cflow[RT];
    }
}
void add(int s, int t, int flow, int c){
    head[s] = new Edge{head[s], npt, t, flow, c};
    head[t] = new Edge{head[t], npt, s, 0, -c};
    head[s]->rev = head[t], head[t]->rev = head[s];
}

int main(){
    freopen("letter.in", "r", stdin);
    freopen("letter.out", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i)b[i] = read();
    add(RS, S, K, 0), add(T, RT, K, 0);
    for(int i = 1; i <= N; ++i){
        add(S, i, 1, a[i]), add(i, T, 1, b[i]);
        if(i <= N - 1)add(i, i + 1, 0x3f3f3f3f >> 1, 0);
    }while(SPFA())MCMF();
    printf("%lld\n", ans);
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