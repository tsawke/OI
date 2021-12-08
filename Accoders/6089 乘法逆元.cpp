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
ll n, p;
ll inv[1100000];
int main() {
	scanf("%lld%lld", &n, &p); inv[1] = 1;
	for (int i = 2; i <= n; ++i)inv[i] = ll(((-p / i) * inv[p % i] % p + p) % p);
	for (int i = 1; i <= n; ++i)printf("%lld\n", inv[i]);
	return 0;
}