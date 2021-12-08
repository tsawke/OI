#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
using namespace std;
int n, k;
bool used[110000];
long long a[110000];
long long ans(0);
void calculate(long long, int, int);
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	calculate(-1, 1, 1);
	ans %= 998244353;
	printf("%lld\n", ans);
	return 0;
}
void calculate(long long nowAns, int deep, int lastChoose) {
	if (deep > k) {
		//		printf("\nNOWANS = %d\n", nowAns);
		ans += nowAns;
		ans %= 998244353;
		return;
	}
	for (int i = lastChoose; i <= n; ++i) {
		if (!used[i]) {
			//			printf("\n%d has been chosen\n", i);
			if (nowAns == -1)nowAns = a[i];
			else nowAns ^= a[i];
			nowAns %= 998244353;
			used[i] = true;
			calculate(nowAns, deep + 1, i);
			if (nowAns == (a[i] % 998244353))nowAns = -1;
			else nowAns ^= a[i];
			nowAns %= 998244353;
			used[i] = false;
		}
	}
	return;
}