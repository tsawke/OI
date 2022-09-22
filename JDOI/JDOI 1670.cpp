#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool f[110];
bool vis[30][30][30];
int La, Lb, Lc;
void dfs(int a, int b, int c){
    if(vis[a][b][c])return;
    vis[a][b][c] = true;
    if(!a)f[c] = true;
    if(a){
        if(a <= Lb - b)dfs(0, b + a, c);
        else dfs(a - Lb + b, Lb, c);
        if(a <= Lc - c)dfs(0, b, c + a);
        else dfs(a - Lc + c, b, Lc);
    }
    if(b){
        if(b <= La - a)dfs(a + b, 0, c);
        else dfs(La, b - La + a, c);
        if(b <= Lc - c)dfs(a, 0, c + b);
        else dfs(a, b - Lc + c, Lc);
    }
    if(c){
        if(c <= La - a)dfs(a + c, b, 0);
        else dfs(La, b, c - La + a);
        if(c <= Lb - b)dfs(a, b + c, 0);
        else dfs(a, Lb, c - Lb + b);
    }
    return;
}
vector<int>ans;
int main(){
    scanf("%d%d%d", &La, &Lb, &Lc);
    dfs(0, 0, Lc);
    for(int i = 0; i <= 20; ++i)if(f[i])ans.push_back(i);
    for(vector<int>::iterator itea = ans.begin(); itea < ans.end(); ++itea)
        printf("%d%c", *itea, itea == ans.end() - 1 ? '\n' : ' ');

//    char ccc = getchar(); ccc = getchar();
    return 0;
}