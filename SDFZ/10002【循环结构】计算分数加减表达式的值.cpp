#include <cstdio>
#include <algorithm>
using namespace std;
int n; double ans=0.0000;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){int t=1;
		if(i%2==0)t=-1;
		ans+=t*1.0000*(1.0000/i*1.0000);
	}printf("%.4lf\n",ans);
	return 0;
}
