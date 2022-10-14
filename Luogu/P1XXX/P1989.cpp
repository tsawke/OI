#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);

vector < pair < int, int > > input;
Edge *head[110000];
int deg[110000];
int vis[110000];
int ans(0);

int main(){
    int N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        input.push_back({s, t});
        ++deg[s], ++deg[t];
    }
    for(auto t : input){
        int i,j; tie(i, j) = t;
        if(deg[j] < deg[i] || (deg[j] == deg[i] && j < i))swap(i, j);
        head[i] = new Edge{head[i], j};
    }
    for(int i = 1; i <= N; ++i){
        for(auto j = head[i]; j; j = j->nxt)vis[j->to] = i;
        for(auto j = head[i]; j; j = j->nxt)
            for(auto k = head[j->to]; k; k = k->nxt)
                if(vis[k->to] == i)++ans;
    }
    printf("%d\n", ans);
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