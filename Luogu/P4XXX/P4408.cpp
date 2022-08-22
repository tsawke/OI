//C++11
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
#include <stack>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, m;
vector<pair<int, int> /*toVertex, wealth*/ >vertex[210000];
bool vis[210000];
unll dist[5][210000];
queue< int >vert;
pair<int, unll> bfs(int, int);
void Init(int, int);
int main(){
	n = read(), m = read();
    for(int i = 1; i <= m; ++i){
        int from = read(), to = read(), wealth = read();
        vertex[from].push_back(make_pair(to, wealth));
        vertex[to].push_back(make_pair(from, wealth));
    }
    int source = rand() % n + 1;
    int start, end;
    unll distAB;
    Init(1, source);
    tie(start, ignore) = bfs(1, source);
    Init(2, start);
    tie(end, distAB) = bfs(2, start);
    Init(3, end);
    tie(ignore, ignore) = bfs(3, end);
    unll distC_AB(0ull);
    for(int posC = 1; posC <= n; ++posC){
        distC_AB = max(distC_AB, min(dist[2][posC], dist[3][posC]));
    }
    unll distance_ = distC_AB + distAB;
    // printf("Source=%d,  Start=%d,  End=%d\n", source, start, end);
    // for(int k = 1; k <= 3; ++k){
    //     printf("DIST %d:\n", k);
    //     for(int i = 1; i <= n; ++i){
    //         printf("%llu%c", dist[k][i], i == n ? '\n' : ' ');
    //     }printf("\n");
    // }printf("DistBC=%llu, DistA_BC=%llu\n", distAB, distC_AB);
    printf("%llu\n", distance_);
    return 0;
}
void Init(int arrayTag, int source){
    memset(vis, false, sizeof(vis));
    vis[source] = true;
    memset(dist[arrayTag], 0, sizeof(dist[arrayTag]));
    vert.push(source);
}
pair<int, unll> bfs(int arrayTag, int root){
    int farthest(root);
    unll farthestDist(0ull);
    int steps = -1;
    while(!vert.empty()){
        ++steps;
        queue<int>vertmp;
        while(!vert.empty()){
            vertmp.push(vert.front());
            vert.pop();
        }
        while(!vertmp.empty()){
            int vertp = vertmp.front();
            vertmp.pop();
            
            for(auto i : vertex[vertp]){
                if(vis[i.first])continue;
                vis[i.first] = true;
                dist[arrayTag][i.first] = unll(dist[arrayTag][vertp]) + unll(i.second);
                vert.push(i.first);
                if(dist[arrayTag][i.first] > farthestDist)farthest = i.first, farthestDist = dist[arrayTag][i.first];
            }
        }
    }
    return make_pair(farthest, farthestDist);
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