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
struct Coord{int x, y;}a[110000];
int mnpre[110000], mxsuf[110000];

int main(){
    memset(mnpre, 0x3f, sizeof mnpre);
    memset(mxsuf, 0xc0, sizeof mxsuf);
    N = read();
    for(int i = 1; i <= N; ++i)a[i].x = read(), a[i].y = read();
    sort(a + 1, a + N + 1, [](Coord a, Coord b)->bool{return a.x != b.x ? a.x < b.x : a.y < b.y;});
    for(int i = 1; i <= N; ++i)mnpre[i] = min(mnpre[i - 1], a[i].y);
    for(int i = N; i >= 1; --i)mxsuf[i] = max(mxsuf[i + 1], a[i].y);
    int ans(1);
    for(int i = 1; i < N; ++i)if(mnpre[i] > mxsuf[i + 1])++ans;
    printf("%d\n", ans);
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