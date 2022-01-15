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
int dis[110000];//distance
bool vis[110000];//default: false
int n, m, s;
vector< pair<int, int> /*toVertex, value*/ > vertex[110000];
void Dijk(void);
int main(){
	memset(dis, 0x7f, sizeof(dis));
	n = read(), m = read(), s = read();
	dis[s] = 0;
	for(int i = 1; i <= m; ++i){
		int from = read(), to = read(), value = read();
		vertex[from].push_back(pair<int, int>(to, value));
	}
	Dijk();
	
	for(int i = 1; i <= n; ++i)printf("%d%c", dis[i] != 0x7f7f7f7f ? dis[i] : 0x7fffffff, i == n ? '\n' : ' ');


    return 0;
}
void Dijk(void){
	for(int vert = 1; vert <= n; ++vert){
		int base(0), minD(INT_MAX);
		for(int i = 1; i <= n; ++i)
			if(!vis[i] && dis[i] < minD)
				base = i, minD = dis[i];
		vis[base] = true;
		for(auto i : vertex[base]){
			int to, value;
			tie(to, value) = i;
			dis[to] = min(dis[to], dis[base] + value);
		}
	}
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