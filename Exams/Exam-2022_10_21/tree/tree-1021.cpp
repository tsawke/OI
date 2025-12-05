#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (1000000007)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[310000];

int N, Q;
int idx[310000], ridx[310000];
int dsl[310000], dsr[310000];

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
        if(!dsl[idx[p.second]])dsl[idx[p.second]] = dsr[idx[p.second]] = idx[p.first];
        else dsr[idx[p.second]] = idx[p.first];
    }
}

class SegTree{
private:
    ll st[310000 << 2];
    ll lz[310000 << 2];
    #define LS (p << 1)
    #define RS ((p << 1) + 1)
    #define MID ((gl + gr) >> 1)
public:
    // void Pushup(int p){st[p] = st[LS] + st[RS];}
    void Pushdown(int p){
        st[LS] = (st[LS] + lz[p]) % MOD, st[RS] = (st[RS] + lz[p]) % MOD;
        lz[LS] = (lz[LS] + lz[p]) % MOD, lz[RS] = (lz[RS] + lz[p]) % MOD;
        lz[p] = 0;
    }
    void Modify(int l, int r, ll val, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return st[p] = (st[p] + val) % MOD, lz[p] = (lz[p] + val) % MOD, void();
        Pushdown(p);
        if(l <= MID)Modify(l, r, val, LS, gl, MID);
        if(MID + 1 <= r)Modify(l, r, val, RS, MID + 1, gr);
    }
    ll Query(int idx, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return st[p];
        Pushdown(p);
        if(idx <= MID)return Query(idx, LS, gl, MID);
        else return Query(idx, RS, MID + 1, gr);
    }
}st;

void Mdf(int p, ll val, int k){
    int l(p), r(p), dis(0);
    st.Modify(l, r, (val - (ll)dis * k + MOD) % MOD);
    while(true){
        ++dis;
        while(!dsl[l] && l <= r)++l;
        while(!dsr[r] && l <= r)--r;
        if(l > r)return;
        l = dsl[l], r = dsr[r];
        st.Modify(l, r, (val - (ll)dis * k + MOD) % MOD);
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read();
    for(int i = 2; i <= N; ++i){
        int fa = read();
        head[i] = new Edge{head[i], fa};
        head[fa] = new Edge{head[fa], i};
    }bfs();
    Q = read();
    while(Q--){
        int opt = read();
        if(opt == 1){
            int v = read(), x = read(), k = read();
            Mdf(idx[v], (ll)x, k);
        }else{
            int v = read();
            printf("%lld\n", (st.Query(idx[v]) + MOD) % MOD);
        }
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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