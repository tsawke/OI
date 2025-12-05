#include <cstdio>
#include <algorithm>
using namespace std;
int n; int cor[11000][5100]={-1};
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int a,b,g,p; scanf("%d%d%d%d",&a,&b,&g,&p);
		for(int j=a; j<=a+g; j++){
			for(int k=b; k<=b+p; k++){
				cor[j][k]=i;
			}
		}
	}int x,y; scanf("%d%d",&x,&y);
	if(cor[x][y]>=1)printf("%d\n",cor[x][y]);
	else printf("-1\n");
	return 0;
}
