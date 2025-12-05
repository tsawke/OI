#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int fx=2,fa=1; int n,a;
int main(){scanf("%d%d",&a,&n);
	for(int i=2; i<=n; i++){
		fx*=2; fa=fa*2+1;
	}const int ans=fa*a/fx;
	printf("%d\n",ans);
	return 0;
}

