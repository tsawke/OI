//1064 ÄæĞòÊä³ö
#include<iostream>
using namespace std;
int main() 
{
	int a[10],i,j;
    i=0;
for( ; i<=9; i++)
{
	cin>>a[i];
}
    j=9;
for( ; j>=0; j--)
{
	cout<<a[j];
	if(j==0)cout<<endl;
	else cout<<" ";
}
	return 0;
}
