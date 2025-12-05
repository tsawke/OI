#include <cstdio>
#include <algorithm>
using namespace std;
int x,y,a,b,n,fa,mo,z;
int main(){scanf("%d%d%d%d",&x,&y,&a,&b);
/*	const int n=(x+y/(a-b)-(a+b)*y/(a-b))/3;
	const int z=(a*n+y-b*n)/(a-b);
	printf("%d\n",z-2);*/
	
	/******************************************************************************/
	/*fa+mo+s=x x>fa>ma, ma<x/2*/
	for(int i=1; i<=x/2;i++){//mo
		mo=i; fa=mo+y; z=x-mo-fa;
		for(int j=1; j<=min(min(fa,i),z); j++){//n
			n=j;
			if(a*(z-n)==fa-n && b*(z-n)==mo-n){
				printf("%d\n",z);
				return 0;
			}
		}
	}
	return 0;
}
/*
az-an+n-y==bz+n-bn

(a-b)(x-2mo-y-n)=6

3n==x+y/(a-b)-(a+b)*y/(a-b)
*/
