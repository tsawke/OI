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
int ans(0);

class UnionFind{
private:
    int fa[210000];
    ll dis[210000];
public:
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i, dis[i] = 0;}
    void Clear(void){for(int i = 1; i <= 201000; ++i)fa[i] = i, dis[i] = 0;}
    int Find(int x){
        if(x == fa[x])return x;
        int cfa = fa[x];
        fa[x] = Find(fa[x]);
        dis[x] += dis[cfa];
        return fa[x];
    }
    void Union(int s, int t, ll d){
        int fs = Find(s), ft = Find(t);
        if(fs == ft)return;
        fa[fs] = ft;
        dis[fs] = d + dis[t] - dis[s];
    }
    bool CheckDis(int s, int t, ll d){
        return dis[s] != d + dis[t];
    }
}uf;

int main(){
    while(true){
        ans = 0, uf.Clear();
        N = read(), M = read();
        while(M--){
            int s = read(), t = read() + 1, d = read();
            if(uf.Find(s) != uf.Find(t))uf.Union(s, t, d);
            else ans += uf.CheckDis(s, t, d);
        }printf("%d\n", ans);
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
    int c = getchar();
    if(!~c)exit(0);
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