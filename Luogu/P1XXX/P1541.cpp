#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template< typename T = int >
inline T read(void);

int N, M;
int val[350];
int crd[5];
int dp[50][50][50][50];

int main(){
	N = read(), M = read();
	for(int i = 1; i <= N; ++i)val[i] = read();
	for(int i = 1; i <= M; ++i)++crd[read()];
	dp[0][0][0][0] = val[1];
	for(int i = 0; i <= crd[1]; ++i)
		for(int j = 0; j <= crd[2]; ++j)
			for(int k = 0; k <= crd[3]; ++k)
				for(int s = 0; s <= crd[4]; ++s){
					int pos = i * 1 + j * 2 + k * 3 + s * 4 + 1;
					dp[i][j][k][s] = max({
						dp[i][j][k][s],
						i ? dp[i - 1][j][k][s] + val[pos] : -1,
						j ? dp[i][j - 1][k][s] + val[pos] : -1,
						k ? dp[i][j][k - 1][s] + val[pos] : -1,
						s ? dp[i][j][k][s - 1] + val[pos] : -1
					});
				}
	printf("%d\n", dp[crd[1]][crd[2]][crd[3]][crd[4]]);

	fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}



template < typename T >
inline T read(void){
	T ret(0);
	short flag(1);
	char c = getchar();
	while(c != '-' && !isdigit(c))c = getchar();
	if(c == '-')flag = -1, c = getchar();
	while(isdigit(c)){
		ret *= 10;
		ret += int(c - '0');
		c = getchar();
	}
	ret *= flag;
	return ret;
}