#include <cstdio>
#include <algorithm>
int main(){
	int a[25][25]={0},x=1,n; scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int p=n-i+1,q=1; for(int j=1; j<=i; j++)a[p++][q++]=x++;
	} for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++)printf("%d ",a[i][j]); puts("");
	}
	return 0;
}
