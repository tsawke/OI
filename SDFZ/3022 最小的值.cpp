#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,m,a[11000],minn;
bool cmp(int x,int y){return x<y;}
int main(){scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)scanf("%d",a+i);
	sort(a+1,a+n+1,cmp); minn=a[1];
	for(int i=1; i<=m; i++){
		int t; scanf("%d",&t);
		if(t==2){printf("%d\n",minn); continue;}
		else if(t==1){
			int tt; scanf("%d",&tt);
			minn=min(minn,tt);
		}
	}
	return 0;
}

