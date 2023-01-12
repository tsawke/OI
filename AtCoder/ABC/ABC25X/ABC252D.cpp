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

int N;
int a[210000];
int cnt[210000];
ll ans(0);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)cnt[a[i] = read()]++;
    ans = (ll)N * (N - 1) * (N - 2) / (3 * 2 * 1);
    for(int i = 1; i <= 201000; ++i){
        if(cnt[i] >= 2)ans -= (ll)cnt[i] * (cnt[i] - 1) / (2 * 1) * (N - cnt[i]);
        if(cnt[i] >= 3)ans -= (ll)cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / (3 * 2 * 1);
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