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

#define true8 true
#define true4 true
#define trueC true
#define trueMAX true
#define false8 false
#define false4 false
#define falseC false
#define falseMax false

#define thisF f[len][last1][last2][with4][with8][same3][maxNum]

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

template <typename T = int>
inline T read(void);

// i位 jk开头 l(T/F)是否有4  m(T/F)是否有8  n(T/F)是否有相邻 o(T/F)是否达到最大
int f[15][10][10][2][2][2][2];
vector< int >nums;
// void Init(void);
int make(int);
int dfs(int, int, int, bool, bool, bool, bool);

signed main(){
	int a = read(), b = read();
    printf("%lld\n", make(b) - make(a - 1));
    return 0;
}
int make(int N){
    if(N < 1e10)return 0;
    memset(f, -1, sizeof(f));
    nums.clear();
    while(N)nums.push_back(N % 10), N /= 10;
    reverse(nums.begin(), nums.end());
    // for(auto i : nums)printf("%d ", i); printf("\n");
    return dfs(1, -1, -1, false4, false8, falseC, trueMAX);
}
//添加第len位数
int dfs(int len, int last1, int last2, bool with4, bool with8, bool same3, bool maxNum){
    // printf("DFS: len=%d, last1=%d, last2=%d, with4=%d, with8=%d, same3=%d, maxNum=%d\n", len, last1, last2, with4, with8, same3, maxNum);
    // usleep(300000);
    if(~last1 && ~last2 && len >= 11 + 1)return thisF = same3 & (!with4 | !with8);
    if(~last1 && ~last2 && ~thisF)return thisF;
    int maxN = maxNum ? nums.at(len - 1) : 9;
    int ret(0);
    for(int i = len == 1 ? 1 : 0; i <= maxN; ++i){
        ret += dfs(
            len + 1,
            i,
            last1,
            with4 | (i == 4),
            with8 | (i == 8),
            same3 | (i == last1 && last1 == last2),
            maxNum & (i == maxN)
        );
    }
    if(~last1 && ~last2)thisF = ret;
    return ret;
}

// void Init(void){
//     for(int i = 0; i <= 9; ++i)
//         for(int j = 0; j <= 9; ++j)
//             f[2][i][j][false4][false8][falseC] = (i != 8 && i != 4 && j != 8 && j != 4) ? 1 : 0;
//     for(int i = 0; i <= 9; ++i){
//         if(i != 8)f[2][4][i][true4][false8][falseC] = f[2][i][4][true4][false8][falseC] = 1;
//         if(i != 4)f[2][8][i][false4][true8][falseC] = f[2][i][8][false4][true8][falseC] = 1;
//     }
//     f[2][4][8][true4][true8][falseC] = f[2][8][4][true4][true8][falseC] = 1;
//     for(int i = 3; i <= 11; ++i){
//         for(int j = 0; j <= 9; ++j){
//             for(int k = 0; k <= 9; ++k){
//                 if(i != 4 && i != 8 && j != 4 && j != 8){
//                     for(int jj = 0; jj <= 9; ++jj){
//                         for(int kk = 0; kk <= 9; ++kk){
//                             if()
//                             f[i][j][k][false4][false8][falseC] += 
//                         }
//                     }
                    
//                 }
//             }
//         }
//     }
// }
template <typename T>
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