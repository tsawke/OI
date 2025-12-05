#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MAXSIZE 1000000
char buf[MAXSIZE],*p1,*p2;
#define gc() (p1 == p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1== p2)?EOF:*p1++)
inline int read(){int x=0,f=1;char c=gc();while(!isdigit(c)){if(c=='-') f=-1;c=gc();}while(isdigit(c)) x=x*10+(c^48),c=gc();return x*f;}

int N, M;
int idx[310000]; //real => my
int ridx[310000]; //my => real
ll ans[310000];

int dsl[310000], dsr[310000];//i-1-depth-subtree-l / r

struct Node{
    int l, r;
    mutable ll val;
    friend const bool operator < (const Node &x, const Node &y){return x.l < y.l;}
};

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node p){return tr.insert(p);}
    auto Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        --it;
        if(p > it->r)return tr.end();
        auto l = it->l, r = it->r;
        auto val = it->val;
        tr.erase(it);
        Insert(Node{l, p - 1, val});
        return Insert(Node{p, r, val}).first;
    }
    void Assign(int l, int r, ll val){
        // printf("assigning %d-%d : %lld\n", l, r, val);
        auto itR = Split(r + 1), itL = Split(l);
        for(auto it = itL; it != itR; ++it)it->val += val;
    }
    void SetAns(void){
        for(auto p : tr)for(int i = p.l; i <= p.r; ++i)ans[ridx[i]] = p.val;
    }
}odt;

// class SegT{
// private:
//     #define LS (p << 1)
//     #define RS ((p << 1) + 1)
//     #define SIZ (gr - gl + 1)
//     #define SIZZ(l, r) (r - l + 1)
//     #define MID ((gl + gr) >> 1)
//     ll tr[310000 << 2];
//     ll lt[310000 << 2];
// public:
//     void Pushdown(int p, int gl, int gr){
//         tr[LS] += lt[p] * SIZZ(gl, MID);
//         tr[RS] += lt[p] * SIZZ(MID + 1, gr);
//         lt[LS] += lt[p], tr[RS] += lt[p];
//         lt[p] = 0;
//     }
//     void Pushup(int p){
//         tr[p] = tr[LS] + tr[RS];
//     }
//     void Modify(int p, int l, int r, ll val, int gl = 1, int gr = N){
//         if(l <= gl && gr <= r)tr[p] += SIZ * val, lt[p] += SIZ
//     }
// }

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[310000];

void bfs(void){
    int cnt(0);
    queue < pair < int, int >/*vertex, father*/ > q;
    q.push({1, 0});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        idx[p.first] = ++cnt;
        ridx[cnt] = p.first;
        vector < pair < int, int > > tmp;
        for(auto i = head[p.first]; i; i = i->nxt)
            if(SON != p.second)
                q.push({SON, p.first});
                // tmp.push_back({SON, p.first});
        // for(auto i = tmp.rbegin(); i != tmp.rend(); ++i)q.push(*i);
        if(!dsl[idx[p.second]])dsl[idx[p.second]] = dsr[idx[p.second]] = idx[p.first];
        else dsr[idx[p.second]] = idx[p.first];
        // if(!head[p.first]->nxt)dsl[p.first] = dsr[p.first] = cnt;
    }
}
void modify(int dep, int p, ll val){
    int l(p), r(p); odt.Assign(l, r, val);
    while(dep--){
        while(!dsl[l] && l <= r)++l;
        while(!dsr[r] && l <= r)--r;
        if(l > r)return;
        l = dsl[l], r = dsr[r];
        // if(l > r)return;
        odt.Assign(l, r, val);
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read();
    odt.Insert(Node{1, N, 0});
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }bfs();
    // for(int i = 1; i <= N; ++i)swap(dsl[i], dsr[i]);
    // for(int i = 1; i <= N; ++i)if(dsl[i] > dsr[i])printf("ERROR! at%d\n", i), exit(0);
    M = read();
    for(int i = 1; i <= M; ++i){
        int p = read(), dep = read(), val = read();
        modify(dep, idx[p], (ll)val);
    }
    odt.SetAns();
    for(int i = 1; i <= N; ++i)printf("%lld%c", ans[i], i == N ? '\n' : ' ');
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
