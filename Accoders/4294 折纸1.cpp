#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b; long long sum=0;
int main(){scanf("%lld%lld",&a,&b);
	while(true){
		if(a<=0 || b<=0){printf("%lld\n",sum); break;}
		if(a<b)swap(a,b); //a>b
		a-=b; sum++;
	}

	return 0;
}

