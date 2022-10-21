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

#define CHK(x, y) (x >= 1 && x <= N && y >= 1 && y <= N && !mp[x][y])

template<typename T = int>
inline T read(void);

int N;
int dx[10] = {0,  -1, -1, 1, 1};
int dy[10] = {0,  -1, 1, -1, 1};
int vis[1600][1600][5];
bool mp[1600][1600];

struct Status{
    int x, y;
    int dir;//direction 1, 2, 3, 4
    int dist;
}S, T;
void Init(void){
    char c = getchar();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j){
        while(c != '.' && c != '#')c = getchar();
        mp[i][j] = c == '.' ? false : true;
        c = getchar();
    }
}
void bfs(void){
    deque < Status > dq;
    dq.push_back(S);
    while(!dq.empty()){
        auto tp = dq.front(); dq.pop_front();
        if(vis[tp.x][tp.y][tp.dir])continue;
        vis[tp.x][tp.y][tp.dir] = true;
        if(tp.x == T.x && tp.y == T.y)
            printf("%d\n", tp.dist), exit(0);
        // printf("Current pos (%d, %d): dis = %d, dir = %d\n", tp.x, tp.y, tp.dist, tp.dir);
        for(int i = 1; i <= 4; ++i){
            int tx = tp.x + dx[i], ty = tp.y + dy[i];
            if(!CHK(tx, ty))continue;
            if(i == tp.dir)dq.push_front(Status{tx, ty, i, tp.dist});
            else dq.push_back(Status{tx, ty, i, tp.dist + 1});
        }
    }printf("-1\n");
}

int main(){
    // freopen("test_11.txt", "r", stdin);
    N = read();
    int x = read(), y = read(); S = Status{x, y, 0, 0};
    x = read(), y = read(); T = Status{x, y, 0, 0};
    Init();
    bfs();
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template<typename T>
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