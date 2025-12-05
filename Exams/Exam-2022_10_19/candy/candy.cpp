#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

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
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MAXSIZE 1000000
char buf[MAXSIZE],*p1,*p2;
#define gc() (p1 == p2&&(p2=(p1=buf)+fread(buf,1,MAXSIZE,stdin),p1== p2)?EOF:*p1++)
inline int read(){int x=0,f=1;char c=gc();while(!isdigit(c)){if(c=='-') f=-1;c=gc();}while(isdigit(c)) x=x*10+(c^48),c=gc();return x*f;}

#define CMP [](int x, int y)->bool{return ctr[x] - cost[x] > ctr[y] - cost[y];}

// struct cmp{
//     bool operator ()(const int &x, const int &y){return ctr[x] - cost[x] > ctr[y] - cost[y];}
// };

int N, M;
int val[1100000];
int idx[1100000];
ll ctr[1100000];
ll cost[1100000];
ll ans(0);
vector < int > vt[1100000];
// vector < int > heap;
bool used[1100000];


int main(){
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    // freopen("candy1.in", "r", stdin);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)val[i] = read(), idx[i] = i;
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        ctr[s] += val[s], ctr[t] += val[t];
        cost[s] += val[t], cost[t] += val[s];
        vt[s].emplace_back(t), vt[t].emplace_back(s);
    }
    for(int i = 1; i <= N; ++i)ctr[i] -= cost[i];
    // sort(idx + 1, idx + N + 1, [](int x, int y)->bool{return ctr[x] == ctr[y] ? cost[x] < cost[y] : ctr[x] > ctr[y];});
    // sort(idx + 1, idx + N + 1, [](int x, int y)->bool{return cost[x] == cost[y] ? ctr[x] > ctr[y] : cost[x] < cost[y];});
    sort(idx + 1, idx + N + 1, [](int x, int y)->bool{return ctr[x] > ctr[y];});
    // for(int i = 1; i <= N; ++i)
        // heap.emplace(lower_bound(heap.begin(), heap.end(), i, CMP), i);
    for(int i = 1; i <= N; ++i){
        // sort(idx + 1, idx + N + 1, );
        // int p = heap.front();
        int p = idx[i];
        used[p] = true;
        // heap.erase(heap.begin());
        ans += cost[p];
        for(auto j : vt[p])
            if(!used[j])
                cost[j] -= val[p];
                // printf("%lld %lld (%d)\n", cost[j], ctr[j], j),
                // heap.erase(find(heap.begin(), heap.end(), j)),
                // heap.emplace(lower_bound(heap.begin(), heap.end(), j, CMP), j);
    }
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
