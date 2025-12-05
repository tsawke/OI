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

typedef __float128 f128;

template<typename T = int>
inline T read(void);



int main(){
    freopen("tomato.in", "r", stdin);
    freopen("tomato.out", "w", stdout);
    ll N = read<ll>(), X = read<ll>();
    // f128 tmp1 = sinf128(((f128)N + (f128)0.5) * X) * sinf128((f128)X / (f128)2);
    // f128 tmp2 = (f128)1.0 - cosf128((f128)X);
    // f128 ans = (f128)0.5 + tmp1 / tmp2;
    // printf("%.6lf\n", (double)ans);

    f128 anss(0.0);
    for(ll i = 0; i <= N; ++i){
        anss += cosf128((f128)i * (f128)X);
    }
    printf("%.6lf\n", (double)anss);
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