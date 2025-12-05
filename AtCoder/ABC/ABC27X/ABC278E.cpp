#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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

int N, M, V;
int H, W;
int A[310][310];
int ans[310][310];
int cnt[310];
bitset < 310 > vis[310];
int tot(0);

int main(){
    N = read(), M = read(), V = read(), H = read(), W = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j)A[i][j] = read();
    for(int i = H + 1; i <= N; ++i)for(int j = 1; j <= M; ++j)if(!cnt[A[i][j]]++)++tot;
    for(int i = 1; i <= H; ++i)for(int j = W + 1; j <= M; ++j)if(!cnt[A[i][j]]++)++tot;
    auto dfs = [](auto&& self, int x = 1, int y = 1)->void{
        if(vis[x][y])return;
        vis[x][y] = true;
        ans[x][y] = tot;
        int tx = x, ty = y + 1;
        if(tx <= N - H + 1 && ty <= M - W + 1){
            for(int i = x; i <= x + H - 1; ++i)if(!cnt[A[i][y]]++)++tot;
            for(int i = x; i <= x + H - 1; ++i)if(!--cnt[A[i][ty + W - 1]])--tot;
            self(self, tx, ty);
            for(int i = x; i <= x + H - 1; ++i)if(!--cnt[A[i][y]])--tot;
            for(int i = x; i <= x + H - 1; ++i)if(!cnt[A[i][ty + W - 1]]++)++tot;
        }
        tx = x + 1, ty = y;
        if(tx <= N - H + 1 && ty <= M - W + 1){
            for(int i = y; i <= y + W - 1; ++i)if(!cnt[A[x][i]]++)++tot;
            for(int i = y; i <= y + W - 1; ++i)if(!--cnt[A[tx + H - 1][i]])--tot;
            self(self, tx, ty);
            for(int i = y; i <= y + W - 1; ++i)if(!--cnt[A[x][i]])--tot;
            for(int i = y; i <= y + W - 1; ++i)if(!cnt[A[tx + H - 1][i]]++)++tot;
        }
    }; dfs(dfs);
    for(int i = 1; i <= N - H + 1; ++i)for(int j = 1; j <= M - W + 1; ++j)printf("%d%c", ans[i][j], j == M - W + 1 ? '\n' : ' ');
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