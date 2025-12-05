#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

template<typename T = int>
inline T read(void);


int N;
int a[11000];
int dp[11000] = {1};

bool cmp(int x, int y){
    return (a[x] ^ y) < (x ^ a[y]);
}

signed main(){
    freopen("butterfly.in", "r", stdin);
    freopen("butterfly.out", "w", stdout);
    N = read();
    for(int i = 0; i <= N - 1; ++i)a[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        for(int j = 0; j < i; ++j){
            if(cmp(j, i))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans(-1);
    for(int i = 0; i <= N - 1; ++i)ans = max(ans, dp[i]);
    printf("%lld\n", ans);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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