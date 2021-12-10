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
template <typename T = int>
inline T read(void);
int a[11000];
vector<int>dp;
int main(){
    int n = read();
	for(int i = 1; i <= n; ++i)a[i] = read();
    for(int i = 1; i <= n; ++i){
		if(dp.empty() || a[i] >= *(dp.end() - 1))dp.push_back(a[i]);
		else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
	}
	printf("%d\n", dp.size());
    pause();
    return 0;
}
template <typename T = int>
inline T read(void){
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