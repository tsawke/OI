#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
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



int main(){
    int N = read();
    ll s = read < ll >();

    vector < ll > sumT(N + 10, 0);
    vector < ll > sumC(N + 10, 0);

    for(int i = 1; i <= N; ++i){
        int t = read(), c = read();
        sumT[i] = sumT[i - 1] + (ll)t;
        sumC[i] = sumC[i - 1] + (ll)c;
    }

    const ll INF(0x3f3f3f3f3f3f3f3fLL);
    vector < ll > dp(N + 10, 0);
    for(int i = 1; i <= N; ++i)dp[i] = INF;
    dp[0] = 0;

    ll totC(sumC[N]);

    for(int i = 1; i <= N; ++i){
        ll curT(sumT[i]);
        ll curC(sumC[i]);
        for(int j = 0; j < i; ++j)
            dp[i] = min(dp[i], dp[j] + curT * (curC - sumC[j]) + s * (totC - sumC[j]));
    }

    printf("%lld\n", dp[N]);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
