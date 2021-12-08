//2886 ì³²¨ÄÇÆõÊıÁĞ 
#include<bits/stdc++.h>
using namespace std;

int func(int x){
	int ans;
	if(x==1) ans=0;
	else if(x==2) ans=1;
	else if(x>=3) ans=func(x-1)+func(x-2);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<func(n)<<endl;
	return 0;
}
