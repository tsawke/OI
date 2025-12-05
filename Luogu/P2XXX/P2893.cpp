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

/*
7
2 1 5 11 5 9 11
*/
#define int ll

template < typename T = int >
inline T read(void);

int N;
int V(5010);
int a[5100], base[5100];

//roll array//////////////////////////////////
ll dp[5100];
ll mn[5100];
int mxv(-1);
basic_string < int > data;

signed main(){
    // freopen("M.in", "r", stdin);
    // freopen("M.out", "w", stdout);
    mn[0] = LONG_LONG_MAX / 2 - 10;
    N = read();
    for(int i = 1; i <= N; ++i)data += a[i] = read(), mxv = max(mxv, a[i]);

    // if(mxv > 5100){
        sort(data.begin(), data.end());
        for(int i = 1; i <= N; ++i)dp[i] = abs(a[1] - data.at(i - 1)), mn[i] = min(mn[i - 1], dp[i]);
        // for(int i = 1; i <= N; ++i)printf("dp[%d] : %lld\n", i, dp[i]);
        for(int i = 2; i <= N; ++i){
            for(int j = 1; j <= N; ++j)
                dp[j] = mn[j] + (ll)abs(a[i] - data.at(j - 1));
            for(int j = 1; j <= N; ++j)
                mn[j] = min(mn[j - 1], dp[j]);
            // for(int i = 1; i <= N; ++i)printf("dp[%d] : %lld\n", i, dp[i]);
        }
        // for(int i = 1; i <= N; ++i)printf("dp[%d] : %lld\n", i, dp[i]);
        ll ans(LONG_LONG_MAX);
        for(int i = 1; i <= N; ++i)ans = min(ans, dp[i]);
        printf("%lld\n", ans);
        exit(0);
    // }

    // // sort(data.begin(), data.end()); data.erase(unique(data.begin(), data.end()), data.end());
    // // for(int i = 1; i <= N; ++i)base[i] = distance(data.begin(), upper_bound(data.begin(), data.end(), a[i]));
    // for(int i = 1; i <= V; ++i)dp[i] = abs(a[1] - i), mn[i] = min(mn[i - 1], dp[i]);
    // for(int i = 2; i <= N; ++i){
    //     for(int j = 1; j <= V; ++j)
    //         dp[j] = mn[j - 1] + (ll)abs(a[i] - j);
    //     for(int j = 1; j <= V; ++j)
    //         mn[j] = min(mn[j - 1], dp[j]);
    // }
    // ll ans(LONG_LONG_MAX);
    // // for(int i = 1; i <= 20; ++i)printf("dp[%d] : %lld\n", i, dp[i]);
    // for(int i = 1; i <= V; ++i)ans = min(ans, dp[i]);
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