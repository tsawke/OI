#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int a[10];
int num(int n,int i){int sum=0;
	if(n<=0)sum++;
	while(abs(n)>0){sum++; n/=10;}
//	if(sum>8){for(int i=1; i<=sum-7; i++)a[i]/=10;}
	return 8-sum;
}
int main(){scanf("%d%d%d",a+1,a+2,a+3);
	for(int k=1; k<=3; k++){
		for(int i=1; i<=num(a[k],k); i++)printf(" "); printf("%d%c",a[k],k!=3?' ':'\n');
	}
	return 0;
}
