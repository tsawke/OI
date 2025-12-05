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

#define INF 0x3f3f3f3f

template<typename T = int>
inline T read(void);

int N;
int a[1100000];
int dp_r[1100000][4];
int* dp[1100000];

int main(){
    memset(dp_r, 0x3f, sizeof(dp_r));
    for(int i = 0; i <= 1010000; ++i)dp[i] = dp_r[i] + 1;
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    dp[1][a[1]] = 0;
    for(int i = 2; i <= N; ++i){
        switch(a[i]){
            case -1:{
                dp[i][-1] = dp[i - 1][-1];
                // dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][1] + 2;
                break;
            }
            case 0:{
                dp[i][-1] = dp[i - 1][-1] + 1;
                dp[i][0] = min(dp[i - 1][-1], dp[i - 1][0]);
                dp[i][1] = dp[i - 1][1] + 1;
                break;
            }
            case 1:{
                dp[i][-1] = dp[i - 1][-1] + 2;
                dp[i][0] = dp[i - 1][-1] + 1;
                dp[i][1] = min({dp[i - 1][-1], dp[i - 1][0], dp[i - 1][1]});
                break;
            }
            default:break;
        }
    }
    // for(int i = 1; i <= N; ++i){
    //     for(int j = -1; j <= 1; ++j){
    //         printf("%d%c", dp[i][j], j == 1 ? '\n' : ' ');
    //     }
    // }
    int ans = min({dp[N][-1], dp[N][0], dp[N][1]});
    ans >= INF  ? printf("BRAK\n")
                : printf("%d\n", ans);
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