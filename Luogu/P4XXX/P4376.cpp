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

int N, M;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
static Edge* P = ed;
Edge* head[110000];
void* Edge::operator new(size_t){return P++;}
void Clear(void){
    P = ed;
    memset(head, 0, sizeof(Edge*) * (N + 10));
}

int ind[110000];
vector < int > rnk[51000];
vector < int > ans;
vector < int > tmp;

bool Check(int lim){
    memset(ind, 0, sizeof(int) * (N + 10));
    Clear();
    tmp.clear();
    for(int i = 1; i <= lim; ++i){
        auto lst = rnk[i].begin();
        for(auto it = next(rnk[i].begin()); it != rnk[i].end(); ++it)
            ++ind[*it], head[*lst] = new Edge{head[*lst], *it}, lst = it;
    }
    std::priority_queue < int, vector < int >, greater < int > > cur;
    for(int i = 1; i <= N; ++i)if(!ind[i])cur.push(i);
    while(!cur.empty()){
        int tp = cur.top(); cur.pop();
        tmp.emplace_back(tp);
        for(auto i = head[tp]; i; i = i->nxt){
            --ind[SON];
            if(!ind[SON])cur.push(SON);
        }
    }
    return (int)tmp.size() == N;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int m = read();
        while(m--)rnk[i].emplace_back(read());
    }
    int l = 1, r = M;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(Check(mid))ans.swap(tmp), l = mid + 1;
        else r = mid - 1;
    }
    for(auto i : ans)printf("%d ", i);
    printf("\n");
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
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