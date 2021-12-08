#include <cstdio>
#include <algorithm>
using namespace std;
void printyh(int n){
	switch(n){
		case 1:{
			printf("1\n");
			break;
		}
		case 2:{
			printf("1\n1 1\n");
			break;
		}
		default:{
			int a[110][110];
			for(int i=1; i<=n; i++)a[i][1]=a[i][i]=1;
			for(int i=3; i<=n; i++)
				for(int j=2; j<=i-1; j++)
					a[i][j]=a[i-1][j]+a[i-1][j-1];
			printf("1\n1 1\n");
			for(int i=3; i<=n; i++){
				for(int j=1; j<=i; j++)
					printf("%d ",a[i][j]);
				puts("");
			}
				
		}
	}puts("");
}
int n;
int main(){
	while(scanf("%d",&n)!=EOF){printyh(n);}
	return 0;
}
