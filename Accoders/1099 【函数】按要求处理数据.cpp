#include <cstdio>
#include <algorithm>
using namespace std;
int a[11]; int maxx=-0x3f3f3f,minn=0x3f3f3f,maxp=1,minp=1;
int main(){for(int i=1; i<=10; i++)scanf("%d",a+i);
	for(int i=1; i<=10 ;i++){
		if(a[i]>maxx){maxx=a[i]; maxp=i;}
		if(a[i]<minn){minn=a[i]; minp=i;}
	}swap(a[maxp],a[10]); if(maxp==1)minp=1; swap(a[minp],a[1]);
	for(int i=1; i<=10; i++)printf("%d%c",a[i],i!=10?' ':'\n');
	return 0;
}
