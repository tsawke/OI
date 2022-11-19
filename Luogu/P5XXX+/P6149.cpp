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

#define MOD (ll)(1e9 + 7)

template< typename T = int >
inline T read(void);

int N;
struct Coord{int x, y;}pt[110000];
ll sumx[110000], cntx[110000], sumy[110000], cnty[110000];
ll lstx[110000], lsty[110000];
ll ans(0);

void Make(void){
    memset(sumx, 0, sizeof sumx);
    memset(sumy, 0, sizeof sumy);
    memset(cntx, 0, sizeof cntx);
    memset(cnty, 0, sizeof cnty);
    memset(lstx, 0, sizeof lstx);
    memset(lsty, 0, sizeof lsty);
    for(int i = 1; i <= N; ++i){
        sumx[pt[i].x] = (sumx[pt[i].x] + abs(pt[i].y - lstx[pt[i].x]) * cntx[pt[i].x]) % MOD;
        ++cntx[pt[i].x], lstx[pt[i].x] = pt[i].y;
        sumy[pt[i].y] = (sumy[pt[i].y] + abs(pt[i].x - lsty[pt[i].y]) * cnty[pt[i].y]) % MOD;
        ++cnty[pt[i].y], lsty[pt[i].y] = pt[i].x;
        ans = (ans + sumx[pt[i].x] * sumy[pt[i].y] % MOD) % MOD;
    }
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)pt[i].x = read() + 11000, pt[i].y = read() + 11000;
    sort(pt + 1, pt + N + 1, [](const Coord &a, const Coord &b)->bool{return a.x == b.x ? a.y < b.y : a.x < b.x;}); Make();
    sort(pt + 1, pt + N + 1, [](const Coord &a, const Coord &b)->bool{return a.x == b.x ? a.y > b.y : a.x < b.x;}); Make();
    sort(pt + 1, pt + N + 1, [](const Coord &a, const Coord &b)->bool{return a.x == b.x ? a.y < b.y : a.x > b.x;}); Make();
    sort(pt + 1, pt + N + 1, [](const Coord &a, const Coord &b)->bool{return a.x == b.x ? a.y > b.y : a.x > b.x;}); Make();
    printf("%lld\n", ans);
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