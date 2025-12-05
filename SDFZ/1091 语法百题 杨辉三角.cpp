#include <algorithm>
#include <cstdio>

void func(int n){
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
			int a[210][210];
			a[1][1]=a[2][1]=a[2][2]=1;
			for(int i=3; i<=n; i++){a[i][1]=a[i][i]=1;
				for(int j=2; j<i; j++){
					a[i][j]=a[i-1][j]+a[i-1][j-1];
				}
			}
			for(int i=1; i<=n; i++){
				for(int j=1; j<=i; j++)printf("%d ",a[i][j]);
				puts("");
			}
			break;
		}
	}
}

void INIT(){
	int n; while(scanf("%d",&n)!=EOF){func(n); puts("");}
}
int main(){INIT(); return 0;}
