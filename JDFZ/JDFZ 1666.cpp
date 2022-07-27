//C++98
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

#define int ll

template <typename T>
inline T read(void);

int f[12][2100];//i行 铺法为j
bool flag[2100][2100];//from i to j
void dfs(int, int, int, int);
int W, H;
void Init(void);
signed main(){
	W = read<int>(), H = read<int>();
	Init();
	for(int i = 1; i <= W + 1; ++i){
		for(int j = 0; j <= (1 << H) - 1; ++j)
			dfs(i, 0, j, 0);
	}
	// printf("F:\n");
	// for(int i = 1; i <= W; ++i){
	// 	for(int j = 0; j <= H; ++j){
	// 		printf("%d%c", f[i][j], j == H ? '\n' : ' ');
	// 	}
	// }
	// printf("flag:\n");
	// for(int i = 0; i <= W; ++i){
	// 	for(int j = 0; j <= H; ++j){
	// 		printf("%d%c", flag[i][j], j == H ? '\n' : ' ');
	// 	}
	// }
	printf("%lld\n", f[W + 1][0]);
    return 0;
}
void Init(void){
	f[1][0] = 1;
	// for(int i = 0; i <= 2010; ++i){
	// 	for(int j = 0; j <= 2010; ++j){
	// 		bool flag(true);
	// 		int temp = i ^ j;
	// 		int n0(0);
	// 		for(int k = 0; k <= H - 1; ++k){
	// 			if(!((temp >> k) & 1)){
	// 				if(n0 & 1){
	// 					flag = false;
	// 					break;
	// 				}
	// 			}
	// 			else
	// 				++n0;
	// 			if(k == H - 1 && n0 & 1){
	// 				flag = false;
	// 				break;
	// 			}
	// 		}
	// 		if(i & j)flag = false;
	// 		::flag[i][j] = flag;
	// 	}
	// }
	// for(int i = 0; i <= 2010; ++i){
	// 	bool flag(true);
	// 	int n0(0);
	// 	for(int k = 0; k <= H - 1; ++k){
	// 		if(!((i >> k) & 1)){
	// 			// printf("i >> k is 1, i = %d\n", i);
	// 			if(n0 & 1){
	// 				flag = false;
	// 				break;
	// 			}
	// 		}
	// 		else
	// 			++n0;
	// 		if(k == H - 1 && n0 & 1){
	// 			flag = false;
	// 			break;
	// 		}
	// 	}
	// 	::f[1][i] = flag;
	// }
}
void dfs(int line, int row, int current, int next){
	if(row >= H){
		// if(flag[current][next]){
			f[line][next] += f[line - 1][current];
		// }
		return;
	}
	if(current & (1 << row)){
			dfs(line, row + 1, current, next);
	}
	else{
		if(row + 1 <= H - 1 && !(current & (1 << (row + 1)))){
			dfs(line, row + 2, current/* | ((1 << row) + (1 << (row + 1)))*/, next);
		}
		dfs(line, row + 1, current/* | (1 << row)*/, next | (1 << row));
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