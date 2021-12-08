#include <algorithm>
#include <cstdio>
using namespace std;
int a[110][110]; int n,x,y; int sum=7;
int main(){scanf("%d%d%d",&n,&x,&y);
	if(n==1)a[1][n]=1;
	else if(n==2){
		a[1][n]=1; a[1][n-1]=2; a[2][n]=3;
	}else if(n==3){
		a[1][n]=1; a[1][n-1]=2; a[2][n]=3;
		a[3][n]=4; a[2][n-1]=5; a[1][n-2]=6;
	}else{
		a[1][n]=1; a[1][n-1]=2; a[2][n]=3;
		a[3][n]=4; a[2][n-1]=5; a[1][n-2]=6;
		for(int x=4; x<=n; x++){
			if(x%2==0){
				for(int i=1,j=x-1; i<=x; i++,j--){
					a[i][n-j]=sum%10; sum++;
				}
			}else{
				for(int i=x,j=0; i>=1; i--,j++){
					a[i][n-j]=sum%10; sum++;
				}
			}
		}
		for(int x=n-1; x>=1; x--){
			if(x%2==0){
				for(int i=n-x+1,j=1; i<=n; i++,j++){
					a[i][j]=sum%10; sum++;
				}
			}else{
				for(int i=n,j=x; i>=n-x+1; i--,j--){
					a[i][j]=sum%10; sum++;
				}
			}
		}
		
	}printf("%d\n",a[x][y]);
/*	puts("");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}*/
	return 0;
}
