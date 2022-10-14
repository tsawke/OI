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
template <typename T = int>
inline T read(void);
int a[110000];
int sa[110000];
struct Interval{
	int s, e;
	int v;
	Interval(int s, int e, int v){
		this -> s = s;
		this -> e = e;
		this -> v = v;
	}
};
vector<Interval>operation;
int getLen(int, int, int, int);
int main(){
	int n(read());
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		sa[i] = sa[i - 1] + a[i];
	}
	int m(read());
	for(int i = 1; i <= m; ++i){
		int flag(read());
		if(flag == 1){
//			a[read()] = read();
			int s(read()), e(read()); int v(read());
//			printf("Input:: value = %d\n", v);
			Interval inter(s, e, v);
			operation.push_back(inter);
		}
		if(flag == 2){
			ll ans(0);
			int s(read()), e(read());
			ans += (sa[e] - sa[s] + a[s]);
//			for(int i = s; i <= e; ++i){
//				ans += a[i];
				for(vector<Interval>::iterator itea = operation.begin(); itea != operation.end(); ++itea){
//					printf("Now Itea = %d, ans = %d nowValue = %d\n", itea, ans, (*itea).v);
					int flag(getLen((*itea).s, (*itea).e, s, e));
//					printf("*****Len = %d\n", flag);
					if(flag != -1){
						ans += flag * (*itea).v;
					}
//					if((*itea).s <= i && i <= (*itea).e) ans += (*itea).v;
				}
//			}
			printf("%lld\n", ans);
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
}template <typename T = int>
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