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

ll N;
// ll to[11000000], sum[11000000];
// ll sto[11000000], ssum[11000000];
ld ans(0.0);
ld base(0.0);

ld dp[1100][1100];

int main(){
    freopen("random.in", "r", stdin);
    freopen("random.out", "w", stdout);
    N = read < ll >();
    // sto[0] = to[0] = 1, ssum[0] = sum[0] = 0;
    // for(int i = 1; i <= N; ++i)
    //     to[i] = sto[i - 1], sto[i] = sto[i - 1] + to[i],
    //     sum[i] = ssum[i - 1] + sto[i - 1], ssum[i] = ssum[i - 1] + sum[i];

    // for(int i = 1; i <= N; ++i)
    //     printf("[%d] to = %lld, sum = %lld\n", i, to[i], sum[i]);
    // printf("%.6Lf\n", (ld)sum[N] / (ld)to[N]);
    ans += (1.0 / (ld)N);

    dp[1][1] = dp[1][0] = 1.0;
    for(ll i = 2; i <= N - 1; ++i)
        for(int j = 0; j <= i; ++j)
            dp[i][j] = dp[i - 1][j] + (j - 1 >= 0 ? dp[i - 1][j - 1] / (ld)i : 0.0);
    // for(int i = 1; i <= N - 1; ++i)
    //     for(int j = 1; j <= i; ++j)
    //         printf("dp{%d][%d] = %.6Lf%c", i, j, dp[i][j], j == i ? '\n' : ' ');
    for(int i = 1; i <= N - 1; ++i)
        ans += dp[N - 1][i] * (ld)(i + 1) / (ld)N;

    // for(ll i = 1; i <= N - 1; ++i)base += (1.0 / (ld)i);
    // ll C(1);
    // for(ll i = N - 2, cur = N; i >= 0; --i, --cur)
    //     ans += (ld)base * cur * C / (ld)N,
    //     (C *= i) /= (N - 2 - i + 1);
    printf("%.6Lf\n", ans);

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