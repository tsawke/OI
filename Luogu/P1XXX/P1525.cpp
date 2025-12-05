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
struct Node{int s, t, w;};
basic_string < Node > rels;

class UnionFind{
private:
    int fa[410000];
public:
    UnionFind(void){for(int i = 1; i <= 401000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){
        int fs = Find(s), ft = Find(t);
        if(fs == ft)return;
        fa[fs] = ft;
    }
}uf;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), w = read();
        rels += Node{s, t, w};
    }sort(rels.begin(), rels.end(), [](const Node &a, const Node &b)->bool{return a.w > b.w;});
    for(auto rel : rels){
        if(uf.Find(rel.s << 1) != uf.Find(rel.t << 1))uf.Union(rel.s << 1, (rel.t << 1) | 1), uf.Union((rel.s << 1) | 1, rel.t << 1);
        else printf("%d\n", rel.w), exit(0);
    }printf("0\n");
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