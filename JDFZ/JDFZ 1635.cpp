#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
void dfs(int, const int&);
//vector<int>queenPos;
bool column[30];
bool slanting[3][30];
bool available[30][30];
int ans(0);
bool GetMap(void);
int main(){//Debug Required
    int n = read<int>();
    for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)available[i][j] = GetMap();
    dfs(1, n);
    printf("%d\n", ans);
    pause();
    return 0;
}
/*bool check(int x, int y){
    for(int i = 1; i <= queenPos.size(); ++i)
        if(y == queenPos.at(i - 1) || abs(x - i) == abs(y - queenPos.at(i - 1)))return false;
    return true;
}*/
bool GetMap(void){
    char flag;
    while((flag = getchar()) != EOF){
        if(flag == '*')return true;
        if(flag == '.')return false;
    }
    return true;
}
void dfs(int deep, const int& depth){
    if(deep > depth){++ans; return;}
    for(int i = 1; i <= depth; ++i){
        if(available[deep][i] && !column[i] && !slanting[1][deep + i] && !slanting[2][deep - i + depth]){
            column[i] = slanting[1][deep + i] = slanting[2][deep - i + depth] = true;
            dfs(deep + 1, depth);
            column[i] = slanting[1][deep + i] = slanting[2][deep - i + depth] = false;
        }
    }
}
template <typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        ret *= 10, ret += (c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}