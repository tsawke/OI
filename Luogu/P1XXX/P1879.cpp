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



template<typename T = int>
inline T read(void);

int N, M;
vector < int > line;
int dp[20][1 << 12][1 << 12]; //i, cur, last
void dfs(int dep, int cur){
    if(dep > M)return (void)line.push_back(cur);
    dfs(dep + 1, cur << 1);
    if(!(cur & 1))cur <<= 1, dfs(dep + 1, cur + 1);
}
int land[20];
int main(){
    N = read(), M = read();
    dfs(1, 0);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            land[i] <<= 1;
            land[i] += !read(); 
        }
    }
    // for(int i = 1; i <= N; ++i)cout<<bitset<8>(land[i])<<endl;
    // for(auto i : line)cout<<bitset<8>(i)<<endl;
    for(auto j : line)if(!(j & land[1]))dp[1][j][0]++;
    for(auto j : line)for(auto k : line){
        if(j & k || j & land[2] || k & land[1])continue;
        dp[2][j][k] += dp[1][k][0];
    }
    for(int i = 3; i <= N; ++i){
        for(auto j : line){
            for(auto k : line){
                for(auto l : line){
                    if(j & k || k & l)continue;
                    if(j & land[i] || k & land[i - 1] || l & land[i - 2])continue;
                    dp[i][j][k] += dp[i - 1][k][l];
                }
            }
        }
    }
    int ans(0);
    for(auto j : line)for(auto k : line)ans += dp[N][j][k];
    printf("%d\n", ans % 100000000);
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