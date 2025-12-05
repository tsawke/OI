#include <cstdio>
#include <algorithm>
using namespace std;
int max_len(-1);
int n; int a[11000];
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d", a+i);
	for(int i=1; i<n; i++){
		int temp_len(1);
		for(int j=i+1; j<=n; j++){
			if(a[j] != a[i])break;
			++temp_len;
		}max_len = max(max_len, temp_len);
	}printf("%d\n", max_len);

	return 0;
}

