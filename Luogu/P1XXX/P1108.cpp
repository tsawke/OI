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
int mx(-1);
int a[5100];
int dp[5100];
int cnt[5100];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i){
        dp[i] = 1;
        for(int j = 1; j < i; ++j)if(a[j] > a[i])dp[i] = max(dp[i], dp[j] + 1);
        mx = max(mx, dp[i]);
        for(int j = 1; j < i; ++j)
            if(dp[i] == dp[j] && a[i] == a[j])cnt[j] = 0;
            else if(dp[i] == dp[j] + 1 && a[j] > a[i])cnt[i] += cnt[j];
        if(dp[i] == 1)cnt[i] = 1;
    }
    int sum(0);
    for(int i = 1; i <= N; ++i)if(dp[i] == mx)sum += cnt[i];
    printf("%d %d\n", mx, sum);
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