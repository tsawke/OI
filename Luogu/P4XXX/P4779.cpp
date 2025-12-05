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
int dis[110000];//distance
bool vis[110000];//default: false
int n, m, s;
vector< pair<int, int> /*toVertex, value*/ > vertex[110000];
priority_queue< pair<int, int>/*distance, vertex*/, vector< pair<int, int> >, greater< pair<int, int> > >vert;
void Dijk(void);
int main(){
    
	memset(dis, 0x3f, sizeof(dis));
	n = read(), m = read(), s = read();
	dis[s] = 0;
	for(int i = 1; i <= m; ++i){
		int from = read(), to = read(), value = read();
		vertex[from].push_back(pair<int, int>(to, value));
	}
    vert.push(pair<int, int>(dis[s], s));
	Dijk();
	
	for(int i = 1; i <= n; ++i)printf("%d%c", dis[i] != 0x3f3f3f3f ? dis[i] : 0x7fffffff, i == n ? '\n' : ' ');


    return 0;
}
void Dijk(void){
    while(!vert.empty()){
        int base;
        tie(ignore, base) = vert.top();
        vert.pop();
        if(vis[base])continue;
        vis[base] = true;
        for(auto i : vertex[base]){
            int to, value;
            tie(to, value) = i;
            if(dis[base] + value < dis[to]){
                dis[to] = dis[base] + value;
                if(!vis[to])vert.push(pair<int, int>(dis[to], to));
            }
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