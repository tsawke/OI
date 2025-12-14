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
    ll S = read < ll >();
    vector < ll > W(N);
    for(int i = 0; i < N; ++i)W[i] = read < ll >();

    if(S == 1){printf("%d\n", N >= 1 ? 1 : 0); return 0;}

    if(S >= 2 && N <= 2){printf("%d\n", N); return 0;}

    sort(W.begin(), W.end());

    ll num(0), cnt1(0), cnt2(0);
    int used(0);

    for(int i = 0; i < N - 2; ++i){
        ll len = W[i];
        ll x = len / 3;
        int r = len % 3;
        if(r == 1)++cnt1;
        if(r == 2)++cnt2;
        ll pairCnt = cnt1 < cnt2 ? cnt1 : cnt2;
        x += pairCnt;
        cnt1 -= pairCnt;
        cnt2 -= pairCnt;
        ll need = num + x + (cnt1 + 1) / 2 + cnt2;
        if(need > S - 2)break;
        num += x;
        ++used;
    }

    int ans = used + 2;
    if(ans > N)ans = N;
    printf("%d\n", ans);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
