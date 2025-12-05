#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template <typename T = int>
inline T read(void);

int N, M;
bool _map[110][110];
int map_[110];
int dp[110][2100][2100]; //i-line  j-current, k-last
int count(int x){
	int cnt(0);
	for(int i = 0; i < M; ++i)if((x >> i) & 1)++cnt;
	return cnt;
}
vector < int > lineArr;
void Init(int dep, int cur){
	if(dep > M)return (void)lineArr.push_back(cur);
	Init(dep + 1, cur << 1);
	if(!(cur & 1) && !((cur >> 1) & 1))cur <<= 1, Init(dep + 1, cur + 1);
}
inline bool readChar(void);
int main(){
	N = read(), M = read();
	Init(1, 0);
	// for(auto i : lineArr)cout << bitset < 8 >(i) << endl;
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j)
			_map[i][j] = readChar(),
			map_[i] <<= 1,
			map_[i] += _map[i][j];
	for(auto i : lineArr)dp[1][i][0] = (i & map_[1]) ? 0 : count(i);
	for(auto i : lineArr){
		for(auto j : lineArr){
			if(i & map_[2] || i & j)continue;
			dp[2][i][j] = max(dp[2][i][j], dp[1][j][0] + count(i));
		}
	}
	for(int i = 3; i <= N; ++i){
		for(auto j : lineArr){
			for(auto k : lineArr){
				for(auto l : lineArr){
					if(j & map_[i] || k & map_[i - 1] || l & map_[i - 2])continue;
					if(j & k || k & l || j & l)continue;
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + count(j));
				}
			}
		}
	}
	// for(int i = 1; i <= N; ++i){
	// 	printf("i = %d:\n", i);
	// 	for(auto j : lineArr){
	// 		for(auto k : lineArr){
	// 			printf("%d ", dp[i][j][k]);
	// 		}
	// 		printf("\n");
	// 	}
	// }
	int ans(0);
	for(auto i : lineArr){
		for(auto j : lineArr)
			ans = max(ans, dp[N][i][j]);
	}
	printf("%d\n", ans);
    return 0;
}
/*
3 3
PPP
PPP
PPP
*/
inline bool readChar(void){
	char c = getchar();	
	while(c != 'P' && c != 'H')c = getchar();
	return c == 'P' ? false : true;
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