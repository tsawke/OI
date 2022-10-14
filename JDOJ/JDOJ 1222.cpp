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

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

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

#define read read < int >
#define MINF -0x3f3f3f3f
int N;
int h[110];
int dp[110][2100];

int main(){
    dp[0][0] = 0;
    for(int i = 1; i <= 2010; ++i)dp[0][i] = MINF;
    N = read();
    int sum(0);
    for(int i = 1; i <= N; ++i)h[i] = read(), sum += h[i];
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= sum; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j >= h[i])dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + h[i]);
            else dp[i][j] = max(dp[i][j], dp[i - 1][h[i] - j] + j);
            if(j + h[i] <= sum)dp[i][j] = max(dp[i][j], dp[i - 1][j + h[i]]);
        }
    }
    if(dp[N][0] > 0)printf("%d\n", dp[N][0]);
    else printf("Impossible\n");
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}