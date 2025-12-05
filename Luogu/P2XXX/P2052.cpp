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
int n;
unll ans(0ull);
vector<pair<int, int> /*toVertex, wealth*/ >vertex[1100000];
void ReadTree(const int, const int = 1);
void DescTree(const int);
int dfs(int = 1, int = -1);
int main(){
	ReadTree(::n = read());
    // DescTree(::n);
    dfs();
    printf("%llu\n", ans);
    return 0;
}
int dfs(int root, int father){//Return subtree based on root
    if(vertex[root].empty())return 1;
    int postVerts(0);
    for(auto i : vertex[root]){
        if(i.first == father)continue;
        int postVert = dfs(i.first, root);
        postVerts += postVert;
        ans += abs(::n - 2ll * postVert) * i.second;
        // printf("In DFS(root=%d) => postV=%d ans=%llu\n", root, postVert, ans);
    }
    // printf("After DFS(root=%d) => postVs=%d ret=+1\n", root, postVerts);
    return postVerts + 1;
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
void ReadTree(const int n, const int root){
    int from, to, wealth;
    for(int i = 1; i <= n - 1; ++i){
        from = read(), to = read(), wealth = read();
        vertex[from].push_back(make_pair(to, wealth));
        vertex[to].push_back(make_pair(from, wealth));
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

// //incorrect
// //C++11
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #include <cstdlib>
// #include <cmath>
// #include <vector>
// #include <climits>
// #include <iostream>
// #include <string>
// #include <map>
// #include <unistd.h>
// #include <functional>
// #include <queue>
// #include <stack>
// using namespace std;
// typedef unsigned long long unll;
// typedef long long ll;
// template <typename T = int>
// inline T read(void);
// int n;
// unll ans(0ull);
// vector<pair<int, int> /*toVertex, wealth*/ >vertex[1100000];
// void ReadTree(const int, const int = 1);
// void DescTree(const int);
// int dfs(int = 1);
// int main(){
// 	ReadTree(::n = read());
//     // DescTree(::n);
//     dfs();
//     printf("%llu\n", ans);
//     return 0;
// }
// int dfs(int root){//Return subtree based on root
//     if(vertex[root].empty())return 1;
//     int postVerts(0);
//     for(auto i : vertex[root]){
//         int postVert = dfs(i.first);
//         postVerts += postVert;
//         ans += unll(abs(::n - 2ll * postVert)) * unll(i.second);
//         // printf("In DFS(root=%d) => postV=%d ans=%llu\n", root, postVert, ans);
//     }
//     // printf("After DFS(root=%d) => postVs=%d ret=+1\n", root, postVerts);
//     return postVerts + 1;
// }
// void DescTree(const int n){
//     for(int i = 1; i <= n; ++i){
//         if(vertex[i].empty())continue;
//         printf("%d => ", i);
//         for(auto v : vertex[i]){
//             printf("%d(%d) ", v.first, v.second);
//         }printf("\n");
//     }
// }
// void ReadTree(const int n, const int root){
//     queue< tuple<int, int, int> /*fromVertex, toVertex, wealth*/ >values;
//     bool inDegree[n + 10];
//     memset(inDegree, 0, sizeof(inDegree));
//     inDegree[root] = 1;
//     int from, to, wealth;
//     for(int i = 1; i <= n - 1; ++i){
//         from = read(), to = read(), wealth = read();
//         if(inDegree[from] && !inDegree[to])vertex[from].push_back(make_pair(to, wealth)), inDegree[to] = 1;
//         else if(!inDegree[from] && inDegree[to])vertex[to].push_back(make_pair(from, wealth)), inDegree[from] = 1;
//         else values.push(make_tuple(from, to, wealth));
//     }
//     while(!values.empty()){
//         tie(from, to, wealth) = values.front();
//         values.pop();
//         if(inDegree[from] && !inDegree[to])vertex[from].push_back(make_pair(to, wealth)), inDegree[to] = 1;
//         else if(!inDegree[from] && inDegree[to])vertex[to].push_back(make_pair(from, wealth)), inDegree[from] = 1;
//         else values.push(make_tuple(from, to, wealth));
//     }
// }
// template <typename T = int>
// inline T read(void)
// {
// 	T ret(0);
// 	short flag(1);
// 	char c = getchar();
// 	while (c < '0' || c > '9') {
// 		if (c == '-')flag = -1;
// 		c = getchar();
// 	}
// 	while (c >= '0' && c <= '9') {
// 		ret *= 10, ret += (c - '0');
// 		c = getchar();
//     }
//     ret *= flag;
// 	return ret;
// }