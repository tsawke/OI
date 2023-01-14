#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

bool infty(true);
ll N, M;
ll low(LONG_LONG_MIN), top(LONG_LONG_MAX);

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        ll v = read();
        if(v != 1)infty = false;
        low = max(low, (v - 1) * i), top = min(top, v * i);
    }if(infty)printf("xiaogougege\n"), exit(0);
    ll mn = (ll)ceil((ld)M / (ld)top);
    ll mx = (ll)floor((ld)M / (ld)low) - (M % low == 0 ? 1 : 0);
    ll ans = mx - mn + 1;
    printf("%lld\n", ans > 0 ? ans : 0);
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