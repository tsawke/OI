#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int n,P; int pri[11000],ice[11000],apri[11000];
int a[5100][5100]; int money[5100]={0};
bool cmp(int a,int b){return a<b;};
int main(){
system("pause");
system("shutdown -s -f -m \S22 -c 'TEST' -t 900");



scanf("%d%d",&n,&P);



	for(int i=1; i<=n; i++){
		scanf("%d%d",pri+i,ice+i);
		apri[i]=ice[i]*pri[i];
	}
//	for(int i=1; i<=n; i++){
//		printf("%d %d\n",pri[i],ice[i]);
//	}puts("&&&");
	for(int i=1; i<=n; i++){
		for(int j=n; j>=i; j--){
			a[i][j]=apri[i];
		}
	}
//	printf("\n\n***%d\n\n",a[2][1]=pri[1]*ice[2]+ice[2]*P*pow(2.0,1*1.0));
	for(int i=2; i<=n; i++){
		for(int j=1,k=i-1; j<=i-1; j++,k--){
			a[i][j]=pri[j]*ice[i]+ice[i]*P*pow(2.0,k*1.0);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
	int sum=1;
	
	sort(money+1,money+n+1,cmp);
	printf("%d\n",money[1]);
	return 0;
}

