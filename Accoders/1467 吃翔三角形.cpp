#include <bits/stdc++.h>
using namespace std;
int func(int x){
	int ans;
	if(x==1) ans=0;
	else if(x==2) ans=1;
	else if(x>=3) ans=func(x-1)+func(x-2);
	return ans;
} int n,ans=0,temp=0;
int main()
{ scanf("%d",&n);
	for(int i=1; ; i++){
		if(temp>n){ans-=2; break;}
		else {ans++; temp+=func(i);}
	} printf("%d\n",ans);
	return 0;
} 
