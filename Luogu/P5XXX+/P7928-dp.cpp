#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

int N, K;
bool stone[400];
int sum[400];
int dp[400][400][400];
int DFS(int l, int r, int k){
    if(~dp[l][r][k])return dp[l][r][k];
    if(k >= K)return false;
    int k_ = sum[N] - (sum[r] - sum[l - 1]) - k;
    if(k_ >= K)return true;
    return dp[l][r][k] = (!DFS(l + 1, r, k_) | !DFS(l, r - 1, k_));
}

int main(){
    memset(dp, -1, sizeof(dp));
    N = read(), K = read();
    for(int i = 1; i <= N; ++i){
        char c = getchar(); while(c != 'C' && c != 'P')c = getchar();
        stone[i] = (c == 'C' ? true : false);
        sum[i] = sum[i - 1] + stone[i];
    }
    printf("%s\n", DFS(1, N, 0) ? "DA" : "NE");
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