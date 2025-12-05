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

int L, N;
vector < pair < int, int >/*price, position*/ > rest;
int spdF, spdB;
int d;
ll ans(0);

int main(){
    L = read(), N = read(), spdF = read(), spdB = read(); d = spdF - spdB;
    for(int i = 1; i <= N; ++i){int p = read(), c = read(); rest.emplace_back(c, p);}
    int cur(0); sort(rest.begin(), rest.end(), greater < pair < int, int > >());
    for(auto res : rest)
        ans += (ll)res.first * max(0, res.second - cur) * d, cur = max(cur, res.second);
    printf("%lld\n", ans);
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