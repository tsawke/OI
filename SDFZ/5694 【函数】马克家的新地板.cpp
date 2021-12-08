#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){int m;char k,t;
		scanf("%d%c%c",&m,&t,&k); for(int i=1; i<=m; i++)printf("%c",k); puts("");
	}return 0;
}

