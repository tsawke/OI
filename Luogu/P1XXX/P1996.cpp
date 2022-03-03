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
vector<int>que;
int main(){
    int n(read()), m(read());
    for(int i = 1; i <= n; ++i)que.push_back(i);
    int nowCount(0);
    vector<int>::iterator itea = que.begin() - 1;
    while(!que.empty()){
        advance(itea, 1);
        if(itea == que.end())itea = que.begin();
        if(++nowCount == m){
            nowCount = 0;
            printf("%d ", *itea);
            que.erase(itea);
            if(itea == que.begin())itea = que.end() - 1;
            else advance(itea, -1);
        }
    }printf("\n");
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
