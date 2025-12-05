#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int m,k;
bool check(int m,int k){
	if(m%19!=0)return false; int temp=m; int a[110],i;
	for(i=1; temp>0; i++){a[i]=temp%10; temp/=10;} i--;
	int sum=0; for(int j=1; j<=i; j++)if(a[j]==3)sum++;
	return sum==k;
}
int main(){scanf("%d%d",&m,&k);
	if(check(m,k))printf("yes\n"); else printf("no\n");	
	return 0;
}

