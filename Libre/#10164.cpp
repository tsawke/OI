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

int DP(int);
int f[15][15];
void Init(void);
int main(){
	int a, b;
    Init();
    for(int i = 1; i <= 10; ++i){
        for(int j = 0; j <= 9; ++j)
            printf("%d ", f[i][j]);
        printf("\n");
    }
    while(scanf("%d%d", &a, &b) != EOF && a != -1 && b != -1){
        printf("\\TEST dpa = %d, dpb = %d\n", DP(a - 1), DP(b));
        // printf("%d\n", DP(b) - DP(a - 1));
    }
    return 0;
}

int DP(int n){
    // if(n == -1)return 0;
    if(!n)return 0;
    vector< int >nums;
    int ans(0);
    while(n)nums.push_back(n % 10), n /= 10;
    reverse(nums.begin(), nums.end());
    // for(auto i : nums)printf("%d ", i);printf("\n");
    // for(int i = 0; i <= nums.front(); ++i){
    //     ans += f[nums.size()][i];
    //     printf("Now Plus f[%d][%d] = %d,  ans = %d\n", nums.size(), i, f[nums.size()][i], ans);
    // }
    // for(int i = 2; i <= (int)nums.size(); ++i){
    //     for(int k = max(nums.at(i - 1) + 1, nums.at(i - 2)); k <= 9; ++k){
    //         ans -= f[nums.size() - i + 1][k];
    //         printf("Now Minus f[%d][%d] = %d,  ans = %d\n", nums.size() - i + 1, k, f[nums.size() - i + 1][k], ans);
    //     }
    // }
    for(int i = 0; i <= nums.front() - 1; ++i){
        ans += f[nums.size()][i];
    }
    int last = nums.front();
    for(vector<)
    return ans;
}
void Init(void){
    for(int i = 0; i <= 9; ++i)f[1][i] = 1;
    for(int i = 2; i <= 11; ++i)
        for(int j = 0; j <= 9; ++j)
            for(int k = j; k <= 9; ++k)
                f[i][j] += f[i - 1][k];
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