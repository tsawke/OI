#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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
    ll val;
    OPNEW;
}ed[21000];
ROPNEW(ed);
Edge* head[1100];

int N;
int cnt(0);
unordered_map < string, int > score;
map < pair < int, int >, int > mp;
unordered_map < int, pair < int, int > > rmp;
bitset < 1100 > inq;
int dep[1100];
ll dis[1100];
ll ans(LONG_LONG_MIN);

void SPFA(void){
    memset(dis, 0xc0, sizeof dis);
    queue < int > cur;
    cur.push(1); inq[1] = true; dep[1] = 1, dis[1] = 0;
    while(!cur.empty()){
        int p = cur.front(); cur.pop();
        inq[p] = false;
        for(auto i = head[p]; i; i = i->nxt){
            if(dis[p] + i->val > dis[SON]){
                dis[SON] = dis[p] + i->val;
                ans = max(ans, dis[SON]);
                dep[SON] = dep[p] + 1;
                if(dep[SON] > 26 * 26 + 26 + 1)printf("Infinity\n"), exit(0);
                if(!inq[SON])cur.push(SON), inq[SON] = true;
            }
        }
    }
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        string S; cin >> S;
        score.insert({S, read()});
    }mp.insert({{0, 0}, ++cnt}), rmp.insert({cnt, {0, 0}});
    for(int i = 'a'; i <= 'z'; ++i)mp.insert({{0, i}, ++cnt}), rmp.insert({cnt, {0, i}});
    for(int i = 'a'; i <= 'z'; ++i)for(int j = 'a'; j <= 'z'; ++j)
        mp.insert({{i, j}, ++cnt}), rmp.insert({cnt, {i, j}});
    for(int i = 1; i <= cnt; ++i)for(int j = 'a'; j <= 'z'; ++j){
        ll tot(0); string S;
        if(rmp[i].first)S += (char)rmp[i].first;
        if(rmp[i].second)S += (char)rmp[i].second;
        S += j; tot += score[S];
        while(!S.empty()){
            S.erase(S.begin());
            tot += score[S];
        }
        head[i] = new Edge{head[i], mp[{rmp[i].second, j}], tot};
    }SPFA();
    printf("%lld\n", ans);
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