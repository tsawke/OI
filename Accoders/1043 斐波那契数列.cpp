//1043 ì³²¨ÄÇÆõÊıÁĞ
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,i,f1,f2,x;
    cin>>n;
    f1=1;
    f2=1;
if(n==1)
{
	cout<<f1; 
}
else
{
	cout<<f1<<" "<<f2<<" ";
}
    i=3;
for( ; i<=n; i++)
{
	x=f2;
	f2=f1+f2;
	f1=x;
	cout<<f2<<" ";
}
	return 0;
} 
