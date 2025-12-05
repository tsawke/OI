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
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int n, money;
int price[110], priority[110];
int dp[510][110];
int main(){
	n = read(), money = read();
    int basePrice(INT_MAX);
	int totalPrice(0);
	for(int i = 1; i <= n; ++i)
		price[i] = read(), 
		priority[i] = read(), 
		basePrice = min(basePrice, price[i]),
		totalPrice += price[i];
	for(int i = 1; i <= n; ++i)
		price[i] -= basePrice,
		++price[i];
	totalPrice -= basePrice * n;
	totalPrice += n;
	--basePrice;
	for(int i = 1; i <= n; ++i)
		for(int j = totalPrice; j >= price[i]; --j)
			for(int k = n; k >= 1; --k)
				if(k * basePrice + j <= money)dp[j][k] = max(dp[j][k], dp[j - price[i]][k - 1] + priority[i]);
	// printf("Base Price = %d\nTotal Price = %d\n", basePrice, totalPrice);
	// printf("All Price:");for(int i = 1; i <= n; ++i)printf("%d ", price[i]);puts("");
	// for(int i = 1; i <= totalPrice; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", dp[i][j], j == n ? '\n' : ' ');
    int ans(INT_MIN);
	for(int i = 1; i <= totalPrice; ++i)for(int j = 1; j <= n; ++j)ans = max(ans, dp[i][j]);
	printf("%d\n", ans);
    return 0;
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