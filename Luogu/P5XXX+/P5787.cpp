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

int N, M, K;

class UnionFind{
private:
    int fa[410000], siz[410000];
    struct Mdf{int s; int fs; int t; int sizt;};
    stack < Mdf > mdfs;
public:
    UnionFind(void){for(int i = 0; i <= 401000; ++i)fa[i] = i, siz[i] = 1;}
    auto GetTop(void){return mdfs.empty() ? Mdf() : mdfs.top();}
    int Find(int x){return x == fa[x] ? x : Find(fa[x]);}
    void Union(int s, int t){
        int fs = Find(s), ft = Find(t);
        if(siz[fs] > siz[ft])swap(fs, ft);
        if(fs == ft)return;
        mdfs.push(Mdf{fs, fa[fs], ft, siz[ft]});
        siz[ft] += siz[fs];
        fa[fs] = ft;
    }
    void Repeal(Mdf endp){
        while(!mdfs.empty() && (mdfs.top().s != endp.s || mdfs.top().t != endp.t))
            fa[mdfs.top().s] =mdfs.top().fs, siz[mdfs.top().t] = mdfs.top().sizt, mdfs.pop();
    }
}uf;

class SegTree{
private:
    struct Line{int s, t;};
    basic_string < Line > tr[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Insert(int l, int r, int s, int t, int p = 1, int gl = 0, int gr = K - 1){
        if(l <= gl && gr <= r)return tr[p] += Line{s, t}, void();
        if(l <= MID)Insert(l, r, s, t, LS, gl, MID);
        if(r >= MID + 1)Insert(l, r, s, t, RS, MID + 1, gr);
    }
    void dfs(int p = 1, int gl = 0, int gr = K - 1){
        bool legal(true);
        auto lst = uf.GetTop();
        for(auto line : tr[p]){
            int fs = uf.Find(line.s << 1), ft = uf.Find(line.t << 1);
            if(fs == ft){
                legal = false;
                for(int i = gl; i <= gr; ++i)printf("No\n");
                break;
            }uf.Union(line.s << 1, (line.t << 1) | 1), uf.Union((line.s << 1) | 1, line.t << 1);
        }
        if(legal){
            if(gl != gr)dfs(LS, gl, MID), dfs(RS, MID + 1, gr);
            else printf("Yes\n");
        }uf.Repeal(lst);
    }
}st;

int main(){
    N = read(), M = read(), K = read();
    while(M--){
        int s = read(), t = read(), l = read(), r = read() - 1;
        st.Insert(l, r, s, t);
    }st.dfs();
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