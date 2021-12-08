#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){scanf("%d",&n); printf("1"); if(n!=1)printf(",");
	for(int i=2; i<=n; i++){
		if(i%2==0)printf("-"); printf("1/");
		printf("%d",i); if(i!=n)printf(",");
	}puts("");
	return 0;
}
