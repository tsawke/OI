#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int tree[110000]={0}; int n,m;
int main(){scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		int hei; scanf("%d",&hei); tree[i]=hei;
	}
	for(int i=1; i<=m; i++){
		int temp; scanf("%d",&temp);
		switch(temp){
			case 1:{
				int x,h; scanf("%d%d",&x,&h); tree[x]+=h;
				break;
			}
			case 2:{
				int num; scanf("%d",&num);
				printf("%d\n",tree[num]);
				break;
			}
		}
	}
	return 0;
}
