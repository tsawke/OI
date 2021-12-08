#include <cstdio>
#include <algorithm>
using namespace std;
long long func(int m,int n){
	if(!m)return n+1;
	if(m && !n)return func(m-1,1);
	if(m && n)return func(m-1,func(m,n-1));
}int m,n;
int main(){scanf("%d%d",&m,&n); 
	printf("%lld\n",func(m,n)); return 0;
}
