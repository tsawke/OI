#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

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

int N, K;
vector < int > line;
int dp[10][9 * 9 + 10][1 << 9]; //i, kingN, cur
void dfs(int dep, int cur){
    if(dep > N)return (void)line.push_back(cur);
    dfs(dep + 1, cur << 1);
    if(!(cur & 1))cur <<= 1, dfs(dep + 1, cur + 1);
}
int count(int x){
    int ret(0);
    for(int i = 0; i < N; ++i)if((x >> i) & 1)++ret;
    return ret;
}
int ans(0);

signed main(){
    N = read(), K = read();
    dfs(1, 0);
    for(auto j : line)dp[1][count(j)][j] = 1;
    for(int i = 2; i <= N; ++i){
        for(auto k : line){
            for(auto l : line){
                if(k & l || (k << 1) & l || (k >> 1) & l)continue;
                int cnt = count(k);
                for(int j = 0; j + cnt <= K; ++j){
                    dp[i][j + cnt][k] += dp[i - 1][j][l];
                }
            }
        }
    }
    // for(int i = 1; i <= N; ++i){
    //     printf("No.%d \n", i);
    //     for(int j = 1; j <= K; ++j){
    //         for(auto k : line){
    //             cout<<bitset<8>(k);
    //             printf(": %d   ", dp[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    // }
    for(auto i : line)ans += dp[N][K][i];
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