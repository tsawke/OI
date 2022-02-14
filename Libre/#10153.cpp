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
vector< pair<int, int> /*toVertex, wealth*/ >vertex[110];
queue< tuple<int, int, int> >toBePush;
int outD[110];
int inD[110];
int dp[110][110];
int n, q;
int cal(int, int);
int main(){
	n = read(), q = read();
    inD[1] = 1;
    for(int i = 1; i < n; ++i){
        int from = read(), to = read(), wealth = read();
        // printf("No.%d  ready to push %d->%d, inDfrom=%d, inDto=%d\n", i, from, to, inD[from], inD[to]);sleep(2);
        if(inD[from] && !inD[to])vertex[from].push_back(make_pair(to, wealth)), ++inD[to];
        else if(!inD[from] && inD[to])vertex[to].push_back(make_pair(from, wealth)), ++inD[from];
        // else if(inD[from] && inD[to])
        else toBePush.push(tuple<int, int, int>(from, to, wealth));
        // edge.push_back(Edge(from, to, wealth));
        
    }
    while(!toBePush.empty()){
        auto values = toBePush.front();
        toBePush.pop(); 
        // printf("%d %d\n", get<0>(values), get<1>(values));sleep(1);                                                                                                                                    
        int from, to, wealth;
        tie(from, to, wealth) = values;
        if(inD[from] && !inD[to])vertex[from].push_back(make_pair(to, wealth)), ++inD[to];
        else if(!inD[from] && inD[to])vertex[to].push_back(make_pair(from, wealth)), ++inD[from];
        else toBePush.push(values);
    }
    for(int i = 1; i <= n; ++i){
        for(auto v : vertex[i]){
            printf("%d->%d     ", i, v.first);
        }if(!vertex[i].empty())printf("\n");
    }


    printf("ANS---%d\n", cal(1, q));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= q; ++j)
            printf("%d%c", dp[i][j], j == q ? '\n' : ' ');
    }
    return 0;
}
int cal(int root, int edgeN){
    printf("Now Cal (root=%d, edgeN=%d)\n", root, edgeN);
    if(vertex[root].empty())return 0;
    int LC = vertex[root].at(0).first, LW = vertex[root].at(0).second;
    int RC = vertex[root].at(1).first, RW = vertex[root].at(1).second;
    for(int i = 0; i <= edgeN; ++i){
        if(!i)dp[root][i] = max(dp[root][i], cal(RC, edgeN - 1) + RW);
        else if(i == edgeN)dp[root][i] = max(dp[root][i], cal(LC, i - 1) + LW);
        else dp[root][i] = max(dp[root][i], cal(LC, i - 1) + LW + cal(RC, edgeN - i - 1) + RW);
    }
    return dp[root][edgeN];
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