#include <cstdio>
#include <algorithm>
using namespace std;
int func(int n,int k){
	if(k==1 || n==k)return true;
	return func(n-1,k-1)+k*func(n-1,k);
}int n,k;
int main(){scanf("%d%d",&n,&k);
	printf("%d\n",func(n,k));
	return 0;
}

