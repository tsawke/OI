//C++11 - Template
//TODO
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

int f[15][10]; //i位数 j开头
void Init(void);
int DP(int);
int main(){
    // freopen("./P2657-OUT.txt", "w", stdout);
	Init();
    // for(int i = 1; i <= 10; ++i){
    //     for(int j = 0; j <= 9; ++j){
    //         printf("%d%c", f[i][j], j == 9 ? '\n' : ' ');
    //     }
    // }
    int a = read(), b = read();
    printf("%d\n", DP(b) - DP(a - 1));
    // for(int i = 1; i <= 100; ++i){
    //     printf("%d%c", DP(i), i % 5 == 0 || i == 100 ? '\n' : ' ');
    // }
    return 0;
}
int DP(int n){
    if(!n)return 0;
    int ret(0);
    vector<int>nums;
    while(n)nums.push_back(n % 10), n /= 10;
    reverse(nums.begin(), nums.end());
    int len(nums.size());
    for(int i = 1; i <= len - 1; ++i){
        for(int r = 1; r <= 9; ++r)
            ret += f[i][r];
    }
    int s(-1);
    int last(100);
    for(vector<int>::iterator itea = nums.begin(); itea != nums.end(); ++itea){
        ++s;
        for(int i = itea == nums.begin() ? 1 : 0; i < *itea; ++i){
            if(abs(last - i) < 2)continue;
            ret += f[len - s][i];
        }

        if(abs(last - (*itea)) < 2)break;
        last = *itea;
        // for(int i = 1; i <= *itea; ++i){
            // int i = *itea;
            // for(int k = i - 2; k >= 0; --k){
            //     ret += f[len - s][k];
            // }
            // for(int k = i + 2; k <= 9; ++k){
            //     ret += f[len - s][k];
            // }
        // }
    }
    bool flag(true);
    for(vector<int>::iterator itea = nums.begin(); itea != nums.end() - 1; ++itea){
        if(abs(*itea - *(itea + 1)) < 2){
            flag = false;
            break;
        }
    }
    ret += flag;
    return ret;
}
void Init(void){
    for(int i = 0; i <= 9; ++i)f[1][i] = 1ull;
    for(int i = 2; i <= 10; ++i){
        for(int j = 0; j <= 9; ++j){
            for(int k = j - 2; k >= 0; --k)
                f[i][j] += f[i - 1][k];
            for(int k = j + 2; k <= 9; ++k)
                f[i][j] += f[i - 1][k];
        }
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