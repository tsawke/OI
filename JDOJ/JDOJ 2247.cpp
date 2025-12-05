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
vector<int>v[10];
int main(){
    int flag, tel;char ct;
    while(~scanf("%d%c%d", &flag,  &ct, &tel)){
        v[flag].push_back(tel);
    }
    for(int i = 1; i <= 10; ++i){
        for(int j = 0; j <= 2; ++j)
            printf("%d%c", v[j].size() >= i ? v[j].at(i - 1) : 0, j == 2 ? '\n' : ' ');
    }
    system("pause");
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
