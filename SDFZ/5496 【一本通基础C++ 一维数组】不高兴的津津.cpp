#include <cstdio>
#include <algorithm>
using namespace std;
int maxx=-1,maxp=1;
int main(){
	int ta,tb; scanf("%d%d",&ta,&tb); maxx=ta+tb;
	for(int i=2; i<=7; i++){
		int a,b; scanf("%d%d",&a,&b);
		if((a+b)>maxx){maxx=max(maxx,a+b); maxp=i;}
	}printf("%d\n",maxp);
	return 0;
}
