#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int p;
int max_func(int a,int b){int maxx=-1;
	for(int i=1; i<=sqrt(max(a,b))*2; i++)if(a%i==0 && b%i==0)maxx=max(maxx,i); return maxx;
}
int main(){scanf("%d",&p);	
	for(int i=1; i<=p; i++){int a,b; scanf("%d%d",&a,&b); printf("%d\n",max_func(a,b));}
	return 0;
}

