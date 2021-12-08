#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;
int n, m, k; int a[1100][1100];
int FindMaxLength(int a[]);
int MAX = -INT_MAX;
int main(){scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)scanf("%d", &a[i][j]);
	printf("%d\n", FindMaxLength(a[k]));
	return 0;
}
int FindMaxLength(int a[]){
	for(int i=1; i<m; i++){
		if(!a[i])continue;
		int sum(1);
		for(int j=i+1; j<=m; j++, i++)if(a[j])++sum;else break;
		MAX = max(MAX, sum);
	}return MAX;
}
