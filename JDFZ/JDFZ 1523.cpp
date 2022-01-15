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
template <typename T>
inline T read(void);
int D[110][110];
int times[110][110];
int main(){
	memset(D, 0x3f, sizeof(D));
	// for(int i = 1; i <= 101; ++i)for(int j = 1; j <= 101; ++j)D[i][j] = 100000;
	// for(int i = 1; i <= 101; ++i)for(int j = 1; j <= 101; ++j)times[i][j] = 1;
	int n = read<int>(), m = read<int>();
	for(int i = 1; i <= m; ++i){
		int from = read<int>(), to = read<int>();
		D[from][to] = D[to][from] = 1;
	}
	
	for(int i = 1; i <= n; ++i)D[i][i] = 0;
	for(int tempV = 1; tempV <= n; ++tempV)
		for(int fromV = 1; fromV <= n; ++fromV)
			for(int toV = 1; toV <= n; ++toV)
				if(D[fromV][tempV] + D[tempV][toV] < D[fromV][toV]){
					// times[fromV][toV] = times[toV][fromV] = 1;
					D[fromV][toV] = D[fromV][tempV] + D[tempV][toV];}
				// }else if(D[fromV][tempV] + D[tempV][toV] == D[fromV][toV]){
				// 	++times[fromV][toV];
				// 	++times[toV][fromV];
				// }
				// D[toV][fromV] = D[fromV][toV] = min(D[fromV][toV], D[fromV][tempV] + D[tempV][toV]);
	int qAmt = read<int>();
	for(int i = 1; i <= qAmt; ++i){
		int from = read<int>(), to = read<int>();
		// int ans(D[from][to] + 1);
		int ans(2);//from&to
		for(int i = 1; i <= n; ++i){
			if(i != from && i != to && D[from][i] + D[i][to] == D[from][to])++ans;
		}
		printf("%d\n", ans); 
	}
    return 0;
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