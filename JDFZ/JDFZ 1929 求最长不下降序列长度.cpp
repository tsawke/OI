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
#include<iterator>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
int a[11000];
int main(){
    int n(read());
	for(int i = 1; i <= n; ++i)a[i] = read();
    for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}
    system("pause");
    return 0;
}
template <typename T>
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