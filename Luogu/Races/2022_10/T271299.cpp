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
}ed[2100000];
ROPNEW(ed);
Edge* head[1100000];

int N;
int deg[1100000];
int idx[1100000];
int maxD(0);

// namespace BL{
//     int f[]
// }

void dfs1(int p = 1, int cur = 1, int fa = -1){
    idx[p] = cur;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON != fa)dfs1(SON, cur + 1, p);
    }
}

int main(){

    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        ++deg[s], ++deg[t];
        maxD = max({maxD, deg[s], deg[t]});
    }
    // if(N <= 10){
    //     return 0;
    // }
    if(maxD == 2){
        dfs1();
        for(int i = 1; i <= N; ++i)printf("%d%c", idx[i], i == N ? '\n' : ' ');
        return 0;
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