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

vector < int > vert[110000];
int N;
int base[110000];
bool vis[110000];
int cur(0);
void dfs(int p, int mapp){
    base[p] = mapp;
    vis[p] = true;
    for(auto i : vert[p]){
        if(!vis[i]){
            vis[i] = true;
            dfs(i, mapp ^ (1 << (cur++)));
        }
    }
}
int dp[110000];
vector < int > legal;
void Init(int N){
    int lim = 1 << N;
    dp[0] = 0;
    for(int i = 1; i <= lim; ++i){
        dp[i] = dp[i >> 1] + (i & 1);
        if(!(dp[i] & 1))legal.push_back(i);
    }
}
int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int f = read(), t = read();
        vert[f].push_back(t);
        vert[t].push_back(f);
    }
    dfs(0, 0);
    Init(N);
    printf("%d\n", (int)legal.size() + 1);
    for(int i = 0; i <= N; ++i)printf("%d%c", base[i], i == N ? '\n' : ' ');
    for(auto i : legal)
        for(int j = 0; j <= N; ++j)
            printf("%d%c", base[j] ^ i, j == N ? '\n' : ' ');
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