//C++11
//TODO TLE
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
// #define SUBMIT
#ifndef SUBMIT
#include <sys/time.h>
#endif
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
vector< pair<int, int> >vertex[210000];
void clearV(int);
int Cal(const int, int = 1);
void dfsByRoot(int, int, int *&);
void dfsChangeRoot(int, int, const int*&, int*&);
int T;
int main(){
#ifndef SUBMIT
    freopen("./287-data.in", "r", stdin);
#endif
    vertex[1].reserve(110000);
    for(int i = 2; i <= 110000; ++i)vertex[i].reserve(2);
	T = read();
    for(int t = 1; t <= T; ++t){
        int n = read();
        if(T != 1)clearV(n);
        for(int i = 1; i <= n - 1; ++i){
            int from = read(), to = read(), wealth = read();
            vertex[from].push_back(make_pair(to, wealth));
            vertex[to].push_back(make_pair(from, wealth));
        }
        printf("Input Success\n");
        printf("%d\n", Cal(n, rand() % n + 1));
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
        // if(root == 7)printf("7****** pos[i.first]=%d  i.sec=%d posFlow=%d i.first=%d\n", postF[i.first], i.second, postFlow, i.first);
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
        // if(fatherToRootFlow == INT_MAX)printf("ERROR!!!!!!!!!!!!!!!!\n\n\n");
        // printf("FIND fathertorootFLOW = %d (%d => %d) Flow = %d\n", fatherToRootFlow, father, root, Flow);
        Flow += min(fatherToRootFlow, vertex[father].size() != 1 ? (flow[father] - min(fatherToRootFlow, postF[root])) : INT_MAX);
        // printf("flow[father]=%d, postF[father]=%d]\n", flow[father], postF[father]);
        // printf("After Flow = %d\n", Flow);
    }
    // else{
    //     printf("father is -1 root=%d", root);
    // }
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
    // printf("ROOT-%d\n", root);
    int postF[210000];
    // memset(postF, 0, sizeof(postF));
    // for(int i = 1; i <= n; ++i)postF = 0;
#ifndef SUBMIT
    timeval t1, t2, t3;
    double timeUse1, timeUse2;
    gettimeofday(&t1, NULL);
#endif
    for(int i = 1; i <= n; ++i){
        if(vertex[i].size() == 1 && i != root)postF[i] = INT_MAX;
        else postF[i] = 0;
    }
    
    DescTree(n);
    dfsByRoot(root, -1, postF);
    // for(int i = 1; i <= n; ++i){
    //     printf("%d#%d%c", i, postF[i], i == n ? '\n' : ' ');
    // }
    printf("dfsByRoot Success\n");
#ifndef SUBMIT
    gettimeofday(&t2, NULL);
#endif
    int flow[210000];
    // memset(flow, 0, sizeof(flow));
    for(int i = 1; i <= n; ++i){
        if(postF[i] == INT_MAX)postF[i] = 0;
        flow[i] = 0;
    }
    // for(int i = 1; i <= n; ++i){
    //     printf("%d#%d%c", i, postF[i], i == n ? '\n' : ' ');
    // }
    dfsChangeRoot(root, -1, postF, flow);
    printf("dfsChangeRoot Success\n");
#ifndef SUBMIT
    gettimeofday(&t3, NULL);

    timeUse1 = (t2.tv_sec - t1.tv_sec) + double((t2.tv_usec - t1.tv_usec) / 1000000.0);
    timeUse2 = (t3.tv_sec - t2.tv_sec) + double((t3.tv_usec - t2.tv_usec) / 1000000.0);

    printf("dfsByRoot use Time --- %.6f\n", timeUse1);
    printf("dfsChangeRoot use Time --- %.6f\n", timeUse2);
#endif
    // for(int i = 1; i <= n; ++i){
    //     printf("%d#%d%c", i, flow[i], i == n ? '\n' : ' ');
    // }
    int ansFLow(INT_MIN);
    for(int i = 1; i <= n; ++i)ansFLow = max(ansFLow, flow[i]);
    return ansFLow;
}
void clearV(int n){
    for(int i = 1; i <= n; ++i)vertex[i].clear();
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