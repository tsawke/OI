#include <cstdio>
#include <algorithm>
int n,a[210][210],c,x,y;
int main(){scanf("%d",&n);
	c=x=y=1; a[x][y]=1;
	while(n*n!=c){
		while(y+1<=n && !a[x][y+1])a[x][++y]=++c;
		while(x+1<=n && !a[x+1][y])a[++x][y]=++c;
		while(y-1>=1 && !a[x][y-1])a[x][--y]=++c;
		while(x-1>=1 && !a[x-1][y])a[--x][y]=++c;
	} for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)printf("%d ",a[i][j]); puts("");
	}
	return 0;
}
