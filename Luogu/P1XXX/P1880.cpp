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
int st[210];
int sum[210];
int dp_mx[210][210], dp_mn[210][210];

int main(){
    memset(dp_mn, 0x3f, sizeof dp_mn);
    N = read();
    for(int i = 1; i <= N; ++i)st[i + N] = st[i] = read();
    for(int i = 1; i <= N * 2; ++i)sum[i] = sum[i - 1] + st[i], dp_mn[i][i] = 0;
    for(int len = 1; len <= N; ++len){
        for(int l = 1; l <= N * 2 - len + 1; ++l){
            int r = l + len - 1;
            for(int spl = l; spl <= r - 1; ++spl){
                dp_mx[l][r] = max(dp_mx[l][r], dp_mx[l][spl] + dp_mx[spl + 1][r] + sum[r] - sum[l - 1]);
                dp_mn[l][r] = min(dp_mn[l][r], dp_mn[l][spl] + dp_mn[spl + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }int mx(0), mn(INT_MAX);
    for(int i = 1; i <= N; ++i)mx = max(mx, dp_mx[i][i + N - 1]), mn = min(mn, dp_mn[i][i + N - 1]);
    printf("%d\n%d\n", mn, mx);
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