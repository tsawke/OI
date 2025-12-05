#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,x,y;
int main(){scanf("%d%d%d",&n,&x,&y);
	for(int i=1; i<=n; i++)printf("(%d,%d)",x,i); puts("");
	for(int i=1; i<=n; i++)printf("(%d,%d)",i,y); puts("");
	for(int i=1,j=abs(y-x)+1; ; i++){
		if(i>n || j>n)break;
		printf("(%d,%d)",i,j);
		j++;
	}puts("");
	for(int i=n,j=abs(y-x); ; i--){
		if(i<1 || j>n)break;
		printf("(%d,%d)",i,j);
		j++;
	}puts("");
	return 0;
}
