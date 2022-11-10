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
vector < pair < int, int >/*left, siz*/ > lft[3100000];
int dp[3100000];
int mx(-1);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int l = read(), r = read();
        lft[r].emplace_back(l, r - l + 1);
    }
    for(int i = 1; i <= 3010000; ++i){
        dp[i] = dp[i - 1];
        for(auto j : lft[i]){
            dp[i] = max(dp[i], dp[j.first - 1] + j.second);
        }mx = max(mx, dp[i]);
    }printf("%d\n", mx);

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