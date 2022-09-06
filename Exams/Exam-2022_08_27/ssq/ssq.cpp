#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef long double ld;
typedef unsigned int uint;

#define npt nullptr
#define PI M_PI
#define E M_E


#define int ll

template < typename T = int >
inline T read(void);



int N;

struct Edge{
    Edge* nxt;
    // int val;
    int to;
    void* operator new(size_t);
    Edge(Edge* nxt, int to):nxt(nxt), to(to){;}
    Edge(void) = default;
}eData[210000];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}
Edge* head[210000];
int deg[210000], val[210000];
int maxdeg(0);
const int root(1);

int dist[210000];

vector < int > nums[210000];

int maxdist(0);
void dfs_dist(int p){
    
    for(auto i = head[p]; i; i = i->nxt){
        dist[i->to] = dist[p] + 1;
        dfs_dist(i->to);
        nums[dist[i->to]].push_back(val[i->to]);
        maxdist = max(maxdist, dist[i->to]);
    }
}

signed main(){
    freopen("ssq.in", "r", stdin);
    freopen("ssq.out", "w", stdout);
    N = read();
    for(int i = 2; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int f = read(), t = read();
        head[f] = new Edge(head[f], t);
        deg[f]++, deg[t]++;
        maxdeg = max(maxdeg, max(deg[f], deg[t]));
    }
    if(deg[1] == 1 && maxdeg <= 2){
        printf("0\n");
        return 0;
    }
    if(deg[1] <= 2 && maxdeg <= 2){
        int ans(0);
        for(auto i = head[1]; i; i = i->nxt){
            ans = max(ans, val[i->to]);
        }
        printf("%lld\n", ans);
        return 0;
    }
    int ans(0);
    dfs_dist(1);
    for(int i = 1; i <= maxdist; ++i){
        if(nums[i].size() <= i)continue;
        sort(nums[i].begin(), nums[i].end(), greater<int>());
        ans = max(ans, nums[i].at(i));
    }
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-'){flag = -1; c = getchar();}
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}