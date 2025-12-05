#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;
using namespace __gnu_pbds;

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
ll sum[110000];
ll mx(0);
ll val[110000], L[110000];
__gnu_pbds::priority_queue < int, less < int >, pairing_heap_tag > ninja[110000];

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[110000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int s = read(), t = i;
        val[i] = read(), L[i] = read();
        sum[i] = val[i], ninja[i].push(val[i]);
        if(s)head[s] = new Edge{head[s], t}, head[t] = new Edge{head[t], s};
    }
    auto dfs = [](auto&& self, int p = 1, int fa = 0)->void{
        for(auto i = head[p]; i; i = i->nxt){
            if(SON == fa)continue;
            self(self, SON, p);
            sum[p] += sum[SON];
            ninja[p].join(ninja[SON]);
        }
        while(sum[p] > M)sum[p] -= ninja[p].top(), ninja[p].pop();
        mx = max(mx, L[p] * (int)ninja[p].size());
    }; dfs(dfs);
    printf("%lld\n", mx);
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