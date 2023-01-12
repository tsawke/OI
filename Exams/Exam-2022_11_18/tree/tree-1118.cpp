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

int N, Q;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

bool vis[110000];
basic_string < int > vised;

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }Q = read();
    while(Q--){
        int K = read();
        bool flag(true);
        for(int k = 1; k <= K; ++k){
            int p = read();
            vis[p] = true;
            vised += p;
            for(auto i = head[p]; i; i = i->nxt)
                if(vis[SON]){flag = false; break;}
        }
        printf("%d\n", flag ? K - 1 : -1);
        for(auto p : vised)vis[p] = false;
        vised.clear();
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

/*
4
1 3
2 3
4 3
4
2 1 2
3 2 3 4
3 1 2 4
4 1 2 3 4

*/