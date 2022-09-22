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
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
void dfs(int, const int&);
vector<int>ans;
bool vis[110];
int main(){
    int n = read<int>();
    dfs(0, n);
    pause();
    return 0;
}
void dfs(int deep, const int& depth){
//    if(deep)printf("%d%c", deep, deep == depth ? '\n' : ' ');
    if(deep == depth){
        for(int i = 1; i <= depth; ++i)printf("%d%c", ans.at(i - 1), i == depth ? '\n' : ' ');
        return;
    }
    for(int i = 1; i <= depth; ++i){
        if(!vis[i]){
            vis[i] = true;
            ans.push_back(i);
            dfs(deep + 1, depth);
            ans.pop_back();
            vis[i] = false;
        }
    }
}
template <typename T>
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