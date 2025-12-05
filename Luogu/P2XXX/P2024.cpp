#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
// #define SON i->to
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

#define SON(i, x) (i + N * x)

template < typename T = int >
inline T read(void);

int N, M;
int ans(0);

class UnionFind{
private:
    int fa[210000];
public:
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){
        int fs = Find(s), ft = Find(t);
        if(fs == ft)return;
        fa[fs] = ft;
    }
}uf;

int main(){
    N = read(), M = read();
    while(M--){
        int opt = read(), s = read(), t = read();
        if(s > N || t > N){++ans; continue;}
        if(opt == 1){
            if(
                uf.Find(SON(s, 0)) == uf.Find(SON(t, 1)) ||
                uf.Find(SON(s, 0)) == uf.Find(SON(t, 2)) ||
                uf.Find(SON(s, 1)) == uf.Find(SON(t, 0)) ||
                uf.Find(SON(s, 1)) == uf.Find(SON(t, 2)) ||
                uf.Find(SON(s, 2)) == uf.Find(SON(t, 0)) ||
                uf.Find(SON(s, 2)) == uf.Find(SON(t, 1))
            )++ans;
            else uf.Union(SON(s, 0), SON(t, 0)), uf.Union(SON(s, 1), SON(t, 1)), uf.Union(SON(s, 2), SON(t, 2));
        }else{
            if(s == t){++ans; continue;}
            if(
                uf.Find(SON(s, 0)) == uf.Find(SON(t, 0)) ||
                uf.Find(SON(s, 0)) == uf.Find(SON(t, 2)) ||
                uf.Find(SON(s, 1)) == uf.Find(SON(t, 1)) ||
                uf.Find(SON(s, 1)) == uf.Find(SON(t, 0)) ||
                uf.Find(SON(s, 2)) == uf.Find(SON(t, 2)) ||
                uf.Find(SON(s, 2)) == uf.Find(SON(t, 1))
            )++ans;
            else uf.Union(SON(s, 0), SON(t, 1)), uf.Union(SON(s, 1), SON(t, 2)), uf.Union(SON(s, 2), SON(t, 0));
        }
    }printf("%d\n", ans);

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