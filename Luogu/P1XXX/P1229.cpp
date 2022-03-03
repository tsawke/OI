//C++11
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
#include <unistd.h>
#include <functional>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
string preOrder, postOrder;

int main(){
	cin>>preOrder>>postOrder;
    int sum(0);
    for(unsigned int i = 0; i < preOrder.size() - 1; ++i)
        for(unsigned int j = 1; j < postOrder.size(); ++j)
            if(preOrder.at(i) == postOrder.at(j) && preOrder.at(i + 1) == postOrder.at(j - 1))++sum;
    printf("%d\n", 1 << sum);
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