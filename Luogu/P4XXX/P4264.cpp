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
ll origin(0);
ll mn(LONG_LONG_MAX);
map < ll, ll > mp;
ll sum[310000]; int cnt(0);

void Insert(int p, int v){
    if(mp.find(p) == mp.end())mp.insert({p, v});
    else mp[p] += v;
}
void InsertAll(int sp1, int sp2, int sp3){
    Insert(sp1, -1);
    Insert(sp2, 2);
    Insert(sp3, -1);
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int a = read(), b = read();
        origin += abs(a - b);
        if(0 <= 2 * a && 2 * a < b)InsertAll(2 * a, b, 2 * b - 2 * a);
        else if(b < 2 * a && 2 * a <= 0)InsertAll(2 * b - 2 * a, b, 2 * a);
        else if(a < 0 && 0 < b)InsertAll(0, b, 2 * b);
        else if(b < 0 && 0 < a)InsertAll(2 * b, b, 0);
    }
    ll cur(0), sum(origin); int lft(INT_MIN);
    mn = origin;
    for(auto v : mp){
        sum += (ll)cur * (v.first - lft);
        cur += v.second, lft = v.first;
        mn = min(mn, sum);
    }
    printf("%lld\n", mn);
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