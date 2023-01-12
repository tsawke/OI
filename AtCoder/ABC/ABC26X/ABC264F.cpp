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

int H, W;
ll R[2100], C[2100];
ll dp[2100][2100][2][2];
bitset < 2100 > G[2100];

int main(){
    H = read(), W = read();
    for(int i = 1; i <= H; ++i)R[i] = read();
    for(int i = 1; i <= W; ++i)C[i] = read();
    for(int i = 1; i <= H; ++i)
        for(int j = 1; j <= W; ++j){
            char c = getchar(); while(!isdigit(c))c = getchar();
            G[i][j] = c == '1' ? true : false;
        }
    memset(dp, 0x3f, sizeof dp);
    dp[1][1][0][0] = 0, dp[1][1][1][0] = R[1], dp[1][1][0][1] = C[1], dp[1][1][1][1] = R[1] + C[1];
    for(int i = 1; i <= H; ++i)
        for(int j = 1; j <= W; ++j)
            for(int x = 0; x <= 1; ++x)
                for(int y = 0; y <= 1; ++y){
                    if((G[i][j] ^ x ^ y )== (G[i + 1][j] ^ y))dp[i + 1][j][0][y] = min(dp[i + 1][j][0][y], dp[i][j][x][y]);
                    else dp[i + 1][j][1][y] = min(dp[i + 1][j][1][y], dp[i][j][x][y] + R[i + 1]);
                    if((G[i][j] ^ x ^ y) == (G[i][j + 1] ^ x))dp[i][j + 1][x][0] = min(dp[i][j + 1][x][0], dp[i][j][x][y]);
                    else dp[i][j + 1][x][1] = min(dp[i][j + 1][x][1], dp[i][j][x][y] + C[j + 1]);
                }
    ll ans(LONG_LONG_MAX);
    for(int x = 0; x <= 1; ++x)for(int y = 0; y <= 1; ++y)ans = min(ans, dp[H][W][x][y]);
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