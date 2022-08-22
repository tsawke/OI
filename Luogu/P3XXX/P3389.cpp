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
#define MUL (double)(1.00000000)

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int equ[110][110];
int sol[110];
int N;
int Gauss(void);
int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            equ[i][j] = read();
        }
        sol[i] = read();
    }



    return 0;
}
int Gauss(void){
    for(int i = 1; i <= N; ++i){
        int maxp(i), maxx(equ[i][i]);
        for(int j = i + 1; j <= N; ++j){
            if(equ[j][i] > maxx){
                maxx = equ[j][i];
                maxp = j;
            }
        }
        if(!maxx)return -1;
        swap(equ[i], equ[maxp]);
        for(int j = 1; j <= N; ++j){
            
        }
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