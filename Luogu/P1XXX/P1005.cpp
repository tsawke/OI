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

__int128_t ans;
__int128_t dp[110][110];
__int128_t a[110];
__int128_t pow2[110];

int N, M;
void Print128(__int128_t val){
    stack < int > nums;
    if(!val)printf("0\n"), exit(0);
    while(val)nums.push(val % 10), val /= 10;
    while(!nums.empty())printf("%d", nums.top()), nums.pop();
    printf("\n");
}

int main(){
    N = read(), M = read();
    pow2[0] = 1;
    for(int i = 1; i <= M; ++i)pow2[i] = pow2[i - 1] * 2;
    for(int line = 1; line <= N; ++line){
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= M; ++i)a[i] = read(), dp[i][i] = a[i] * pow2[M];
        for(int len = 2; len <= M; ++len){
            for(int l = 1; l <= M - len + 1; ++l){
                int r = l + len - 1;
                dp[l][r] = max(dp[l][r - 1] + a[r] * pow2[M - len + 1], dp[l + 1][r] + a[l] * pow2[M - len + 1]);
                // printf("Update [%d~%d], %d & %d\n", l, r, int(dp[l][r - 1] + a[r] * pow2[len]), int(dp[l + 1][r] + a[l] * pow2[len]));
            }
        }
        // for(int i = 1; i <= M; ++i)for(int j = 1; j <= M; ++j)printf("%d%c", (int)dp[i][j], j == M ? '\n' : ' ');
        ans += dp[1][M];
    }Print128(ans);
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