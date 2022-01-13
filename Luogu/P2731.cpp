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
int edgeAmt; //Edge Amount
int vertAmt(0); //Vertex Amount 
pair< vector< pair<int, bool> /*toVertex, visited*/ > , int /*vertex, degree*/>vertex[1100];
bool cmp_vec(pair<int, bool>, pair<int, bool>);
void dfs(int, int)
int main(){
	edgeAmt = read();
    for(int i = 1; i <= 500; ++i)vertex[i].second = 0;
    for(int i = 1; i <= edgeAmt; ++i){
        int from = read(), to = read();
        vertex[from].first.push_back(pair<int, bool>(to, false));
        vertex[to].first.push_back(pair<int, bool>(from, false));
        ++vertex[from].second;
        ++vertex[to].second;
        vertAmt = max(vertAmt, max(from, to));
    }
    for(int i = 1; i <= vertAmt; ++i)sort(vertex[i].first.begin(), vertex[i].first.end(), cmp);
    int root(1);
    for(int i = 2; i <= vertAmt; ++i)
        if(vertex[i].second & 1){root = i; break;}
    dfs(root, 1)


    return 0;
}
void dfs(int vertex, int steps){
    if(steps >= )
}
bool cmp_vec(pair<int, bool>a, pair<int, bool>b){
    return a.first < b.first;;
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