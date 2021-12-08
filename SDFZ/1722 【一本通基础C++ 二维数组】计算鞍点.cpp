#include <cstdio>
#include <algorithm>
using namespace std;
short sum[10][10] = {0};
int a[10][10];
int main(){
	for(int i=1; i<=5; i++)for(int j=1; j<=5; j++)scanf("%d", &a[i][j]);
	for(int i=1; i<=5; i++){
		int maxx(-1); int x,y;
		for(int k=1; k<=5; k++)if(a[i][k] > maxx){maxx = a[i][k]; x = i; y = k;}
		++sum[x][y];
	}
	for(int j=1; j<=5; j++){
		int minn(2147483640); int x,y;
		for(int k=1; k<=5; k++)if(a[k][j] < minn){minn = a[k][j]; x = k; y = j;}
		++sum[x][y];
	}
	for(int i=1; i<=5; i++)for(int j=1; j<=5; j++)if(sum[i][j] == 2){printf("%d %d %d\n", i, j, a[i][j]); return 0;}

	return 0;
}

