#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

ll N;
ll ans(0);
basic_string < int > prime;
bool notPrime[1100000];
int sum[1100000];

int main(){
    N = read < ll >();
    ll lim = (ll)powl(N, 1.0 / 3.0) + 10;
    for(int i = 2; i <= lim; ++i){
        if(!notPrime[i])prime += i;
        for(auto p : prime){
            if(i * p > lim)break;
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }for(int i = 2; i <= lim; ++i)sum[i] = sum[i - 1] + (!notPrime[i] ? 1 : 0);
    for(auto p : prime){
        ll base = (ll)p * p * p;
        ans += sum[min(N / base, (ll)p - 1)];
    }printf("%lld\n", ans);
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