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
#include <queue>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, m;
int x, y;
int dx[10] = {0,  -1, -2, -2, -1, 1, 2, 2, 1};
int dy[10] = {0,  -2, -1, 1, 2, -2, -1, 1, 2};
int ans[410][410];
bool vis[410][410];
queue< pair<int, int> >q;
void bfs(int);
int main(){
    for(int i = 0; i <= 400; ++i)for(int j = 0; j <= 400; ++j)ans[i][j] = -1;
    n = read(), m = read();
    x = read(), y = read();
    q.push(pair<int, int>(x, y));
	bfs(0);
	for(int i = 1; i <= n; ++i){
	    for(int j = 1; j <= m; ++j)
	        printf("%-5d", ans[i][j]);
	    printf("\n");
	}
    return 0;
}
void bfs(int steps){
	if(q.empty())return;
	int len = q.size();
    for(int i = 1; i <= len; ++i){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(x < 1 || x > n || y < 1 || y > m || vis[x][y])continue;
        vis[x][y] = true;
        ans[x][y] = steps;
        for(int i = 1; i <= 8; ++i)
        	q.push(pair<int, int>(x + dx[i], y + dy[i]));
    }
    if(!q.empty())bfs(steps + 1);
}
template <typename T = int>
inline T read(void)
{
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