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

#define MOD (int)(1e9 + 7)

template< typename T = int >
inline T read(void);

int N, M, K;
string S1, S2;
int dp[2][202][202][2];

int main(){
    N = read(), M = read(), K = read();
    cin >> S1 >> S2;
    for(int i = 0; i <= N; ++i)dp[i & 1][0][0][0] = 1;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            for(int k = 1; k <= K; ++k)
                    dp[i & 1][j][k][0] = ((ll)dp[(i - 1) & 1][j][k][0] + dp[(i - 1) & 1][j][k][1] ) % MOD,
                    dp[i & 1][j][k][1] = S1.at(i - 1) == S2.at(j - 1)
                        ? ((ll)dp[(i - 1) & 1][j - 1][k - 1][0] + dp[(i - 1) & 1][j - 1][k - 1][1] + dp[(i - 1) & 1][j - 1][k][1]) % MOD
                        : 0;
    printf("%lld\n", ((ll)dp[N & 1][M][K][0] + dp[N & 1][M][K][1]) % MOD);
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