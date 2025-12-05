#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a,b,n;
int main(){scanf("%d%d%d",&a,&b,&n);
	if(n==0){
		if(a%b*10/b>=5)printf("%d\n",a/b+1); else printf("%d\n",a/b); return 0;
	}else printf("%d.",a/b); a%=b;
	while(n>0){a*=10;
		if(n>1)printf("%d",a/b);
		else{
			if(a/b>=5)printf("%d",a/b+1);
			else printf("%d",a/b);
		} a%=b; n--;
	}puts("");
	return 0;
}
