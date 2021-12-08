#include <bits/stdc++.h>
using namespace std; int a,b,c;
int pow(long long a,long long b,long long c){ long long ans=1,bas=a;
	while(b){
	if(b&1)ans=(ans*bas)%c;
	bas=(bas*bas)%c; b>>=1;
	}
	return ans%c;}
int main(){
	scanf("%lld %lld %lld",&a,&b,&c);	
	printf("%lld\n",pow(a,b,c));
	return 0;
}
