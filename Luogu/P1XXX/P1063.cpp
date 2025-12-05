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
int fnt[210], til[210];
int dp[210][210];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)til[i - 1] = fnt[i] = read();
    til[N] = fnt[1];
    for(int i = N + 1; i <= N + N; ++i)fnt[i] = fnt[i - N], til[i] = til[i - N];
    for(int len = 2; len <= N; ++len){
        for(int l = 1; l <= N + N - len + 1; ++l){
            int r = l + len - 1;
            for(int sp = l; sp <= r - 1; ++sp){
                dp[l][r] = max(dp[l][r], dp[l][sp] + dp[sp + 1][r] + fnt[l] * til[sp] * til[r]);
            }
        }
    }int mx(-1);
    for(int i = 1; i <= N; ++i)mx = max(mx, dp[i][i + N - 1]);
    printf("%d\n", mx);
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