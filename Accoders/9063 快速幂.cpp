#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <queue>
#include <stack>
typedef long long ll;
typedef unsigned long long unll;
using namespace std;
int a, b, c;
int qPow(int, int, int);
int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", qPow(a, b, c));
	return 0;
}
int qPow(int a, int n, int mod) {
	int ret(1);
	while (n) {
		if (n & 1)ret = 1ll * ret * a % mod;
		n /= 2;
		a = 1ll * a * a % mod;
	}
	return ret;
}