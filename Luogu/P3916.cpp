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
int maxVert[110000];
queue<int>vert;
void dfs(int, int);
int main(){
	// memset(maxVert, 0x80, sizeof(maxVert));
	n = read(), m = read();                                                                                                                     
	for(int i = 1; i <= m; ++i){
		int from = read(), to = read(), value(1);
		vertex[to].push_back(CP_NN(from, value));
	}
	for(int i = n; i >= 1; --i)dfs(i, i);
	for(int i = 1; i <= n; ++i)printf("%d%c", maxVert[i], i == n ? '\n' : ' ');
    return 0;
}

void dfs(int vertex, int rootVert){
	if(used[vertex])return;
	used[vertex] = true;
	maxVert[vertex] = rootVert;
	for(auto i : ::vertex[vertex]){
		int to;
		tie(to, ignore) = i;
		if(!used[to])dfs(to, rootVert);
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