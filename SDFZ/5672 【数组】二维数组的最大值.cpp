#include <cstdio>
#include <algorithm>
using namespace std;
int a[110][110]; int maxpx=1,maxpy=1,maxx=-1;
int main(){
	for(int i=1; i<=3; i++)
		for(int j=1; j<=4; j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>maxx){maxx=a[i][j]; maxpx=i; maxpy=j;}
		}
	printf("%d %d %d\n",maxx,maxpx,maxpy);
	return 0;
}
