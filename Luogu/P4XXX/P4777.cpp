#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

void exgcd(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y){
    if(!b)return x = 1, y = 0, void();
    exgcd(b, a % b, x, y);
    __int128_t tmp(x);
    x = y;
    y = tmp - a / b * y;
}
void Query(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y, __int128_t c){
    exgcd(a, b, x, y);
    __int128_t d = c / __gcd(a, b);
    x *= d, y *= d;
    __int128_t val = b / __gcd(a, b);
    x = (x % val + val) % val;
    y = (c - a * x) - b;
}

int N;
__int128_t rem1(-1), mod1(-1);

int main(){
    N = read();
    while(N--){
        __int128_t mod2 = read < ll >(), rem2 = read < ll >();
        if(!~rem1 || !~mod1){rem1 = rem2, mod1 = mod2; continue;}
        __int128_t b1, b2;
        Query(mod1, -mod2, b1, b2, rem2 - rem1);
        rem1 = rem1 + b1 * mod1;
        mod1 = mod1 * mod2 / __gcd(mod1, mod2);
        rem1 = (rem1 % mod1 + mod1) % mod1;
    }printf("%lld\n", rem1);
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