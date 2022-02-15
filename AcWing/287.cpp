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
vector< pair<int, int> >vertex[210000];
void clearV(void);
int Cal(const int, int = 1);
void dfsByRoot(int, int, int *&);
void dfsChangeRoot(int, int, const int*&, int*&);
int T;
int main(){
	T = read();
    for(int t = 1; t <= T; ++t){
        clearV();
        int n = read();
        for(int i = 1; i <= n - 1; ++i){
            int from = read(), to = read(), wealth = read();
            vertex[from].push_back(make_pair(to, wealth));
            vertex[to].push_back(make_pair(from, wealth));
        }
        printf("%d\n", Cal(n, rand() % n + 1));//TODO root->rand() WA
    }
    return 0;
}
void dfsByRoot(int root, int father, int (&postF)[210000]){
    if(vertex[root].size() == 1 && father != -1)return;
    int postFlow(0);
    for(auto i : vertex[root]){
        if(i.first == father)continue;
        dfsByRoot(i.first, root, postF);
        postFlow += min(postF[i.first], i.second);
    }
    postF[root] = postFlow;
    return;
}
void dfsChangeRoot(int root, int father, const int (&postF)[210000], int (&flow)[210000]){
    // printf("Now Cal root=%d, father=%d\n", root, father);
    int Flow(postF[root]);
    if(father != -1){
        int fatherToRootFlow(INT_MAX);
        for(auto i : vertex[father])
            if(i.first == root){fatherToRootFlow = i.second; break;}
        // printf("FIND FLOW = %d\n", fatherToRootFlow);
        Flow += min(fatherToRootFlow, vertex[father].size() != 1 ? (flow[father] - fatherToRootFlow) : INT_MAX);
    }
    flow[root] = Flow;
    for(auto i : vertex[root])
        if(i.first != father)dfsChangeRoot(i.first, root, postF, flow);
}
void DescTree(const int n){
    for(int i = 1; i <= n; ++i){
        if(vertex[i].empty())continue;
        printf("%d => ", i);
        for(auto v : vertex[i]){
            printf("%d(%d) ", v.first, v.second);
        }printf("\n");
    }
}
int Cal(const int n, int root){
    int postF[210000];
    memset(postF, 0, sizeof(postF));
    for(int i = 1; i <= n; ++i){
        if(vertex[i].size() == 1)postF[i] = INT_MAX;
    }
    // DescTree(n);
    dfsByRoot(root, -1, postF);
    // for(int i = 1; i <= n; ++i){
    //     printf("%d%c", postF[i], i == n ? '\n' : ' ');
    // }
    int flow[210000];
    memset(flow, 0, sizeof(flow));
    for(int i = 1; i <= n; ++i)
        if(postF[i] == INT_MAX)postF[i] = 0;
    // for(int i = 1; i <= n; ++i){
    //     printf("%d%c", postF[i], i == n ? '\n' : ' ');
    // }
    dfsChangeRoot(root, -1, postF, flow);
    // for(int i = 1; i <= n; ++i){
    //     printf("%d%c", flow[i], i == n ? '\n' : ' ');
    // }
    int ansFLow(INT_MIN);
    for(int i = 1; i <= n; ++i)ansFLow = max(ansFLow, flow[i]);
    return ansFLow;
}
void clearV(void){
    for(int i = 1; i <= 201000; ++i)vertex[i].clear();
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