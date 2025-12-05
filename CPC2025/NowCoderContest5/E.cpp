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

int N;
int A[110000];
int cnt[40][2][2]; //[i][cur][suffix 1]
int sum1[110000];
ll ans(0);


int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 0; i <= 30; ++i){
        for(int j = 1; j <= N; ++j){
            bool bit = (A[j] >> i) & 1;
            ++cnt[i][bit][sum1[j] & 1];
            if(bit)++sum1[j];
        }ans += (1ll << i) * ((ll)cnt[i][1][0] * cnt[i][0][0] + (ll)cnt[i][1][1] * cnt[i][0][1]);
    }printf("%lld\n", ans);

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