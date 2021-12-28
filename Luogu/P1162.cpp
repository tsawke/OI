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
#include <functional>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n;
int a[50][50];
bool vis[50][50];
int dx[10] = {0, -1, 1, 0, 0};
int dy[10] = {0, 0, 0, -1, 1};
vector< pair<int, int> >pos;
void dfs(int, int, bool);
int main(){
	n = read();
	for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)a[i][j] = read();
	for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j){
	    if(!vis[i][j] && !a[i][j])dfs(i, j, false);
	    pos.clear();
	   // printf("Now Search x%d y%d\n", i, j);
	   // for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
	}
	for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
    return 0;
}
void dfs(int x, int y, bool have_border){
    bool ret = have_border;
    // printf("Now DFS x:%d, y:%d border=%d\n", x, y, ret);
    if(vis[x][y] || a[x][y] == 1 || x < 1 || x > n || y < 1 || y > n)return;
    vis[x][y] = true;
    // printf("These values is legal\n");
    if(x == 1 || x == n || y == 1 || y == n){ret = true;}
    //if have border: default 0
    if(ret){
        for(auto i : pos){
            int tx, ty;
            tie(tx, ty) = i;
            a[tx][ty] = 0;
        }
        pos.clear();
    }else{
        a[x][y] = 2;
        pos.push_back(pair<int, int>(x, y));
    }
    for(int i = 1; i <= 4; ++i)
        dfs(x + dx[i], y + dy[i], ret);
}
template <typename T = int>
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