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
int n;
int tell[210];
vector<int>ind[210];

int main(){
	n = read();
    for(int i = 1; i <= n; ++i){
        tell[i] = read();
        ind[i].push_back(i);
    }
    int cnt(0);
    while(true){
        ++cnt;
        decltype(ind[1].begin()) ends[210];
        for(int i = 1; i <= n; ++i)ends[i] = ind[i].end();
        for(int i = 1; i <= n; ++i){
            ind[tell[i]].insert(ind[tell[i]].end(), ind[i].begin(), ends[i]);
            if(find(ind[tell[i]].begin(), ind[tell[i]].end(), tell[i]) != ind[tell[i]].end()){
                printf("%d\n", cnt);
                return 0;
            }
            for(int k = 1; k <= n; ++k){
                printf("No.%d: ", k);
                for(auto j : ind[k])printf("%d  ", j);
                printf("\n");
            }
        }
    }
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