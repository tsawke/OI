#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

int N;
int ans(0);
bitset < 2100 > mp[2100];
int dx[10] = {0,  -1, -1, 0, 0, 1, 1};
int dy[10] = {0,  -1, 0, -1, 1, 0, 1};

void bfs(int x, int y){
    queue < pair < int, int > > cur; cur.push({x, y}); mp[x][y] = false;
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        for(int i = 1; i <= 6; ++i)for(int j = 1; j <= 6; ++j){
            int tx = p.first + dx[i], ty = p.second + dy[i];
            if(1 <= tx && tx <= 2001 && 1 <= ty && ty <= 2001 && mp[tx][ty])
                mp[tx][ty] = false, cur.push({tx, ty});
        }
    }
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int x = read() + 1001, y = read() + 1001;
        mp[x][y] = true;
    }
    for(int i = 1; i <= 2001; ++i)for(int j = 1; j <= 2001; ++j)
        if(mp[i][j])++ans, bfs(i, j);
    printf("%d\n", ans);
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