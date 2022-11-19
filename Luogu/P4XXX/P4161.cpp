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

int N, MOD;
vector < int > prime;
bool notPrime[11000];
ll dp[11000];

int main(){
    N = read();
    for(int i = 2; i <= N; ++i){
        if(!notPrime[i])prime.emplace_back(i);
        for(auto p : prime){
            if(p * i > N)break;
            notPrime[p * i] = true;
            if(i % p == 0)break;
        }
    }dp[0] = 1;
    //dp[i][j] = dp[i - 1][j - p^k] * p^k
    for(auto p : prime){
        for(int i = N; i >= p; --i){
            int cur(p);
            while(cur <= i)dp[i] += dp[i - cur], cur *= p;
        }
    }ll ans(0);
    for(int i = 0; i <= N; ++i)ans += dp[i];
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