#include <cstdio>
#include <algorithm>
using namespace std;
bool tree[11000] = {false};
int l, m; int ans = 0;
int main(){
	scanf("%d%d", &l, &m);
	for(int i=1; i<=m; i++){
		int x,y; scanf("%d%d", &x, &y);
		for(int j=x; j<=y; j++)tree[j] = true;
	}
	for(int i=0; i<=l; i++)if(!tree[i])++ans;
	printf("%d\n",ans);
	return 0;
}
