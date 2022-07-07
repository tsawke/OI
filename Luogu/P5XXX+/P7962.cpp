//C++11 - Template
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
#define MAX_CIR 1000000000
#define MUL_DOUBLE 1.0000000
#define logN(a, b) (double) log(double(b)) / log(double(a))
using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int N;
int MAX_DEEP;
ll a[11000];
double minD = __DBL_MAX__;
int Times(0);
void Cal(int, double);
void CalVari(double);
int main(){
	N = read();
	MAX_DEEP = floor(logN(N, MAX_CIR));
	ll sum(0ll);
    for(int i = 1; i <= N; ++i)a[i] = read<ll>(), sum += a[i];
	Cal(1, (double) sum * MUL_DOUBLE / N * MUL_DOUBLE);
	printf("%lld\n", (ll) (minD * N * N));
    return 0;
}
void Cal(int deep, double currentAver){
	// printf("Caling deep = %d, currentAver = %.5lf\n", deep, currentAver);
	if(deep * (N - 2) > MAX_DEEP)return;
	CalVari(currentAver);
	for(int currentN = 2; currentN <= N - 1; ++currentN){
		currentN = currentN > N ? 2 : currentN;
		ll temp = a[currentN];
		a[currentN] = (ll) a[currentN - 1] + a[currentN + 1] - temp;
		Cal(deep + 1, currentAver + (double)(a[currentN] - temp) * MUL_DOUBLE / (N * MUL_DOUBLE) );
		a[currentN] = temp;
	}
	return;
}
void CalVari(double Aver){
	double ret(0.0000000);
	for(int i = 1; i <= N; ++i)
		ret += (double)( (a[i] * MUL_DOUBLE - Aver) * (a[i] * MUL_DOUBLE - Aver) * MUL_DOUBLE);
	ret /= N * MUL_DOUBLE;
	minD = min(minD, ret);
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