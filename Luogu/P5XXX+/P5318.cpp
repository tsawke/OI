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
#define CP_NN(a, b) pair<int, int>(a, b)//Create Pair<N, N>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, m;
vector< pair<int, int>/*to, value*/ >vertex[110000];
bool used[110000];
queue<int>vert;
bool cmp(pair<int, int>, pair<int, int>);
void dfs(int);
void bfs(void);
// int head[11000];
// //toVertex value nextEdge
// tuple<int, int, int>edge[110000];
int main(){
	n = read(), m = read();
    // int cnt(0);
    // for(int i = 1; i <= m; ++i){
    //     int from = read(), to = read(), value(1);
    //     edge[++cnt] = tuple<int, int, int>(to, value, head[from]);
    //     head[from] = cnt;
    // }                                                                                                                       
	for(int i = 1; i <= m; ++i){
		int from = read(), to = read(), value(1);
		vertex[from].push_back(CP_NN(to, value));
	}
	for(int i = 1; i <= n; ++i)sort(vertex[i].begin(), vertex[i].end(), cmp);
	memset(used, 0, sizeof(used));
	dfs(1);
	printf("\n");
	memset(used, 0, sizeof(used));
	vert.push(1);
	used[1] = true;
	bfs();
	printf("\n");
    return 0;
}
void bfs(void){
	int len = vert.size();
	for(int c = 1; c <= len; ++c){
		int t = vert.front();
		vert.pop();
		printf("%d ", t);
		for(auto i : ::vertex[t]){
			int to;
			tie(to, ignore) = i;
			if(!used[to]){
				used[to] = true;
				vert.push(to);
			}
		}
	}
	if(!vert.empty())bfs();
}
void dfs(int vertex){
	printf("%d ", vertex);
	used[vertex] = true;
	for(auto i : ::vertex[vertex]){
		int to;
		tie(to, ignore) = i;
		if(!used[to])dfs(to);
	}
}
bool cmp(pair<int, int>a, pair<int, int>b){
	return a.first < b.first;
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