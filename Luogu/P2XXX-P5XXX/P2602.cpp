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

unll a, b;
unll f[15][15][15];//i位数 j开头 k有多少个
unll f0[15][15][15];
// ll lastZero[15][15];
// vector < tuple<int, int, int, int>/*i, j, k, value*/ > oper;
void Init(void);
vector<int> DP(unll);
unll CreateNum(int, int, vector<int>);
unll qPow(unll, unll, unll = ULONG_LONG_MAX);

signed main(){
    freopen("./P2602-OUTPUT.txt", "w", stdout);
    Init();
    
    for(int i = 1; i <= 4; ++i){
        printf("I = %llu:\n", i);
        for(int j = 0; j <= 9; ++j){
            printf("            ");
            for(int k = 0; k <= 9; ++k)printf("%llu ", f[i][j][k]);
            printf("\n");
        }
    }

    for(int i = 1; i <= 4; ++i){
        printf("I = %llu:\n", i);
        for(int j = 0; j <= 9; ++j){
            printf("            ");
            for(int k = 0; k <= 9; ++k)printf("%llu ", f0[i][j][k]);
            printf("\n");
        }
    }

	// a = read<unll>(), b = read<unll>();
    // vector <int> ansa ( DP(a - 1) );
    // vector <int> ansb ( DP(b) );
    // for(int i = 0; i <= 9; ++i)ansb.at(i) -= ansa.at(i);
    // // for(auto i : ansa)printf("%lld ", i);
    // // printf("\n");
    // for(auto i : ansb)printf("%llu ", i);
    // printf("\n");

    for(int i = 1; i <= 1000; ++i){
        vector <int> ans (DP(i));
        printf("No.%llu  [0]=>%llu%s", i, ans.at(0), (i % 5 == 0 || i == 1000) ? "\n" : "    ");
        ans.clear();
    }
    return 0;
}
unll qPow(unll a, unll b, unll MOD){
    unll mul(a);
    unll ret(1ull);
    while(b){
        if(b & 1ull){
            ret = (ret * mul) % MOD;
        }
        mul = (mul * mul) % MOD;
        b >>= 1;
    }
    return ret;
}
unll CreateNum(int s, int e, vector<int>nums){
    unll ret(0ull);
    unll mul(1ull);
    for(int i = e; i >= s; --i)ret += nums.at(i - 1) * mul, mul *= 10ull;
    return ret;
}
vector<int> DP(unll n){
    vector < int > nums;
    if(!n){
        vector <int> ans0(10, 0);
        ans0.at(0) = 1ull;
        return ans0;
    }
    while(n)nums.push_back(n % 10ull), n /= 10ull;
    reverse(nums.begin(), nums.end());
    vector < int > anss(10, 0ull);
    int len(nums.size());
    // int s = 0;
    // int lastN(10);//return error
    // for(vector<int>::iterator itea = nums.begin(); itea != nums.end(); ++itea){
    //     for(int i = itea == nums.begin() ? 1 : 0; i < *itea; ++i){
    //         for(int r = 0; r <= 9; ++r){
    //             anss[r] += f[len][i][r];
    //         }
    //     }
    //     ++s;
    //     --len;
    //     if(itea != nums.begin())anss[lastN] += CreateNum(s, nums.size(), nums);
    //     lastN = *itea;
    // }
    // for(int i = 2; i <= nums.size(); ++i){
    //     for(int r = 0; r <= 9; ++r){
    //         anss[r] += f0[nums.size() - i + 1][0][r];
    //     }
    // }
    

    for(int i = 1; i <= len - 1; ++i)
        for(int j = i == 1 ? 0 : 1; j <= 9; ++j)
            for(int r = 0; r <= 9; ++r)
                anss.at(r) += f[i][j][r];
    int LastNums[10];
    memset(LastNums, 0ull, sizeof(LastNums));
    int s(0ull);
    for(vector< int >::iterator itea = nums.begin(); itea != nums.end(); ++itea){
        for(int j = itea == nums.begin() ? 1 : 0; j < *itea; ++j){
            for(int r = 0; r <= 9; ++r){
                anss.at(r) += f[len][j][r];
            }
        }
        ++s;
        if(itea != nums.begin()){
            unll subNum = CreateNum(s, nums.size(), nums);
            for(int r = 0; r <= 9; ++r){
                anss[r] += LastNums[r] * subNum;
            }
        }
        LastNums[*itea]++;

    }
    for(auto i : nums)++anss[i];
    
    return anss;
}
void Init(void){
    memset(f, 0, sizeof(f));
    for(int i = 0; i <= 9; ++i)f[1][i][i] = 1;
    for(int i = 2; i <= 12; ++i){
        // memset(lastZero, 0, sizeof(lastZero));
        for(int j = 0; j <= 9; ++j){
            /*if(j)*/ f[i][j][j] += qPow(10ull, (unll)i - 1);
            // if(!j) oper.push_back(make_tuple(i, j, j, (int)pow((float)10, (float)i - 1)));
            for(int r = 0; r <= 9; ++r){
                // if(!r && j)f[i][j][0] += (int)pow((float)10, (float)i - 2);
                for(int k = 0; k <= 9; ++k){
                    f[i][j][k] += f[i - 1][r][k];
                    // if(!k)f[i][j][k] += lastZero[k][k];
                }
            }
        }
    }
    // for(auto I : oper){
    //     int i, j, k, value;
    //     tie(i, j, k, value) = I;
    //     f[i][j][k] -= value;
    // }
    // copy(begin(f), end(f), begin(f0));
    memcpy(f0, f, sizeof(f));
    for(int i = 2; i <= 12; ++i){
        for(int j = 1; j <= i - 1; ++j)f0[i][0][0] -= qPow(10ull, (unll)i - j);
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