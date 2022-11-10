#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

#define MAXN (1100000)
#define MOD (998244353)

template < typename T = int >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }return ret * flag;
}

int N, K;
int a[MAXN];



int main(){
    // freopen("function.in", "r", stdin);
    // freopen("function.out", "w", stdout);

    N = read(), K = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    // st.Build();
    ll ans(0);
    for(int i = 1; i <= K; ++i){
        int mn(1), mx(i);
        for(int j = 1; j <= N; ++j){
            ll val = max(abs(a[j] + mn), abs(a[j] + mx));
            // printf("val: %lld\n", val);
            ans = (ans + val * val % MOD) % MOD;
        }
        // printf("Cur ans : %lld\n", ans);
        // printf("Curans : %d = %lld\n", i, ans);
    }
    // for(int i = 1; i <= K; ++i){
    //     int sp = -(int)ceil((double)(K + 1) / 2.0);
    //     auto ptr = lower_bound(a + 1, a + N + 1, sp);
    //     int idx = distance(a + 1, ptr + 1);
    //     st.Modify(1, idx - 1, 1);
    //     st.Modify(idx, N, i);
    //     ans = (ans + st.Query(1, N));
    //     st.Modify(1, idx - 1, -1);
    //     st.Modify(idx, N, -i);
    //     /
    // }
    printf("%lld\n", ans);

    return 0;
}