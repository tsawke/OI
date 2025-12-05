//TODO lower or upper?
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

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

vector< int > UnRise;
vector< int > UnReduce;

int main(){
	int temp;
    while(scanf("%d", &temp) != EOF && temp != -1){
        if(UnRise.empty() || UnRise.back() >= temp)UnRise.push_back(temp);
        else *upper_bound(UnRise.begin(), UnRise.end(), temp, greater<int>()) = temp;
        if(UnReduce.empty() || UnReduce.back() < temp)UnReduce.push_back(temp);
        else *lower_bound(UnReduce.begin(), UnReduce.end(), temp, less<int>()) = temp;
    }
    printf("%d\n%d\n", (int)UnRise.size(), (int)UnReduce.size());

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