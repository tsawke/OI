#include <cstdio>
#include <algorithm>
using namespace std;
int a[110][110];
int main(){
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			scanf("%d",&a[i][j]);
	printf("%d %d\n",a[1][1]+a[2][2]+a[3][3],a[1][3]+a[2][2]+a[3][1]);
	return 0;
}

