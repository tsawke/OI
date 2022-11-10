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

int N;
int a[110];
int dp[110][110];
int cal(int s, int t){
    int cnt(0);
    for(int i = s; i <= t; ++i)if(a[i] != i - s)++cnt;
    return cnt;
}

int main(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 0; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            for(int k = i + 1; k <= N; ++k)
                dp[k][j] = min(dp[k][j], dp[i][j - 1] + cal(i + 1, k));
    for(int i = 1; i <= N; ++i)printf("%d\n", dp[N][i]);
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