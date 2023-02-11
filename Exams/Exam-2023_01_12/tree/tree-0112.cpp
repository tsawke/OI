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
// ld dp[2][1100][1100];
// ll dp[1100];
// ll tot[1100];
// ld dp[1100];

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read();
    // dp[1][1][0] = 1.0;
    // for(int i = 2; i <= N; ++i){
    //     ll base(0);
    //     for(int j = 0; j <= i; ++j)for(int k = 0; k <= i; ++k)if(dp[!(i & 1)][j][k])base += 2 * j + k;
    //     for(int j = 0; j <= i; ++j){
    //         for(int k = 0; k <= i; ++k){
    //             dp[i & 1][j][k] = 0.0;
    //             if(k - 1 >= 0)dp[i & 1][j][k] += (2.0 * j / base) * dp[!(i & 1)][j][k - 1],
    //             printf("upd i = %d, j = %d, k = %d, from %.5Lf\n", i, j, k, dp[!(i & 1)][j][k - 1]);
    //             if(j - 1 >= 0)dp[i & 1][j][k] += ((k + 1.0) / base) * dp[!(i & 1)][j - 1][k + 1];
    //         }
    //     }
    // }
    // ld ans(0.0);
    // for(int j = 0; j <= N; ++j)for(int k = 0; k <= N; ++k)ans += dp[N & 1][j][k] * j;
    // printf("%.9Lf\n", ans);

    // dp[1] = 1.0;
    // for(int i = 2; i <= N; ++i)
    //     for(int j = 0; j <= i; ++j)
    //         if(i - j - 1 >= 0)
    //             dp[i] += (dp[j] + dp[i - j - 1])
    // printf("%.9Lf\n", (ld)((__float128)dp[N] / tot[N]));

    // dp[1] = 1, tot[0] = tot[1] = 1;
    // for(int i = 2; i <= N; ++i)
    //     for(int j = 0; j <= i; ++j)
    //         if(i - j - 1 >= 0)
    //             dp[i] += dp[j] * tot[i - j - 1] + dp[i - j - 1] * tot[j],
    //             tot[i] += tot[j] * tot[i - j - 1];
    // for(int i = 0; i <= N; ++i)printf("dp is %lld, tot is %lld\n", dp[i], tot[i]);
    printf("%.10Lf\n", (((ld)N * N + N) / (4 * N - 2)));
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