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

#define EPS (double)(1e-7)

template< typename T = int >
inline T read(void);

int N, W;
int wei[300], val[300];
double c[300];
double dp[1100];

bool Check(double lim){
    for(int i = 1; i <= 1010; ++i)dp[i] = -114514.0;
    for(int i = 1; i <= N; ++i)c[i] = (double)val[i] - lim * (double)wei[i];
    for(int i = 1; i <= N; ++i)for(int j = W; j >= 0; --j)
        j + wei[i] >= W
            ? dp[W] = max(dp[W], dp[j] + c[i])
            : dp[j + wei[i]] = max(dp[j + wei[i]], dp[j] + c[i]);
    return dp[W] >= 0.0;
}

int main(){
    N = read(), W = read();
    double l(0.0), r(0.0);
    for(int i = 1; i <= N; ++i)wei[i] = read(), val[i] = read(), r += (double)val[i];
    int ans;
    while(l + EPS <= r){
        double mid = (l + r) / 2.0;
        if(Check(mid))ans = (int)floor(mid * 1000.0), l = mid;
        else r = mid;
    }printf("%d\n", ans);
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