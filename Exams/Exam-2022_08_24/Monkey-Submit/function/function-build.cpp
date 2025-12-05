#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define PI M_PI
#define E M_E
#define npt nullptr

#define MOD 998244353

#define logg(a, b) ((double)log(b) / log(a))

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef long long ll;
typedef unsigned long long unll;

template <typename T = int>
inline T read(void);

ll CAL(int N){
    ll ans(0ll);
    for(int a = 2; a <= N; ++a){
        ll tmp(0);
        for(int b = a; b <= N; ++b){
            tmp = ( tmp + (int)(floor(logg(a, b)) * ceil(logg(b, a))) % MOD ) % MOD; 
        }
        ans = (ans + (a * tmp) % MOD ) % MOD;
    }
    return ans;
}

int main(){
    freopen("array2.txt", "w", stdout);
    // printf("int ans[60000010] = {0, 0, ");
    // for(int i = 2; i <= 60000000; ++i){
    //     printf("%lld%c", CAL(i), i == 60000000 ? '}' : ',');
    //     if(i % 100 == 0)printf("\n"), fprintf(stderr, "i = %d has COMPLETED!\n", i);
    //     fflush(stdout);
    // }
    int cnt(0);
    while(++cnt){
        int val(rndd(7000, 30000));
        printf("ans[%d]=%lld,", val, CAL(val));
        fflush(stdout);
        if(cnt % 100 == 0)printf("\n"), fprintf(stderr, "cnt = %d has COMPLETED!\n", cnt);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = 1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

/* Examples:



*/