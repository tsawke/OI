//1059 Çós=a+aa+aaa+aaaa+aa...aµÄÖµ
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,i,x,y;
	cin>>a>>n;
	i=1;
	x=0;
	y=1;
for( ; i<=n; i++)
{
	x=x+a*y;
	y=y*10+1;
}
    cout<<x;
    return 0;
} 
