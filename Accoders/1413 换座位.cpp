#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int now(0); int n; int ans(0);
int main(){scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int t; scanf("%d", &t);
		if(t != ++now)++ans;
	}printf("%d\n",ans);
	return 0;
}

