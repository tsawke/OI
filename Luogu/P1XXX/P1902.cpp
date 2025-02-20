#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int N, M;
int P[1100][1100];
int mn[1100][1100];
bool vis[1100][1100];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            P[i][j] = read();
    
    auto bfs = [](int lim) -> bool{
        memset(vis, 0, sizeof vis);
        queue < pair < int, int > > q;
        q.push(make_pair(1, 1));
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur.first == N)return true;
            for(int i = 1; i <= 4; ++i){
                auto nxt = make_pair(cur.first + dx[i], cur.second + dy[i]);
                if(1 <= nxt.first && nxt.first <= N && 1 <= nxt.second && nxt.second <= M && !vis[nxt.first][nxt.second] && P[nxt.first][nxt.second] <= lim)
                    q.push(nxt), vis[nxt.first][nxt.second] = true;
            }
        }return false;
    };
    int l(0), r(1000), ans(0);
    while(l <= r){
        int mid = (l + r) >> 1;
        if(bfs(mid))ans = mid, r = mid - 1;
        else l = mid + 1;
    }printf("%d\n", ans);

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