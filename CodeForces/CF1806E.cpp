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

int N, Q;
int fa[110000];
int val[110000];
int dep[110000];
int cnt[110000];
int idx[110000];
ll ans[110000][510];
// struct HashPair{
//     ll operator ()(const pair < int, int > &p)const{
//         return p.first * (ll)(1e8) + p.second;
//     }
// };
// cc_hash_table < pair < int, int >, ll, HashPair > mp;

int main(){
    N = read(), Q = read();
    int lim = sqrt(N);
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 2; i <= N; ++i){
        fa[i] = read();
        dep[i] = dep[fa[i]] + 1;
        idx[i] = ++cnt[dep[i]];
    }
    while(Q--){
        int x = read(), y = read();
        static auto dfs = [lim](auto&& self, int x, int y)->ll{
            // if(!mp.empty() && mp.find({x, y}) != mp.end())return mp[{x, y}];
            if(cnt[dep[x]] <= lim && ans[x][idx[y]])return ans[x][idx[y]];
            if(x > y)swap(x, y);
            auto ret = !x || !y ? 0 : self(self, fa[x], fa[y]) + (ll)val[x] * val[y];
            if(cnt[dep[x]] <= lim)ans[x][idx[y]] = ret;//mp[{x, y}] = ret;
            return ret;
        };
        printf("%lld\n", dfs(dfs, x, y));
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