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

int N, B;
int dep[300];
int s[300], d[300];
bool dp[300][300];
// int dp[300][300];
// int pre[300][300];

int main(){
    // memset(dp, 0x3f, sizeof dp);
    // for(int i = 0; i <= 260; ++i)dp[i][0] = i;
    dp[1][1] = 1;
    N = read(), B = read();
    for(int i = 1; i <= N; ++i)dep[i] = read();
    for(int i = 1; i <= B; ++i)s[i] = read(), d[i] = read();

    // Waiting for debugging...
    // for(int i = 1; i <= B; ++i)
    //     for(int j = 1; j <= N; ++j)
    //         for(int k = j; k >= 1; --k)
    //             if(dep[k] <= s[i] && j - k + 1 <= d[i])pre[i][j] = k;
    //             else break;
    // for(int i = 1; i <= B; ++i)
    //     for(int j = 1; j <= N; ++j)
    //         if(dep[j] <= s[i])
    //             for(int k = i - 1; k >= 0; --k)
    //                 if(pre[i][j])dp[i][j] = min(dp[i][j], dp[k][pre[i][j] - 1] + i - k - 1);
    // int mn(INT_MAX);
    // for(int i = 1; i <= B; ++i)mn = min(mn, dp[i][N]);
    // printf("%d\n", mn);

    for(int i = 1; i <= B; ++i)
        for(int j = 1; j <= N; ++j)
            if(dp[i][j])
                for(int k = i; k <= B; ++k)
                    if(s[k] >= dep[j])
                        for(int l = j + 1; l <= min(N, j + d[k]); ++l)
                            if(s[k] >= dep[l])
                                dp[k][l] = true;
    for(int i = 1; i <= B; ++i)if(dp[i][N])printf("%d\n", i - 1), exit(0);
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