#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[110],m,sum=0;
bool cmp(int x,int y){return x<y;}
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",a+i); scanf("%d",&m);
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++){
		if(a[i]>m)break;
		else if(a[i]==m)sum++;
	}printf("%d\n",sum);
	return 0;
}
