#include <cstdio>
#include <algorithm>
using namespace std;
long long n; bool ans[11000]; int len=1;
int main(){scanf("%lld",&n); if(n==0){printf("0\n");return 0;}
	while(n>0){if(n%2==0)ans[len]=false;else ans[len]=true; len++; n/=2;}
	len--; for(int i=len; i>=1; i--){
		if(ans[i])printf("1");else printf("0");
	}puts("");
	return 0;
}
