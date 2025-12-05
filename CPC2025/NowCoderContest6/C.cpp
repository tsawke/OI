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



template<typename T = int>
inline T read(void);

const ll MOD = 998244353ll;
ll F[4][510000];

int main(){
    F[0][1] = F[1][1] = F[2][1] = F[3][1] = 1;
    for(int i = 2; i <= 500100; ++i){
        F[0][i] = i * F[0][i - 1] % MOD;
        F[1][i] = (i * F[1][i - 1] % MOD + F[0][i - 1]) % MOD;
        F[2][i] = (i * F[2][i - 1] % MOD + 2 * F[1][i - 1] % MOD + F[0][i - 1]) % MOD;
        F[3][i] = (i * F[3][i - 1] % MOD + 3 * F[2][i - 1] % MOD + 3 * F[1][i - 1] % MOD + F[0][i - 1]) % MOD;
    }
    int T = read();
    while(T--)printf("%lld\n", F[3][read()]);

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