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
#include <bitset>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int a[10];
int weight[10] = {0, 1, 2, 3, 5, 10, 20};
bitset<11000>num;
void cal(int, int);
int main(){
	for(int i = 1; i <= 6; ++i)a[i] = read();
    cal(1, 0);
    if(num[0])num[0] = false;
    printf("Total=%d\n", (int)num.count());
    return 0;
}//TODO
void cal(int root, int value){
    // if(root == 7){
    //     num[value] = true;
    //     return;
    // }
    for(int i = 0; i <= a[root]; ++i){
        if(root == 6){
            num[value + weight[root] * i] = true;
        }
        else
            cal(root + 1, value + weight[root] * i);
    }
    return;
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