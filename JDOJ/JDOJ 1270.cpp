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
#include <queue>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
priority_queue<int, vector<int>, greater<int> >q;
int value(0);
int main(){
	int n = read<int>();
    for(int i = 1; i <= n; ++i)q.push(read<int>());
    for(int i = 1; i <= n - 1; ++i){
        value += q.top(); int temp = q.top(); q.pop();
        value += q.top(); temp += q.top(); q.pop();
        q.push(temp);
    }
    printf("%d\n", value);
    return 0;
}

template <typename T>
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