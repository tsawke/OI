#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,x,y,a,b;
int main(){scanf("%d%d%d%d%d",&n,&x,&y,&a,&b);
	const int S=n*a;
	const int S1=a*y,S2=b*x;
	int ans=S/(S1-S2);
	printf("%d %d\n",ans*x,ans*y);
	return 0;
}

