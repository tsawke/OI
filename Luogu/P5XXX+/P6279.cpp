#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template< typename T = int >
inline T read(void);

class UnionFind{
private:
public:
    int fa[210000];
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i;}
    // int Find(int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}
}uf;

int N, M;
basic_string < int > belike[210000];
basic_string < int > son[210000];
queue < int > cur;
int col[210000];

void Union(int a, int b){
    if(son[a].size() < son[b].size())swap(a, b);
    for(auto sp : son[b])uf.fa[sp] = a;
    son[a] += son[b];
    belike[a] += belike[b];
    if(belike[a].size() > 1)cur.push(a);
}

int main(){
    // freopen("P6279_5.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        belike[s] += t;
    }
    for(int i = 1; i <= N; ++i){
        son[i] += i;
        if(belike[i].size() > 1)cur.push(i);
    }
    while(!cur.empty()){
        int tp = cur.front(); cur.pop();
        ///////////////////////////
        while(belike[tp].size() > 1){
            if(uf.fa[*belike[tp].begin()] != uf.fa[*next(belike[tp].begin())])
                Union(uf.fa[*belike[tp].begin()], uf.fa[*next(belike[tp].begin())]);
            belike[tp].erase(belike[tp].begin());
        }
        ///////////////////////////
        // if(belike[tp].size() <= 1)continue;
        // auto lst = belike[tp].begin();
        // for(auto p : belike[tp].substr(1)){
        //     if(uf.fa[p] != uf.fa[*lst])
        //         Union(uf.fa[p], uf.fa[*lst]);
        //     advance(lst, 1);
        // }belike[tp].clear();
        ///////////////////////////
    }static int ccol(0);
    for(int i = 1; i <= N; ++i){if(!col[uf.fa[i]])col[uf.fa[i]] = ++ccol; printf("%d\n", col[uf.fa[i]]);}
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