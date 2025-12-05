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
uint n;
uint size;
deque< pair<int, int> >deqMax;
deque< pair<int, int> >deqMin;
vector< int >ansMax;
int main(){
    n = read<uint>(), size = read<uint>();
    // printf("%u, %u\n", n, size);sleep(5);
	for(uint i = 1; i <= n; ++i){
        int value = read();
        if(!deqMax.empty() && i - (*deqMax.begin()).first >= size)deqMax.pop_front();
        if(!deqMin.empty() && i - (*deqMin.begin()).first >= size)deqMin.pop_front();
        while(!deqMax.empty() && (*(deqMax.end() - 1)).second < value)deqMax.pop_back();
        while(!deqMin.empty() && (*(deqMin.end() - 1)).second > value)deqMin.pop_back();
        deqMax.push_back(make_pair(i, value));
        deqMin.push_back(make_pair(i, value));
        if(i >= size)printf("%d%c", (*deqMin.begin()).second, i == n ? '\n' : ' '),
        // if(i >= size)*(ansMax.end() - 1) = *(deqMax.begin());
        ansMax.push_back((*deqMax.begin()).second);
    }
    for(auto itea = ansMax.begin(); itea != ansMax.end(); ++itea)printf("%d%c", *itea, itea == (ansMax.end() - 1) ? '\n' : ' ');

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