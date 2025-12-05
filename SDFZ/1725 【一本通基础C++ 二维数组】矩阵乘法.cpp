#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k;
int a[110][110], b[110][110], ans[110][110] = {0};
int main(){scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)scanf("%d", &a[i][j]);
	for(int i=1; i<=m; i++)for(int j=1; j<=k; j++)scanf("%d", &b[i][j]);
	for(int i=1; i<=n; i++)for(int j=1; j<=k; j++)for(int s=1; s<=m; s++)ans[i][j] += (a[i][s] * b[s][j]);
	for(int i=1; i<=n; i++)for(int j=1; j<=k; j++)printf("%d%s", ans[i][j], j!=k?" ":" \n");
	return 0;
}

