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
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
inline unll readULL(void);
inline int read(void);
int a[110000]; 
int d[110000];
int main(){
	int n(read());
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		d[i] = a[i] - a[i - 1];
	}
/*	printf("d[] = ");
			for(int i = 1; i <= n; ++i)printf("%d ", d[i]);
			printf("\n");*/
	int m(read());
	for(int i = 1; i <= m; ++i){
		int flag(read());
		if(flag == 1){
			int s(read()), e(read()); int v(read());
			d[s] += v;
			d[e + 1] -= v;
/*			printf("d[] = ");
			for(int i = 1; i <= n; ++i)printf("%d ", d[i]);
			printf("\n");*/
		}
		if(flag == 2){
			int ans(0);
			int s(read()), e(read());
			for(int i = 1; i <= s; ++i)ans += d[i] * (e - s + 1);
			int nowN(e - s + 1);
			for(int i = s + 1; i <= e; ++i)ans += d[i] * (--nowN); 
			printf("%d\n", ans);
		}
	}
	
//    system("pause");
    return 0;
}
int getLen(int a_s, int a_e, int b_s, int b_e){
	//a in b
	if(a_e < b_s || a_s > b_e)return -1;
	if(b_s <= a_s && a_e <= b_e)return a_e - a_s + 1;
	if(a_e <= b_e)return a_e - b_s + 1;
	if(a_s >= b_s)return b_e - a_s + 1;
}
inline unll readULL(void){
	unll ret(0);
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
		ret *= flag;
	}
	return ret;
}
inline int read(void) {
	int ret(0);
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
		ret *= flag;
	}
	return ret;
}

