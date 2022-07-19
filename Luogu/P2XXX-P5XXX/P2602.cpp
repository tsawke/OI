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

#define int unll

template <typename T = int>
inline T read(void);

ll a, b;
ll f[15][15][15];//i位数 j开头 k有多少个
void Init(void);
vector<int> DP(ll);
unll CreateNum(int, int, vector<int>);
signed main(){
    Init();

    // for(int i = 1; i <= 3; ++i){
    //     printf("I = %llu:\n", i);
    //     for(int j = 0; j <= 9; ++j){
    //         printf("            ");
    //         for(int k = 0; k <= 9; ++k)printf("%llu ", f[i][j][k]);
    //         printf("\n");
    //     }
    // }

	a = read<ll>(), b = read<ll>();
    vector <int> ansa ( DP(a - 1) );
    vector <int> ansb ( DP(b) );
    for(int i = 0; i <= 9; ++i)ansb.at(i) -= ansa.at(i);
    // for(auto i : ansa)printf("%lld ", i);
    // printf("\n");
    for(auto i : ansb)printf("%llu ", i);
    printf("\n");

    return 0;
}
unll CreateNum(int s, int e, vector<int>nums){
    unll ret(0ull);
    unll mul(1ull);
    for(int i = e; i >= s; --i)ret += nums.at(i - 1) * mul, mul *= 10ull;
    return ret;
}
vector<int> DP(ll n){
    vector < int > nums;
    if(!n){
        vector <int> ans0(10, 0);
        ans0.at(0) = 1;
        return ans0;
    }
    while(n)nums.push_back(n % 10ull), n /= 10ull;
    reverse(nums.begin(), nums.end());
    vector < int > anss(10, 0);
    int len(nums.size());
    int s = 0;
    int lastN(10);//return error
    for(vector<int>::iterator itea = nums.begin(); itea != nums.end(); ++itea){
        for(int i = 0; i < *itea; ++i){
            for(int r = 0; r <= 9; ++r){
                anss[r] += f[len][i][r];
            }
        }
        ++s;
        --len;
        if(itea != nums.begin())anss[lastN] += CreateNum(s, nums.size(), nums);
        lastN = *itea;
    }
    for(auto i : nums)++anss[i];
    return anss;
}
void Init(void){
    memset(f, 0, sizeof(f));
    for(int i = 0; i <= 9; ++i)f[1][i][i] = 1;
    for(int i = 2; i <= 12; ++i){
        for(int j = 0; j <= 9; ++j){
            if(j)f[i][j][j] += (int)pow((float)10, (float)i - 1);
            for(int r = 0; r <= 9; ++r){
                for(int k = 0; k <= 9; ++k){
                    f[i][j][k] += f[i - 1][r][k];
                }
            }
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