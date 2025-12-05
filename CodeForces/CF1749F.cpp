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

#define LIM (210000)
#define LIMD (21)

template < typename T = int >
inline T read(void);

int N, Q;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[LIM << 1];
ROPNEW;
Edge* head[LIM];
int dep[LIM], fa[LIM], siz[LIM], hson[LIM], top[LIM], dfn[LIM], idx[LIM];

// class BIT{
// private:
//     int tr[25];
// public:
//     int lowbit(int x){return x & -x;}
//     void Modify(int x, int v){while(x <= LIMD)tr[x] += v, x += lowbit(x);}
//     ll Query(int x){ll ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
//     ll QueryR(int x){return Query(LIMD) - Query(x - 1);}
// };

class SegTree{
private:
    // BIT tr[LIM << 2];
    int tr[LIM << 2][22];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Modify(int l, int r, int d, int val, int p = 1, int gl = 1, int gr = N){
        // printf("Modifying l = %d, r = %d, d = %d, val = %d\n", idx[l], idx[r], d, val);
        if(l <= gl && gr <= r)return tr[p][d] += val, void();
        if(l <= MID)Modify(l, r, d, val, LS, gl, MID);
        if(r >= MID + 1)Modify(l, r, d, val, RS, MID + 1, gr);
    }
    void ModifyPoint(int idx, int d, int val, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p][d] += val, void();
        if(idx <= MID)ModifyPoint(idx, d, val, LS, gl, MID);
        else ModifyPoint(idx, d, val, RS, MID + 1, gr);
    }
    ll Query(int idx, int d, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p][d];
        return tr[p][d] + (idx <= MID ? Query(idx, d, LS, gl, MID) : Query(idx, d, RS, MID + 1, gr));
    }
    // void Modify(int l, int r, int d, int val, int p = 1, int gl = 1, int gr = N){
    //     // printf("Modifying l = %d, r = %d, d = %d, val = %d\n", idx[l], idx[r], d, val);
    //     if(l <= gl && gr <= r)return tr[p].Modify(d + 1, val);
    //     if(l <= MID)Modify(l, r, d, val, LS, gl, MID);
    //     if(r >= MID + 1)Modify(l, r, d, val, RS, MID + 1, gr);
    // }
    // // ll Query(int idx, int p = 1, int gl = 1, int gr = N){
    // //     ll ret(0);

    // // }
    // ll Query(int l, int r, int d, int p = 1, int gl = 1, int gr = N){
    //     // printf("Querying l = %d, r = %d, d = %d\n", idx[l], idx[r], d);
    //     ll ret(0);
    //     for(int i = gl; i <= min(gr, r); ++i){
    //         int nd = (l < gl ? gl - l + i : i) + d - 1;
    //         if(nd > 20)break;
    //         ret += tr[p].QueryR(nd + 1);
    //     }
    //     if(gl == gr)return ret;
    //     if(l <= MID)ret += Query(l, r, d, LS, gl, MID);
    //     if(r >= MID + 1)ret += Query(l, r, d, RS, MID + 1, gr);
    //     return ret;
    // }
}st;



int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("tree.in", "r", stdin);
    // freopen("tree.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    auto dfs_pre = [](auto&& self, int p = 1, int fa = 0)->void{
        dep[p] = dep[fa] + 1, ::fa[p] = fa, siz[p] = 1;
        for(auto i = head[p]; i; i = i->nxt){
            if(SON == fa)continue;
            self(self, SON, p);
            siz[p] += siz[SON];
            if(siz[SON] > siz[hson[p]])hson[p] = SON;
        }
    }; dfs_pre(dfs_pre);
    auto dfs_make = [](auto&& self, int p = 1, int top = 1)->void{
        static int cdfn(0);
        dfn[p] = ++cdfn, idx[cdfn] = p, ::top[p] = top;
        if(hson[p])self(self, hson[p], top);
        for(auto i = head[p]; i; i = i->nxt)
            if(SON != fa[p] && SON != hson[p])self(self, SON, SON);
    }; dfs_make(dfs_make);
    Q = read();
    auto QueryPoint = [](int p)->ll{
        ll ret(0); int cdis = 0;
        while(p && cdis <= 20){
            // printf("Querying p = %d, d = %d, val = %lld\n", p, cdis, st.Query(p, cdis));
            ret += st.Query(dfn[p], cdis);
            p = fa[p], ++cdis;
        }
        // while(top[p] != 1){
        //     ret += st.Query(dfn[top[p]], dfn[p], cdis);
        //     cdis += dfn[p] - dfn[top[p]] + 1;
        //     p = fa[top[p]];
        // }ret += st.Query(dfn[top[p]], dfn[p], cdis);
        return ret;
    };
    auto ModifyChain = [](int s, int t, int val, int d)->int{
        while(top[s] != top[t]){
            if(dep[top[s]] < dep[top[t]])swap(s, t);
            st.Modify(dfn[top[s]], dfn[s], d, val);
            // printf("Modifying lp = %d, rp = %d, l = %d, r = %d, d = %d, val = %d\n", top[s], s, dfn[top[s]], dfn[s], d, val);
            s = fa[top[s]];
        }if(dep[s] < dep[t])swap(s, t);
        st.Modify(dfn[t], dfn[s], d, val);
        // printf("Modifying lp = %d, rp = %d, l = %d, r = %d, d = %d, val = %d\n", t, s, dfn[t], dfn[s], d, val);
        return t;
    };
    auto ModifyLCA = [](int p, int s, int t, int val, int d)->void{
        for(int i = d - 1; i >= 0; --i)st.ModifyPoint(dfn[p], i, val);//, printf("Modifying p = %d, dfnp = %d, d = %d, val = %d\n", p, dfn[p], i, val);
        // if(d - 1 >= 0)st.ModifyPoint(dfn[p], d - 1, val);
        // printf("Modifying p = %d, dfnp = %d, d = %d, val = %d\n", p, dfn[p], d - 1, val);
        int curp = fa[p], lstp = p, curd = d - 1;
        while(curp && curd >= 0){
            for(int i = 0; i <= curd; ++i){
                st.ModifyPoint(dfn[curp], i, val);
                if(i - 1 >= 0)st.ModifyPoint(dfn[lstp], i - 1, -val);
            }lstp = curp, curp = fa[curp], --curd;
        }
        // int curp = fa[p], curd = d - 1;
        // while(curd >= 0){
        //     st.ModifyPoint(dfn[curp ? curp : 1], curd, val);
        //     // printf("Modifying p = %d, dfnp = %d, d = %d, val = %d\n", p, dfn[p], d, val);
        //     curp = fa[curp], --curd;
        // }
        // curp = fa[p], curd = d - 2;
        // while(curd >= 0 && fa[curp] && curp){
        //     st.ModifyPoint(dfn[curp], curd, val);
        //     // printf("Modifying p = %d, dfnp = %d, d = %d, val = %d\n", p, dfn[p], d, val);
        //     curp = fa[curp], --curd;
        // }
    };
    while(Q--){
        int opt = read();
        if(opt == 1){
            int p = read();
            printf("%lld\n", QueryPoint(p));
        }else{
            int s = read(), t = read(), val = read(), d = read();
            ModifyLCA(ModifyChain(s, t, val, d), s, t, val, d);
        }
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
    }ret *= flag;
    return ret;
}