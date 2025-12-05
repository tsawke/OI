//1039 ×î´óÖµ 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,i,max;
	cin>>n>>max;
	i=2;
	for( ; i<=n; i++)
	{
		cin>>x;
	if(x>max)
	    max=x;
	}
    cout<<max;
    return 0;
}
