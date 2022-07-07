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

vector< int >arr;
int dp[110000];
vector< int >height;
int main(){
    int temp;
    while(scanf("%d", &temp) != EOF && temp != -1)arr.push_back(temp);
    for(int i = 0; i <= 100100; ++i)dp[i] = 1;
    int len = arr.size();
    for(int i = 2; i <= len; ++i){
        for(int j = 1; j < i; ++j){
            if(arr.at(j - 1) >= arr.at(i - 1))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans1(INT_MIN);
    for(int i = 1; i <= len; ++i)ans1 = max(ans1, dp[i]);
    // for(auto i : arr)printf("%d ", i); printf("\n");
    // for(int i = 1; i <= len; ++i)printf("%d ", dp[i]);printf("\n");
    // for(int i = 0; i <= 100100; ++i)dp[i] = 1;
    // for(int i = 2; i <= len; ++i){
    //     for(int j = 1; j < i; ++j){
    //         if(arr.at(j - 1) < arr.at(i - 1))
    //             dp[i] = max(dp[i], dp[j] + 1);
    //     }
    // }
    int ans2(0);
    for(auto i : arr){
        if(height.empty()){++ans2; height.push_back(i); continue;}
        bool breakflag(false);
        for(auto &j : height){
            if(j >= i){
                j = i;
                breakflag = true;
                break;
            }
        }
        if(breakflag)continue;
        ++ans2;
        height.push_back(i);
    }
    printf("%d\n%d\n", ans1, ans2);
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
//TODO O(NlogN)