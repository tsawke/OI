#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (998244353ll)

template<typename T = int>
inline T read(void);

int A[210000];
ll sum(0), mx(0), mn(INT_MAX), fst(-1), lst(-1);

int main(){
    int T = read();
    while(T--){
        int N = read();
        sum = 0, mx = 0, mn = INT_MAX, fst = N, lst = 1;
        for(int i = 1; i <= N; ++i){
            A[i] = read();
            sum += A[i];
            mx = max(mx, (ll)A[i]);
            if(A[i]){
                mn = min(mn, (ll)A[i]);
                lst = max(lst, (ll)i);
                if(fst == N)fst = i;
            }
        }
        if(mn == INT_MAX){
            printf("%lld %lld\n", sum, ((ll)N + 1) * ((ll)N + 1) % MOD * ((((ll)N + 1) * (ll)N) >> 1) % MOD);
            continue;
        }
        printf("%lld %lld\n", sum, ((ll)N - mx + 1) * (mn + (ll)N + 1) % MOD * fst % MOD * ((ll)N - lst + 1) % MOD);
    }    

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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