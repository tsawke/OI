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

template<typename T = int>
inline T read(void);

ll Func(int a, int b){
    return (ll)a * a * a + (ll)a * a * b + (ll) a * b * b + (ll)b * b * b;
}

int main(){
    ll N = read<ll>();
    ll mn(LLONG_MAX);
    for(int x = 0; x <= (int)1e6; ++x){
        int l = 0, r = (int)1e6;
        ll cur(-1);
        while(l <= r){
            int mid = (l + r) >> 1;
            ll tmp = Func(x, mid);
            if(tmp >= N)cur = tmp, r = mid - 1;
            else l = mid + 1;
        }
        mn = min(mn, cur);
    }printf("%lld\n", mn);
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