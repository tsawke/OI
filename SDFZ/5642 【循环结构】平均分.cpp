#include <cstdio>
#include <algorithm>
using namespace std;
int n,score[110];double alls=0;
bool cmp(int x,int y){return x<y;}
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",score+i);
	sort(score+1,score+n+1,cmp);
	for(int i=2; i<=n-1; i++)alls+=score[i];
	alls*=1.00; alls/=(n-2)*1.00;
	printf("%.2lf\n",alls);
	return 0;
}
