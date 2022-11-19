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

int N, K;
string S;
int dp[510][110][110][2];

int main(){
    memset(dp, 0xc0, sizeof dp);
    dp[0][0][0][1] = 0;
    N = read(), K = read();
    cin >> S;
    for(int i = 1; i <= N; ++i)
        for(int j = 0; j <= K; ++j)
            for(int k = 0; k <= K; ++k)
                if(S.at(i - 1) == 'j'){
                    dp[i][j][k][0] = max(dp[i - 1][j][k][0], dp[i - 1][j][k][1]);
                    if(j)dp[i][j][k][1] = max(dp[i - 1][j - 1][k][0] + 1, dp[i - 1][j - 1][k][1]);
                }else{
                    dp[i][j][k][1] = max(dp[i - 1][j][k][0] + 1, dp[i - 1][j][k][1]);
                    if(k)dp[i][j][k][0] = max(dp[i - 1][j][k - 1][0], dp[i - 1][j][k - 1][1]);
                }
    int ans(0);
    for(int i = 1; i <= K; ++i)ans = max({ans, dp[N][i][i][0], dp[N][i][i][1]});
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