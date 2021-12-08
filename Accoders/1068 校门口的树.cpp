#include <cstdio>
#include <algorithm>
using namespace std;
int l,m,sum=0; bool tree[11000]={true};
int main(){scanf("%d%d",&l,&m);
	for(int i=0; i<=l; i++)tree[i]=true;
	for(int i=1; i<=m; i++){
		int x,y; scanf("%d%d",&x,&y);
		for(int j=x; j<=y; j++)tree[j]=false;
	}
	for(int i=0; i<=l; i++)if(tree[i])sum++; printf("%d\n",sum);
	return 0;
}
