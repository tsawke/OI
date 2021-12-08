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
ll a, b;
ll mod;
void exgcd(ll, ll&, ll, ll&);
int main() {
	scanf("%lld%lld", &a, &b);
	mod = b;
	ll x, y;
	exgcd(a, x, b, y);
	printf("%lld\n", (x % mod + mod) % mod);
	return 0;
}
void exgcd(ll a, ll& x, ll b, ll& y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, x, a % b, y);
	ll temp = x;
	x = y;
	y = (temp - (a / b) * y % mod + mod) % mod;
}