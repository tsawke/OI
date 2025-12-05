#pragma warning(disable : 4996)
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
int T;
int a[110000];
int main() {
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)scanf("%d", a + i);
		for (int i = n; i >= 1; --i)
			if (a[i] == n)--n;
		printf("%d\n", n);
	}
	return 0;
}
