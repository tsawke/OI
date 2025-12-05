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
#include <queue>
#define SUBMIT
#ifndef SUBMIT
#define PRINT for(int i = 1; i <= n; ++i)printf("%d%c", get<3>(vertex[i]), i == n ? '\n' : ' ')
#else
#define PRINT 
#endif
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
tuple< vector<int>, int, int, int, bool /*toVertex, wealth, indegree, time, vis*/ >vertex[11000];
queue<int>vertQ;
queue<int>topoSequence;
void TopoSort(void);
int n;
int main(){
	for(int i = 1; i <= 10100; ++i)get<4>(vertex[i]) = bool((get<3>(vertex[i]) = get<2>(vertex[i]) = get<1>(vertex[i]) = 0));
	n = read();
    for(int i = 1; i <= n; ++i){
		int num = read();
		int wealth = read();
		get<1>(vertex[num]) = wealth;
		int works;
		while((works = read())){
			get<0>(vertex[works]).push_back(num);
			++get<2>(vertex[num]);
		}
    }
	TopoSort();
	int _max(0);
	for(int i = 1; i <= n; ++i)_max = max(_max, get<3>(vertex[i]));
	printf("%d\n", _max);
    return 0;
}
void TopoSort(void){
	for(int i = 1; i <= n; ++i){
		if(!get<2>(vertex[i]) && !get<4>(vertex[i])){
			vertQ.push(i);
			get<4>(vertex[i]) = true;
			get<3>(vertex[i]) = get<1>(vertex[i]);
		}
	}
	PRINT;
	while(!vertQ.empty()){
		int vert = vertQ.front();
		vertQ.pop();
		for(auto i : get<0>(vertex[vert])){
			get<3>(vertex[i]) = max(get<3>(vertex[i]), get<3>(vertex[vert]) + get<1>(vertex[i]));
			if(!--get<2>(vertex[i])){
				vertQ.push(i);
			}
		}
		PRINT;
	}
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