#include <cstdio>
#include <algorithm>
using namespace std;
int n; /*n<=100*/
int main(){scanf("%d",&n);int s=0,ss=n*2-1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=s; j++)printf(" ");
		printf("****"); s++;
		for(int j=1; j<=ss; j++)printf(" ");
		printf("****"); ss-=2; if(i!=n)puts("");
	}
	return 0;
}
