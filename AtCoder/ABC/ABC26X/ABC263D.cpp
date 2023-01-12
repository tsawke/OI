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

int N, L, R;
int A[210000];
ll sum[210000];

// ll sumA[210000];
// ll preA(0), sufA(0), sumL(0), sumR(0);
// ll dmxl(LONG_LONG_MIN), dmxpl(-1), dmxr(LONG_LONG_MIN), dmxpr(-1);
// ll ans(0);

int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), L = read(), R = read();
    for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + (A[i] = read());
    ll ans(min((ll)N * min(L, R), sum[N]));
    ll mxL(0);
    for(int i = 1; i <= N; ++i){
        ans = min(ans, sum[i] + (ll)(N - i) * R - mxL);
        mxL = max(mxL, sum[i] - (ll)i * L);
    }printf("%lld\n", ans);

    // for(int i = 1; i <= N; ++i){
    //     ll D = (preA += A[i]) - (sumL += L);
    //     if(D > dmxl)dmxl = D, dmxpl = i;
    // }
    // for(int i = N; i >= 1; --i){
    //     ll D = (sufA += A[i]) - (sumR += R);
    //     if(D > dmxr)dmxr = D, dmxpr = i;
    // }
    // if(dmxpl >= dmxpr)L <= R ? dmxpr = dmxpl + 1 : dmxpl = dmxpr - 1;
    // ans += sumA[dmxpr - 1] - sumA[dmxpl];
    // if(dmxl > 0)ans += (ll)L * dmxpl;
    // else ans += sumA[dmxpl];
    // if(dmxr > 0)ans += (ll)R * (N - dmxpr + 1);
    // else ans += sumA[N] - sumA[dmxpr - 1];
    // printf("%lld\n", ans);
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