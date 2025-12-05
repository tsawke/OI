#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int main(){scanf("%d",&n);
	for(int i=1,m=n; i<=n; i++,m--){
		for(int j=1; j<=i-1; j++)printf(" ");
		for(int j=m*2-1; j>=1; j--)printf("*");
		puts("");
	}
	return 0;
}

