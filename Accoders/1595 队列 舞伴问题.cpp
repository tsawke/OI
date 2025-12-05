#include <bits/stdc++.h>
using namespace std;
int main()
{
	//made from ys33
	int n,m,k,sum=1,sum_n=1,sum_m=1; scanf("%d %d %d",&n,&m,&k);
	while(sum<=k){
		sum++;
		if(sum_n>n) sum_n=1; if(sum_m>m) sum_m=1;
		printf("%d %d\n",sum_n,sum_m);
		sum_n++; sum_m++;
	}
	return 0;
} 
