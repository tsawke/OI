#include <cstdio>
#include <algorithm>
using namespace std;
int func(int a,int b){
	if(!(a%b))return b;
	else return func(b,a%b);
}int a,b;
int main(){scanf("%d%d",&a,&b);
	printf("%d %d\n",func(a,b),a*b/func(a,b));
	return 0;
}

