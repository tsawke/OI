#include <cstdio>
#include <algorithm>
using namespace std;
int n; int sum=0;
struct cor{int x,y;}a;
cor func(int n){int i; cor temp;
	for(i=1;;i++){
		sum+=i;
		if(sum>=n)break;
	}temp.x=i;
	temp.y=i-sum+n;
	return temp;
}
int main(){scanf("%d",&n); a=func(n);
	printf("%d %d\n",a.x,a.y);

	return 0;
}

