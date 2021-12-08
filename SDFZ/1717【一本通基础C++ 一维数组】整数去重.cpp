#include <cstdio>
#include <algorithm>
using namespace std;
class Num{
	public:
		int value;
		bool flag = true;
}a[21000];
int n; bool check[21000];
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i].value);
		if(!check[a[i].value])check[a[i].value] = true;
		else a[i].flag = false;
	}
	for(int i=1; i<=n; i++)if(a[i].flag)printf("%d%c", a[i].value, i!=n?' ':'\n');
	return 0;
}

