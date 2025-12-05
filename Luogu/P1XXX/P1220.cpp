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

#define int ll

template< typename T = int >
inline T read(void);

int N;
int sumv[1100];
int x0;
struct Egg{
    int x, y;
    int v;
    friend const bool operator < (const Egg &a, const Egg &b){return a.x < b.x;}
}egg[1100];
ll dpl[1100][1100], dpr[1100][1100];

signed main(){
    N = read(), x0 = read();
    // egg[1].x = x0;
    for(int i = 1; i <= N; ++i)egg[i].x = read(), egg[i].v = read();
    // for(int i = 1; i <= N; ++i)egg[i].y = read();
    // for(int i = 1; i <= N; ++i)
    // sort(egg + 1, egg + N + 1);
    for(int i = 1; i <= N; ++i)sumv[i] = sumv[i - 1] + egg[i].v;
    // for(int i = 1; i <= N; ++i)dpl[i][i] = dpr[i][i] = (ll)egg[i].y - (ll)(sumv[N] - sumv[i]) * abs(egg[i].x - x0);
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)
        dpl[i][j] = dpr[i][j] =  i == j && i == x0 ? 0 : -(LONG_LONG_MAX / 2);

    // for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)printf("%lld-%lld%c", dpl[i][j], dpr[i][j], j == N ? '\n' : ' ');
    for(int len = 2; len <= N; ++len){
        for(int l = 1; l <= N - len + 1; ++l){
            int r = l + len - 1;
            dpl[l][r] = egg[l].y + max(
                dpl[l + 1][r] - (ll)abs(egg[l + 1].x - egg[l].x) * (sumv[l] + sumv[N] - sumv[r]),
                dpr[l + 1][r] - (ll)abs(egg[r].x - egg[l].x) * (sumv[l] + sumv[N] - sumv[r])
            );
            dpr[l][r] = egg[r].y + max(
                dpr[l][r - 1] - (ll)abs(egg[r].x - egg[r - 1].x) * (sumv[l - 1] + sumv[N] - sumv[r - 1]),
                dpl[l][r - 1] - (ll)abs(egg[r].x - egg[l].x) * (sumv[l - 1] + sumv[N] - sumv[r - 1])
            );
        }
    }
    // for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)printf("%lld-%lld%c", dpl[i][j], dpr[i][j], j == N ? '\n' : ' ');
    // printf("%.3Lf\n", (ld)max(dpl[1][N], dpr[1][N]) / (ld)1000.0);
    printf("%lld\n", -max(dpl[1][N], dpr[1][N]));
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