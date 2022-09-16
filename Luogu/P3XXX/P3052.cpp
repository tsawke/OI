#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
double rnddd(void){return (double)rndd(0, 114514000) / 114514000.0;}
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, M;
int a[20];
int dp[20];
int sum[20];
int ans(114514);
int MakeDP(void){
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0, sum[0] = 0;
    for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= N; ++i)
        for(int j = 0; j < i; ++j)
            if(sum[i] - sum[j] <= M)
                dp[i] = min(dp[i], dp[j] + 1);
    return dp[N];
}
void Luangao(void){
    double T = 1000.0;
    
    while(T > 0.00000001){
        int curx(0), cury(0);
        while(curx == cury)curx = rndd(1, N), cury = rndd(1, N);
        swap(a[curx], a[cury]);
        int nxt = MakeDP();
        int delta = abs(nxt - ans);
        if(nxt < ans)ans = nxt;
        else if(exp(-delta * 1.0 / T) > rnddd());
        else swap(a[curx], a[cury]);
        T *= 0.98;
    }
}

int main(){
    // freopen("hddd.in", "r", stdin);
    // freopen("hddd.out", "w", stdout);
    N = read(), M = read() * 1.05;
    for(int i = 1; i <= N; ++i)a[i] = read();
    while((double)clock() / CLOCKS_PER_SEC < 0.9)Luangao();
    printf("%d\n", ans);
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