#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define int ll

template<typename T = int>
inline T read(void);

int dp[510][510][510]; //i-th flower, j-price k-fresh
int N, Q;
int pri[510], fre[510], bty[510];
int ans[510][510];
signed main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)pri[i] = read(), fre[i] = read(), bty[i] = read();
    for(int i = 1; i <= N; ++i){
        for(int k = fre[i]; k <= 500; ++k){
            for(int j = pri[i]; j <= 500; ++j){
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - pri[i]][k - fre[i]] + bty[i]);
            }
        }
    }
    for(int j = 1; j <= 500; ++j){
        for(int k = 500; k >= 1; --k){
            for(int i = 1; i <= N; ++i){
                ans[j][k] = max(ans[j][k + 1], dp[i][j][k]);
            }
        }
    }
    for(int j = 1; j <= 500; ++j){
        for(int k = 1; k <= 500; ++k){
            ans[j][k] = max(ans[j - 1][k], ans[j][k]);
        }
    }
    while(Q--){
        int cst = read(), fsh = read();
        printf("%lld\n", ans[cst][fsh]);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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