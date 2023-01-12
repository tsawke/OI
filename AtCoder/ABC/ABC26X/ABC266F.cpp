#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

struct Edge{
    Edge* nxt;
    int to;
    bool blocked;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];

int N;
int deg[210000];
bitset < 210000 > inloop;
int col[210000], cnt(0);
basic_string < int > loop;

void dfs(int p, int ccol, int fa = 0){
    col[p] = ccol;
    for(auto i = head[p]; i; i = i->nxt)
        if(!i->blocked && SON != fa)dfs(SON, ccol, p);
}

int main(){
    inloop.set();
    N = read();
    for(int i = 1; i <= N; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t, false};
        head[t] = new Edge{head[t], s, false};
        ++deg[s], ++deg[t];
    }queue < int > cur;
    for(int i = 1; i <= N; ++i)if(deg[i] == 1)cur.push(i), inloop[i] = false;
    while(!cur.empty()){
        int p = cur.front(); cur.pop();
        for(auto i = head[p]; i; i = i->nxt)
            if(inloop[SON] && --deg[SON] == 1)
                inloop[SON] = false, cur.push(SON);
    }
    for(int i = 1; i <= N; ++i)if(inloop[i])loop += i;
    for(auto p : loop)for(auto i = head[p]; i; i = i->nxt)if(inloop[SON])i->blocked = true;
    for(auto p : loop)dfs(p, ++cnt);
    int Q = read();
    while(Q--){
        int s = read(), t = read();
        printf("%s\n", !(col[s] ^ col[t]) ? "Yes" : "No");
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