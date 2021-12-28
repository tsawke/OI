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
int memory[110][110];
int dx[10] = {0,  -1, 1, 0, 0};
int dy[10] = {0,  0, 0, -1, 1};
void bfs(int);
//queue: pos int x, int y, bool use_magic, int now_coin, int now_color
queue< tuple<int, int, bool, int, int> >q;
int chessSize, n;
int chess[110][110];
bool vis[110][110];
vector< pair<int, int> >update_vis;
int minCoin(INT_MAX);
void bfs(void);
int main(){
    // memset(memory, 0x3f, sizeof(memory));
    for(int i = 1; i <= 100; ++i)for(int j = 1; j <= 100; ++j)memory[i][j] = INT_MAX;
    chessSize = read(), n = read();
    for(int i = 1; i <= n; ++i){
        int x = read(), y = read(), flag = read();
        chess[x][y] = flag ? 1 : -1;//1:yellow -1:red
    }
    // printf("Print Chess[][]:\n");
    // for(int i = 1; i <= chessSize; ++i){
    //     for(int j = 1; j <= chessSize; ++j)
    //         printf("%d%c", chess[i][j], j == chessSize ? '\n' : ' ');
    // }
    // printf("\n");
    q.push(tuple<int, int, bool, int, int>(1, 1, false, 0, chess[1][1]));
    bfs();
    printf("%d\n", minCoin == INT_MAX ? -1 : minCoin);
    return 0;
}
void bfs(void){
	int len = q.size();
    for(int i = 1; i <= len; ++i){
        int x, y, nowCoin, nowColor;
        bool used;
        tie(x, y, used, nowCoin, nowColor) = q.front();
        q.pop();
        // if(memory[x][y] != INT_MAX){
        //     minCoin = min(minCoin, nowCoin + memory[x][y]);
        //     continue;
        // }
        if(vis[x][y] || x < 1 || x > chessSize || y < 1 || y > chessSize)continue;
        if(x == chessSize && y == chessSize){
            minCoin = min(minCoin, nowCoin);
            memory[x][y] = min(memory[x][y], nowCoin);
            continue;
        }
        update_vis.push_back(pair<int, int>(x, y));
        // vis[x][y] = true;
        for(int j = 1; j <= 4; ++j){
            int addCoin(0);
            int nowColor_ = nowColor;
            int toX = x + dx[j], toY = y + dy[j];
            // printf("#After Check Range Values In bfs: from%d,%d to%d,%d used=%d nowC=%d lastCol=%d\n",
            //     x, y, toX, toY, used, nowCoin, nowColor);
            if(toX < 1 || toX > chessSize || toY < 1 || toY > chessSize || vis[toX][toY])continue;
            nowColor_ = chess[x + dx[j]][y + dy[j]];
            if(nowColor_ && used)used = false;
            if(!nowColor_){
                nowColor_ = chess[x][y];
                addCoin += 2;
                used = true;
            }
            if(nowColor != nowColor_)++addCoin;
            // if(!chess[x + dx[i]][y + dy[i]]){
            //     chess[x + dx[i]][y + dy[i]] = chess[x][y];
            //     used = true;
            //     addCoin += 2;
            // }
            // printf("Find Values In bfs: from%d,%d to%d,%d used=%d nowC=%d addC=%d lastCol=%d nowCol=%d\n",
            //     x, y, toX, toY, used, nowCoin, addCoin, nowColor, nowColor_);
            q.push(tuple<int, int, bool, int, int>(toX, toY, used, nowCoin + addCoin, nowColor_));
        }
    }
    for(auto i : update_vis){
        int x, y;
        tie(x, y) = i;
        vis[x][y] = true;
    }update_vis.clear();

	if(!q.empty())bfs();
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
//TODO