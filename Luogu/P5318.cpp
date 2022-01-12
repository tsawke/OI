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
#define CP_NN(a, b) pair<int, int>(a, b)//Create Pair<N, N>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, m;
vector< pair<int, int>/*to, value*/ >vertex[11000];
bool used[11000];
bool cmp(pair<int, int>, pair<int, int>);
void dfs(int);
void bfs(int);
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
	dfs(1);
	bfs(1);

    return 0;
}
void dfs(int vertex){
	if()
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