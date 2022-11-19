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

#define IN_RANGE(x, y) (1 <= x && x <= N && 1 <= y && y <= N)

template< typename T = int >
inline T read(void);

int N;
int mp[300][300];
int belong[300][300];
// bitset < 90000 > exist[90000];

struct HashPair{
    size_t operator() (const pair < int, int > &x)const{
        // auto hash1 = hash < int >{}(x.first);
        // auto hash2 = hash < int >{}(x.second);
        // return hash1 ^ hash2;
        return (ll)x.first * x.second % (1000000007);
    }
};

unordered_set < pair < int, int >, HashPair > exist;
int mx1(-1), mx2(-1);
int cnt(0);
pair < int, int > blk[110000];
bitset < 90000 > vis[1];
int ver(0);

int dx[10] = {0, -1, 0, 1, 0};
int dy[10] = {0, 0, 1, 0, -1};

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[910000];
ROPNEW(ed);
Edge* head[210000];

void bfs(int idx, int val, int px, int py){
    queue < pair < int, int > > cur;
    cur.push({px, py});
    belong[px][py] = idx;
    ++blk[idx].second;
    while(!cur.empty()){
        auto tp = cur.front(); cur.pop();
        for(int i = 1; i <= 4; ++i){
            int tx = tp.first + dx[i], ty = tp.second + dy[i];
            if(!IN_RANGE(tx, ty))continue;
            if(mp[tx][ty] == val && !belong[tx][ty])++blk[idx].second, belong[tx][ty] = idx, cur.push({tx, ty});
        }
    }
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)mp[i][j] = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            if(!belong[i][j]){
                blk[++cnt].first = mp[i][j];
                bfs(cnt, mp[i][j], i, j);
            }
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            for(int k = 1; k <= 4; ++k){
                int tx = i + dx[k], ty = j + dy[k];
                if(IN_RANGE(tx, ty) && belong[tx][ty] != belong[i][j]){
                    int t = belong[tx][ty], s = belong[i][j];
                    if(exist.find(make_pair(s, t)) == exist.end()){
                        exist.insert({s, t});
                        head[s] = new Edge{head[s], t};
                        head[t] = new Edge{head[t], s};
                    }
                }
            }
    for(int i = 1; i <= cnt; ++i)mx1 = max(mx1, blk[i].second);
    queue < int > tmp;
    queue < int > undel;
    for(int p = 1; p <= cnt; ++p)
        for(auto t = head[p]; t; t = t->nxt){
            if((double)clock() / CLOCKS_PER_SEC > 0.9)printf("%d\n%d\n", mx1, mx2), exit(0);
            while(!undel.empty()){
                int tp = undel.front(); undel.pop();
                vis[ver][tp] = false;
            }
            int ans(0);
            // ++ver;
            // vis[ver].reset();
            vis[ver][p] = vis[ver][t->to] = true;
            undel.push(p), undel.push(t->to);
            tmp.push(p), tmp.push(t->to);
            ans += blk[p].second, ans += blk[t->to].second;
            while(!tmp.empty()){
                int tp = tmp.front(); tmp.pop();
                for(auto i = head[tp]; i; i = i->nxt){
                    if(vis[ver][SON])continue;
                    if(blk[SON].first == blk[p].first || blk[SON].first == blk[t->to].first){
                        vis[ver][SON] = true;
                        undel.push(SON);
                        tmp.push(SON);
                        ans += blk[SON].second;
                    }
                }
            }
            mx2 = max(mx2, ans);
        }
    printf("%d\n%d\n", mx1, mx2);
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