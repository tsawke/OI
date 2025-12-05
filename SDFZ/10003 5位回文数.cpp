#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){scanf("%d",&n);
	if(n%10==n/10000 && n/10%10==n/1000%10)printf("yes\n");
	else printf("no\n");
	return 0;
}
