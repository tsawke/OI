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
struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    OPNEW;
}ed[4100000];
ROPNEW;
Edge* head[510000];
bitset < 510000 > inS;
int dfn[510000], low[510000];
struct edge{int s, t;};
int BCC(0);
basic_string < int > pts[510000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        if(s == t)continue;
        head[s] = new Edge{head[s], npt, t};
        head[t] = new Edge{head[t], npt, s};
        head[s]->rev = head[t], head[t]->rev = head[s];
    }
    auto Tarjan = [](auto&& self, int p, Edge* fa = npt)->void{
        static stack < int > cur;
        static int cdfn(0);
        dfn[p] = low[p] = ++cdfn;
        cur.push(p);
        int cnt_son(0);
        for(auto i = head[p]; i; i = i->nxt){
            if(!dfn[SON]){
                ++cnt_son;
                self(self, SON, i->rev);
                low[p] = min(low[p], low[SON]);
                if(low[SON] >= dfn[p]){
                    ++BCC;
                    while(cur.top() != SON)pts[BCC] += cur.top(), cur.pop();
                    pts[BCC] += cur.top(); cur.pop();
                    pts[BCC] += p;
                }
            }else if(i != fa)low[p] = min(low[p], dfn[SON]);
        }
        if(!fa && !cnt_son)pts[++BCC] += p;
    };
    for(int i = 1; i <= N; ++i)if(!dfn[i])Tarjan(Tarjan, i);
    printf("%d\n", BCC);
    for(int i = 1; i <= BCC; ++i){
        printf("%d ", (int)pts[i].size());
        for(auto p : pts[i])printf("%d ", p);
        printf("\n");
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