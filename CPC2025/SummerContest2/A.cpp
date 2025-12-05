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

int N, M;
char mp[20][20];
int dp[20][20][10];
int dx[10] = {0, 0, 0, -1, 1};
int dy[10] = {0, -1, 1, 0, 0};
string label = " YOKOHAMA";

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j){
        char c = getchar();
        while(c != 'A' && c != 'H' && c != 'K' && c != 'M' && c != 'O' && c != 'Y')c = getchar();
        mp[i][j] = c;
        if(c == 'Y')dp[i][j][1] = 1;
    }
    for(int k = 1; k <= 7; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(!dp[i][j][k])continue;
                for(int p = 1; p <= 4; ++p){
                    int tx = i + dx[p], ty = j + dy[p];
                    if(1 <= tx && tx <= N && 1 <= ty && ty <= M && mp[tx][ty] == label[k + 1]){
                        dp[tx][ty][k + 1] += dp[i][j][k];
                    }
                }
            }
        }
    }
    int ans(0);
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j)
        ans += dp[i][j][8];
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