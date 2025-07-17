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

#define EPS (1e-6)
#define LIM (610000)

template < typename T = int >
inline T read(void);

struct Interval{
    bool flag;
    int idx;
    ll k, b;
    ll CalVal(ll x){
        // printf("calling k = %lld, b = %lld, x = %lld, v = %lld\n", k, b, x, k * x + b);
        return k * x + b;
    }
};

struct Node{
    Node* lson;
    Node* rson;
    int gl;
    int gr;
    Interval val;
    void* operator new(size_t);
}nd[3000000];
static Node* NP = nd;
void* Node::operator new(size_t){ return NP++;}

Node* root;

class LCSegTree{
private:
    
    // #define LS (p << 1)
    // #define RS (LS | 1)
    #define MID ((p->gl + p->gr) >> 1)
public:
    void Clear(int lim){
        // for(int i = 0; i <= lim; ++i)
            root = new Node{npt, npt, 1, 1000000000, Interval{true, 0, 0, 1000000000000000000}};
    }
    void Update(Interval line, Node* p = root){
        if(!p->val.flag)return p->val = line, void();
        if(line.CalVal(MID) == p->val.CalVal(MID)){
            if(line.idx < p->val.idx)swap(p->val, line);
        }else if(line.CalVal(MID) < p->val.CalVal(MID))swap(p->val, line);
        if(p->gl != p->gr && (line.CalVal(p->gl) == p->val.CalVal(p->gl) || line.CalVal(p->gl) < p->val.CalVal(p->gl))){
            if(!p->lson)p->lson = new Node{npt, npt, p->gl, MID, Interval{true, 0, 0, 1000000000000000000}};
            Update(line, p->lson);
        }
        else if(p->gl != p->gr && (line.CalVal(p->gr) == p->val.CalVal(p->gr) || line.CalVal(p->gr) < p->val.CalVal(p->gr))){
            if(!p->rson)p->rson = new Node{npt, npt, MID + 1, p->gr, Interval{true, 0, 0, 1000000000000000000}};
            Update(line, p->rson);
        }
    }
    void Insert(Interval line, int l, int r, Node* p = root){
        if(l <= p->gl && p->gr <= r)return Update(line, p);
        if(l <= MID){
            if(!p->lson)p->lson = new Node{npt, npt, p->gl, MID, Interval{true, 0, 0, 1000000000000000000}};
            Insert(line, l, r, p->lson);
        }
        if(r >= MID + 1){
            if(!p->rson)p->rson = new Node{npt, npt, MID + 1, p->gr, Interval{true, 0, 0, 1000000000000000000}};
            Insert(line, l, r, p->rson);
        }
    }
    pair < int, ll > Query(int pos, Node* p = root){
        auto ret = p->val.idx; auto mnv = p->val.CalVal(pos);
        if(p->gl != p->gr){
            pair < int, ll > vals;
            if(pos <= MID){
                if(!p->lson)return {0, 1000000000000000000};//p->lson = new Node{npt, npt, p->gl, MID, Interval{true, 0, 0, 1000000000000000000}};
                vals = Query(pos, p->lson);
            }else{
                if(!p->rson)return {0, 1000000000000000000};//p->rson = new Node{npt, npt, MID + 1, p->gr, Interval{true, 0, 0, 1000000000000000000}};
                vals = Query(pos, p->rson);
            }
            if(vals.second == mnv)ret = min(ret, vals.first);
            else if(vals.second < mnv)ret = vals.first, mnv = vals.second;
        }
        // printf("In tree gl = %d, gr = %d, mn = %lld\n", gl, gr, mnv);
        return {ret, mnv};
    }
}LCST;

/////////////////////// Dijkstra

struct Edge{
    Edge* nxt;
    int to;
    ll t;
    ll w;
    OPNEW;
}ed[610000];
static Edge* EP = ed; 
void* Edge::operator new(size_t){return EP++;}
Edge *head[110000], *rhead[110000];

int N, M;
ll dis[110000], rdis[110000];
bitset < 110000 > vis;

void Dijkstra(void){
    for(int i = 0; i <= N; ++i)dis[i] = 0x3f3f3f3f3f3f3f3f;
    vis.reset();
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > cur;
    dis[1] = 0, cur.push({0, 1});
    while(!cur.empty()){
        int p = cur.top().second; cur.pop();
        if(vis[p])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(dis[SON] > dis[p] + i->t)
                dis[SON] = dis[p] + i->t, cur.push({dis[SON], SON});
    }
}
void RDijkstra(void){
    for(int i = 0; i <= N; ++i)rdis[i] = 0x3f3f3f3f3f3f3f3f;
    vis.reset();
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > cur;
    rdis[N] = 0, cur.push({0, N});
    while(!cur.empty()){
        int p = cur.top().second; cur.pop();
        if(vis[p])continue;
        vis[p] = true;
        for(auto i = rhead[p]; i; i = i->nxt)
            if(rdis[SON] > rdis[p] + i->t)
                rdis[SON] = rdis[p] + i->t, cur.push({rdis[SON], SON});
    }
}

/////////////////////// Dijkstra

int main(){
    int T = read();
    while(T--){
        NP = nd;
        EP = ed;
        N = read(), M = read();
        for(int i = 0; i <= N; ++i)head[i] = rhead[i] = npt;
        for(int i = 1; i <= M; ++i){
            int u = read(), v = read(), t = read < ll >(), w = read < ll >();
            head[u] = new Edge{head[u], v, t, w};
            rhead[v] = new Edge{rhead[v], u, t, w};
        }
        Dijkstra(); RDijkstra();
        // for(int i = 1; i <= N; ++i){
        //     printf("dis[%d] = %lld, %lld\n", i, dis[i], rdis[i]);
        // }

        LCST.Clear(M << 2);
        int cnt(0);
        for(int s = 1; s <= N; ++s)
            for(auto i = head[s]; i; i = i->nxt)
                // printf("interval: k = %lld, b = %lld\n", -i->w, dis[s] + rdis[i->to] + i->t),
                LCST.Insert(Interval{true, ++cnt, -i->w, dis[s] + rdis[i->to] + i->t}, 1, 1000000000);
        
        int Q = read();
        while(Q--)
            printf("%lld\n", LCST.Query(read < ll >()).second);
    }

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