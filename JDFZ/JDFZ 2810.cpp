#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;
typedef unsigned long long unll;
inline unll readULL(void);
inline int read(void);
int a[1100][1100];
int main(){
	int n(read());
	int nowSteps(n);
	int nowBeg(1);
	int num(0);
	while(nowSteps > 0){
		
		if(nowSteps == 1){
			a[nowBeg][nowBeg] = ++num;
			break;
		}
		for(int j = 0; j < nowSteps; ++j)a[nowBeg][nowBeg + j] = ++num;
//			printf("\nTEST nowSteps = %d Operation:1  a[][] --> \n", nowSteps);
//			for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
//			printf("\n");
		for(int i = 1; i < nowSteps + 1 - 1; ++i)a[nowBeg + i][n - nowBeg + 1] = ++num;
//			printf("\nTEST nowSteps = %d Operation:2  a[][] --> \n", nowSteps);
//			for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
//			printf("\n");
		for(int j = 1; j < nowSteps + 1 - 1; ++j){
			a[n - nowBeg + 1][n - nowBeg + 1 - j] = ++num;
//				printf("\nFOR:::TEST nowSteps = %d Operation:3 for=%d a[][] --> \n", nowSteps, j);
//				for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
//				printf("\n");
		}
//			printf("\nTEST nowSteps = %d Operation:3  a[][] --> \n", nowSteps);
//			for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
//			printf("\n");
		for(int i = 1; i < nowSteps + 1 - 1 - 1; ++i)a[n - nowBeg + 1 - i][nowBeg] = ++num;
//			printf("\nTEST nowSteps = %d Operation:4  a[][] --> \n", nowSteps);
//			for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
//			printf("\n");
		++nowBeg;
//			printf("\nTEST nowSteps = %d a[][] --> \n", nowSteps);
//			for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');
//			printf("\n");
		nowSteps -= 2;
	}
	for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j)printf("%d%c", a[i][j], j == n ? '\n' : ' ');

//    system("pause");
    return 0;
}

inline unll readULL(void){
	unll ret(0);
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
		ret *= flag;
	}
	return ret;
}
inline int read(void) {
	int ret(0);
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
		ret *= flag;
	}
	return ret;
}

