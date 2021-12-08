#include <cstdio>
#include <algorithm>
using namespace std;
int a,b; int ans;
int main(){scanf("%d%d",&a,&b); ans=a;
	for(int i=2; i<=b; i++){ans*=a; ans%=1000;}
	if(ans<10)printf("00");
	else if(ans<100)printf("0");
	printf("%d\n",ans);
	return 0;
}
