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

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

int N;

int dfs(int k, int p = 1, int fa = 0){
    multiset < int > unmatch;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        int lft = dfs(k, SON, p);
        if(!~lft)return -1;
        ++lft;
        unmatch.insert(lft);
        // ++lft, lft %= k;
        // if(!lft)continue;
        // if(unmatch.find(k - lft) != unmatch.end())unmatch.erase(unmatch.find(k - lft));
        // else unmatch.insert(lft);
    }int ret(0);
    if((p == 1 && unmatch.size() & 1) || (p != 1 && !(unmatch.size() & 1)))unmatch.insert(0);
    while(!unmatch.empty()){
        auto tp = *unmatch.begin(); unmatch.erase(unmatch.begin());
        auto it = unmatch.lower_bound(k - tp);
        if(p == 1){if(it == unmatch.end())return -1; unmatch.erase(it);}
        else{
            if(it == unmatch.end() && ret)return -1;
            if(it == unmatch.end() && !ret)ret = tp;
            else unmatch.erase(it);
        }
    }return ret;
    // if(p == 1){
    //     while(!unmatch.empty()){
    //         int tp = *unmatch.begin(); unmatch.erase(unmatch.begin());
    //         if(tp >= k)return 0;
    //         auto it = unmatch.lower_bound(k - tp);
    //         if(it != unmatch.end())unmatch.erase(it);
    //         else return 114514;
    //     }return 0;
    // }
    // // if(unmatch.size() & 1 == unmatch.insert(0);
    // while(!unmatch.empty()){
    //     int tp = *unmatch.begin(); unmatch.erase(unmatch.begin());
    //     if(tp >= k){ret = tp; continue;}
    //     auto it = unmatch.lower_bound(k - tp);
    //     if(it != unmatch.end())unmatch.erase(it);
    //     else{
    //         if(ret)return -1;
    //         else ret = tp;
    //     }
    // }return ret;
}

int main(){
    // freopen("P6142_10.in", "r", stdin);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    int l = 1, r = N - 1, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(!dfs(mid))ans = mid, l = mid + 1;
        else r = mid - 1;
    }printf("%d\n", ans);
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