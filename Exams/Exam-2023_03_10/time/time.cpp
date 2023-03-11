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

#define LIM (16)

template < typename T = int >
inline T read(void);



// class SegTree{
// private:
//     // ll mx[LIM << 2];
//     #define MID ((gl + gr) >> 1)
// public:
//     void Pushup(p)
// }

// auto Update = [](Node* p, int dep)->void{
//     printf("dep: %d p is %d\n", dep, p ? 1 : 0);
//     // if(!p)p = new Node{{npt, npt}, 0, 0};
//     int d = swp[dep] - p->csw; p->csw = swp[dep];
//     if(d & 1)swap(p->son[0], p->son[1]);
// };
// auto Insert = [](int val)->void{
//     Node* &p = root;
//     for(int i = LIM; i >= 0; --i){
//         printf("i = %d, p is %d\n", i, p ? 1 : 0);
//         Update(p, i);
//         bool flag = val & (1 << i);
//         printf("Inserting val = %d, i = %d, csw = %d\n", val, i, p->csw);
//         if(!p->son[flag])p->son[flag] = new Node{{npt, npt}, 0, 0};
//         p = p->son[flag];
//         // if(!p)p = new Node{{npt, npt}, 0, 0};
//     }p->cnt++;
// };
// auto Modify = [](int val)->void{
//     for(int i = LIM; i >= 0; --i)
//         if(val & (1 << i))++swp[i];
// };
// auto QueryMx = [](int val)->int{
//     int ret(0);
//     Node* &p = root;
//     for(int i = LIM; i >= 0; --i){
//         Update(p, i);
//         bool flag = val & (1 << i);
//         if(p->son[flag ^ 1])ret |= 1 << i, p = p->son[flag ^ 1];
//         else p = p->son[flag];
//     }return ret;
// };
// void dfs(int p = 1, int fa = 0){
//     ans[p] = QueryMx(val[p]) + val[p];
//     Modify(val[p]), Insert(val[p]);
//     for(auto i = head[p]; i; i = i->nxt)
//         if(SON != fa)dfs(SON, p);
// };

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[810000];
ROPNEW;
Edge* head[71000];

// struct Node{
//     Node* son[2];
//     int csw;
//     int cnt;
//     OPNEW;
// }nd[810000];
// ROPNEW_NODE;
// Node* root;

int N;
int val[71000];
int ans[71000];
ll dp[71000];
int swp[20];

// #define mx(p) (p ? p->mx : 0)
// #define MID ((gl + gr) >> 1)
// #define LIM (71000)

// struct Node{
//     Node *ls, *rs;
//     ll mx;
//     OPNEW;
// }nd[LIM << 5];
// ROPNEW_NODE;
// Node* root[LIM];


// void Pushup(Node* p){
//     if(!p)return;
//     p->mx = max(mx(p->ls), mx(p->rs));
// }
// Node* Create(int idx, ll val, Node* lst, int gl = 0, int gr = LIM){
//     Node* p = lst ? new Node(*lst) : new Node{npt, npt, 0};
//     if(gl == gr)return p->mx = max(p->mx, val), p;
//     if(idx <= MID)p->ls = Create(idx, val, p->ls, gl, MID);
//     else p->rs = Create(idx, val, p->rs, MID + 1, gr);
//     return p;
// }
// ll QueryMx(int l, int r, Node* p, int gl = 0, int gr = LIM){
//     if(!p)return 0;
//     if(l <= gl && gr <= r)return p->mx;
//     if(l > gr || gl < r)return 0;
//     return max(QueryMx(l, r, p->ls, gl, MID), QueryMx(l, r, p->rs, MID + 1, gr));
// }



struct Val{ll sval; int xval;};
basic_string < Val > cur;

void dfs_dp(int p = 1, int fa = 0){
    dp[p] = val[p];
    for(auto lst : cur)dp[p] = max(dp[p], val[p] + (val[p] ^ lst.xval) + lst.sval - lst.xval);
    cur += {dp[p], val[p]};
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_dp(SON, p);
    cur.pop_back();
};

// basic_string < ll > curv[300];
struct Vval{ll val; int tim;};
basic_string < Vval > curv[300];

void dfs_by_val(int p = 1, int fa = 0, int dep = 1){
    dp[p] = val[p];
    for(int i = 0; i <= 256; ++i){
        while(!curv[i].empty() && curv[i].back().tim >= dep)curv[i].pop_back();
        if(curv[i].empty())continue;
        dp[p] = max(dp[p], val[p] + (val[p] ^ i) - i + curv[i].back().val);
    }if(curv[val[p]].empty() || dp[p] > curv[val[p]].back().val)curv[val[p]] += {dp[p], dep};
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_by_val(SON, p, dep + 1);
    if(!curv[val[p]].empty() && curv[val[p]].back().val == dp[p])curv[val[p]].pop_back();
}

void dfs_annel(int p = 1, int fa = 0){
    dp[p] = val[p];
    if(!cur.empty()){
        ll curr(dp[p]);
        // int T = max(200 * min((p * 1000 / N), 1), 50);
        // while(T--){
            
        // }
        double T = 50, delta = 0.9;
        while(T > 1e-3){
            int idx = rndd(1, (int)cur.size());
            ll nxt = val[p] + (val[p] ^ cur.at(idx - 1).xval) + cur.at(idx - 1).sval - cur.at(idx - 1).xval;
            if(nxt > curr || exp(-(double)(nxt - curr) / T))curr = nxt;
            dp[p] = max(dp[p], curr);
            T *= delta;
        }
    }
    // for(auto lst : cur)dp[p] = max(dp[p], val[p] + (val[p] ^ lst.xval) + lst.sval - lst.xval);
    cur += {dp[p], val[p]};
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_annel(SON, p);
    cur.pop_back();
}


int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int T = read();
    while(T--){
        memset(head, 0, sizeof head);
        // memset(swp, 0, sizeof swp);
        // root = new Node();
        N = read();
        int mxw(0);
        for(int i = 1; i <= N; ++i)mxw = max(mxw, val[i] = read());
        for(int i = 2; i <= N; ++i){
            int s = read(), t = i;
            head[s] = new Edge{head[s], t};
            head[t] = new Edge{head[t], s};
        }
        cur.clear();
        if(N <= 5000)dfs_dp();
        else if(mxw <= 256){
            for(int i = 0; i <= 256; ++i)curv[i].clear();
            dfs_by_val();
        }else{
            dfs_annel();
            // if(rnddd(50)){printf("qwq\n"); continue;}
            // else exit(1);
        }
        for(int i = 1; i <= N; ++i)printf("%lld\n", dp[i]);
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

/*
1
5
5 4 3 2 1
1 2 2 4
*/