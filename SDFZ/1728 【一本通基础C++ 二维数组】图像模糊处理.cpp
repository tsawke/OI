#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int a[110][110]; double ans[110][110]; int n,m;
int main(){scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)scanf("%d", &a[i][j]);
	for(int i=1; i<=n; i++){ans[i][1] = a[i][1]; ans[i][m] = a[i][m];}
	for(int i=1; i<=m; i++){ans[1][i] = a[1][i]; ans[n][i] = a[n][i];}
	for(int i=2; i<=n-1; i++)for(int j=2; j<=m-1; j++)ans[i][j] = round(a[i][j] + a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1]) / 5;
	for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)printf("%.0lf%s", ans[i][j], j!=m?" ":" \n");
	return 0;
}

