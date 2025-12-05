#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int r,n; int sum=0; int now=0;
int main(){scanf("%d%d",&r,&n);
	for(int i=1; i<=n; i++){
		int t; scanf("%d",&t); now+=t;
		if(abs(now)<=r)sum++;
	}printf("%d\n",sum);
	return 0;
}

