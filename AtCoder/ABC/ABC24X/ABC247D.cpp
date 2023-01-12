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

queue < pair < int, int >/*value, cnt*/ > balls;

int main(){
    int N = read();
    while(N--){
        int opt = read();
        if(opt == 1){
            int x = read(), c = read();
            balls.push({x, c});
        }else{
            ll ans(0);
            int c = read();
            while(c > 0 && !balls.empty()){
                auto tp = balls.front();
                if(c >= tp.second)balls.pop(), c -= tp.second, ans += (ll)tp.first * tp.second;
                else ans += (ll)c * tp.first, balls.front().second -= c, c = 0;
            }printf("%lld\n", ans);
        }
    }

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