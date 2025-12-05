#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include<climits>

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

#define EPS (1e-9)

template < typename T = int >
inline T read(void);

int N, M, C;
ld P;
ld dp[1100][1100];
bitset < 1100 > vis[1100];
ld mn(1e10);

// void dfs(int x = N, int y = M, ld cur){
//     if(!x && !y)return;
//     if(x < 0 || y < 0)return;
//     vis[x][y] = true;
//     if(x - 1 >= 0 && !vis[x - 1][y])dfs(x - 1, y, (cur + 1) * (1.0 - P));
//     if(y - 1 >= 0 && !vis[x][y - 1])dfs(x, y - 1, (cur + 1) * P);
//     // if(x - 1 >= 0)dp[x - 1][y] += (dp[x][y] + 1) * (1.0 - P);
//     // if(y - 1 >= 0)dp[x][y - 1] += (dp[x][y] + 1) * P;
//     // dfs(x - 1, y), dfs(x, y - 1);
// }

bool Check(ld tim){
    // memset(dp, 0, sizeof dp);
    for(int i = 0; i <= N + 10; ++i)
        dp[i][0] = 0.0;
    for(int j = 0; j <= M + 10; ++j)
        dp[0][j] = tim;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            dp[i][j] = min(tim, (dp[i - 1][j] + 1) * (1.0 - P) + (dp[i][j - 1] + 1) * P);
    // if(dp[N][M] < mn)return mn = dp[N][M], true;
    return dp[N][M] < tim;
    // return false;
    // for(int i = N; i >= 0; --i)
    //     for(int j = M; j >= 0; --j)
    //         if(i != N || j != M)
    //             dp[i][j] = (dp[i + 1][j] + 1) * (1.0 - P) + (dp[i][j + 1] + 1) * P;

    // dfs();
    // ld tot(0.0);
    // printf("tim is %.5Lf, tot is %.5Lf\n", tim, tot);
    // for(int i = 0; i <= N; ++i)tot += dp[0][M];
    // if(tot < mn)return mn = tot, true;
    // return false;
}

int main(){
    N = read(), M = read(), C = read();
    P = (ld)C / 100.0;
    ld l = EPS, r = 1e9, ans(-1.0);
    while(fabs(l - r) > EPS){
        ld mid = (l + r) / 2.0;
        ans = mid;
        if(Check(mid))r = mid - EPS;
        else l = mid + EPS;
    }printf("%.8Lf\n", ans);

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