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

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int readChar(void);

int N, Q;
vector<int>block[1100];
int blockL[1100], blockR[1100], blockLen[1100];
int height[1100000];
int lazytag[1100];
int FindBlock(int n);
int main(){
	N = read(), Q = read();
    InitBlocks();
    for(int k = 1; k <= Q; ++k){
        int mode = readChar();
        switch(mode){
            case int('M'):{
                int l = read(), r = read(), h = read();
                if(FindBlock(l) == FindBlock(r)){
                    for(int i = l; i <= r; ++i)
                        height[i] += h;
                    UpdateVector(FindBlock(l));
                    break;
                }
                for(int i = l; i <= blockR[FindBlock(l)]; ++i)
                    height[i] += h;
                for(int i = blockL[FindBlock(r)]; i <= r; ++i)
                    height[i] += h;
                for(int i = FindBlock(l) + 1; i <= FindBlock(r) - 1; ++i)
                    lazytag[i] += h;
            }
            case int('A'):{
                int l = read()
            }
        }
    }


    return 0;
}
void UpdateVector(int n){
    for(int i = 1; i <= blockLen[n]; ++i)
        block[n].at(i - 1) = height[n * blockLen[1] + i];
    sort(block[n].begin(), block[n].end());
}
int FindBlock(int n){
    return ceil(n / blockLen[1]);
}
void InitBlocks(void){
    int cnt(0);
    int blockLen = floor(sqrt(N * 1.00));
    for(int i = 1; i <= blockLen; ++i){
        blockL[i] = blockLen * (i - 1) + 1;
        blockR[i] = blockLen * i;
        ::blockLen[i] = blockLen;
        for(int j = 1; j <= blockLen; ++j){
            height[++cnt] = read();
            block[i].push_back(height[cnt]);
        }
    }
    blockR[blockLen] = N;
    ::blockLen[blockLen] += (N - blockLen * blockLen);
    for(++cnt; cnt <= N; ++cnt){
        height[cnt] = read();
        block[blockLen].push_back(height[cnt]);
    }
    for(int i = 1; i <= blockLen; ++i)
        sort(block[i].begin(), block[i].end());
}
int readChar(void){
    int ret(0);
	char c = getchar();
	while (!isalnum(int(c))) {
		c = getchar();
	}
    ret = int(c);
	return ret;
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