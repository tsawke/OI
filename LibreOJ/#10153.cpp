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
#include <tuple>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
vector<pair<int, int> /*toVertex, wealth*/ >vertex[1100000];
void ReadTree(const int, const int = 1);
void DescTree(const int);
int dp[110][110];
int n, q;
int Cal(int, int, int);
int main(){
	::n = read(), ::q = read();
    // ReadTree(::n);
    // DescTree(::n);

    for(int i = 1; i <= n - 1; ++i){
        int from = read(), to = read(), wealth = read();
        vertex[from].push_back(make_pair(to, wealth));
        vertex[to].push_back(make_pair(from, wealth));
    }

    printf("%d\n", Cal(1, q, -1));

    // for(int i = 1; i <= n; ++i)
    //     for(int j = 1; j <= q; ++j)
    //         printf("%d%c", dp[i][j], j == q ? '\n' : ' ');
    return 0;
}

int Cal(int root, int edgeN, int father){
    // printf("Now Cal (root=%d, edgeN=%d) subTreeNum=%d\n", root, edgeN, vertex[root].size());
    // sleep(1);
    if(vertex[root].size() == 1 || !edgeN)return 0;
    // printf("Do CAL\n");
    if(dp[root][edgeN])return dp[root][edgeN];
    int LC = vertex[root].at(0).first, LW = vertex[root].at(0).second;
    int RC = vertex[root].at(1).first, RW = vertex[root].at(1).second;
    if(LC == father)LC = vertex[root].at(2).first, LW = vertex[root].at(2).second;
    if(RC == father)RC = vertex[root].at(2).first, RW = vertex[root].at(2).second;
    // printf("    subtree not empty --- LC=%d, LW=%d, RC=%d, RW=%d\n", LC, LW, RC, RW);
    for(int i = 0; i <= edgeN; ++i){
        // printf("        Now is going to cal lCN=%d, rCN=%d\n", i - 1, edgeN - i - 1);
        if(!i)dp[root][edgeN] = max(dp[root][edgeN], Cal(RC, edgeN - 1, root) + RW);
        else if(i == edgeN)dp[root][edgeN] = max(dp[root][edgeN], Cal(LC, i - 1, root) + LW);
        else dp[root][edgeN] = max(dp[root][edgeN], Cal(LC, i - 1, root) + LW + Cal(RC, edgeN - i - 1, root) + RW);
        // printf("$$$   %d\n", Cal(LC, i - 1) + LW);
        // printf("        After cal lCN=%d, rCN=%d, dp[][]=%d\n", i - 1, edgeN - i - 1, dp[root][edgeN]);
    }
    return dp[root][edgeN];
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
/*
3 1
1 2 20
1 5 120
*/


//OLD
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
// using namespace std;
// typedef unsigned long long unll;
// typedef long long ll;
// template <typename T = int>
// inline T read(void);
// int n, q;
// // vector< pair<int, int>/*toVertex, wealth*/ >vertex[110];
// class Edge{
//     public:
//         int from;
//         int to;
//         int wealth;
//         const bool operator<(const Edge&) const;
//         Edge(int _from, int _to, int _wealth):from(_from), to(_to), wealth(_wealth){;}
// };
// vector<Edge>edge;
// priority_queue<int>ansQ;
// int dfsTree(int, int);
// int main(){
// 	n = read(), q = read();
//     for(int i = 1; i < n; ++i){
//         int from = read(), to = read(), wealth = read();
//         // vertex[from].push_back(make_pair(to, wealth));
//         // vertex[to].push_back(make_pair(from, wealth));
//         edge.push_back(Edge(from, to, wealth));
//     }
//     dfsTree(1, -1);


//     return 0;
// }
// int dfsTree(int root, int father){
//     int lowVertex(0);
//     int maxVertex(INT_MIN);
//     int lowT1(-1), lowT2(-1);
//     for(auto i : edge){
//         if((i.from == root && i.from != father) || (i.to == root && i.to != father)){
//             int from = i.from == root ? i.from : i.to;
//             int to = from == i.from ? i.to : i.from;
//             int lowT = dfsTree(to, root);
//             if(lowT1 == -1)lowT1 = lowT;
//             else lowT2 = lowT;
//             lowVertex += lowT;
//         }
//     }
//     int upVertex = 
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
// const bool Edge::operator<(const Edge& E) const{
//     return this->wealth > E.wealth;
// }