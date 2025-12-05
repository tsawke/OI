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

struct Coord{
    int x, y;
    friend const bool operator == (const Coord &a, const Coord &b){return a.x == b.x && a.y == b.y;}
};
int N, M, Q;
Coord S, T;
char mp[1600][1600];
int dx[10] = {0,  -1, 0, 1, 0};
int dy[10] = {0,  0, 1, 0, -1};
bool dire[10];
bool vis[1600][1600];
bool reach[1600][1600][5];
int dfn[1600][1600], low[1600][1600];
bool inS[1600][1600];
vector < int > belong[1600][1600];
int cnt(0), BCC(0);
#define CHECK(x, y) (1 <= x && x <= N && 1 <= y && y <= M)

void bfs_pre(void){
    queue < Coord > cur; cur.push(S); vis[S.x][S.y] = true;
    while(!cur.empty()){
        auto tp = cur.front(); cur.pop();
        for(int i = 1; i <= 4; ++i){
            int tx(tp.x + dx[i]), ty(tp.y + dy[i]);
            if(CHECK(tx, ty) && !vis[tx][ty] && mp[tx][ty] ^ '#' && mp[tx][ty] ^ 'B'){
                vis[tx][ty] = true;
                for(int j = 1; j <= 4; ++j)
                    if(tx == T.x + dx[j] && ty == T.y + dy[j])dire[j] = true;
                cur.push(Coord{tx, ty});
            }
            if(dire[1] && dire[2] && dire[3] && dire[4])return;
        }
    }
}

void Tarjan(int x, int y){
    static stack < Coord > cur;
    dfn[x][y] = low[x][y] = ++cnt;
    cur.push(Coord{x, y}); inS[x][y] = true;
    for(int i = 1; i <= 4; ++i){
        int tx(x + dx[i]), ty(y + dy[i]);
        if(!CHECK(tx, ty) || mp[tx][ty] == '#')continue;
        if(!dfn[tx][ty]){
            Tarjan(tx, ty);
            low[x][y] = min(low[x][y], low[tx][ty]);
            if(low[tx][ty] >= dfn[x][y]){
                ++BCC;
                while(true){
                    auto tp = cur.top(); cur.pop();
                    belong[tp.x][tp.y].emplace_back(BCC);
                    inS[tp.x][tp.y] = false;
                    if(tp == Coord{tx, ty})break;
                }belong[x][y].emplace_back(BCC);
            }
        }else if(inS[tx][ty])
            low[x][y] = min(low[x][y], dfn[tx][ty]);
    }
}
bool InSameBSS(Coord A, Coord B){
    for(auto i : belong[A.x][A.y])
        for(auto j : belong[B.x][B.y])
            if(i == j)return true;
    return false;
}
struct Status{int x, y; int dire;};
#define OPPOSITE(x) (x <= 2 ? x + 2 : x - 2)
void bfs(void){
    queue < Status > cur;
    for(int i = 1; i <= 4; ++i)if(dire[i])cur.push(Status{T.x, T.y, i}), reach[T.x][T.y][i] = true;
    while(!cur.empty()){
        auto tp = cur.front(); cur.pop();
        for(int i = 1; i <= 4; ++i){
            int tx(tp.x + dx[i]), ty(tp.y + dy[i]);
            if(
                CHECK(tx, ty) &&
                mp[tx][ty] ^ '#' &&
                (
                    OPPOSITE(i) == tp.dire ||
                    InSameBSS(
                        Coord{tp.x + dx[tp.dire], tp.y + dy[tp.dire]},
                        Coord{tp.x + dx[OPPOSITE(i)], tp.y + dy[OPPOSITE(i)]}
                    )
                ) &&
                !reach[tx][ty][OPPOSITE(i)]
            ){
                reach[tx][ty][OPPOSITE(i)] = true;
                cur.push(Status{tx, ty, OPPOSITE(i)});
            }
        }
    }
}

int main(){
    N = read(), M = read(), Q = read();
    char c = getchar();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j){
        while(c != '#' && c != '.' && c != 'A' && c != 'B')c = getchar();
        mp[i][j] = c;
        if(mp[i][j] == 'A')S = Coord{i, j};
        if(mp[i][j] == 'B')T = Coord{i, j};
        c = getchar();
    }bfs_pre();
    Tarjan(S.x, S.y);
    bfs();
    while(Q--){
        int x = read(), y = read();
        if(Coord{x, y} == T){printf("YES\n"); continue;}
        printf("%s\n", (reach[x][y][1] || reach[x][y][2] || reach[x][y][3] || reach[x][y][4]) ? "YES" : "NO");
    }
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