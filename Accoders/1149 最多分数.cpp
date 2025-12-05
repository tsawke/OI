//1149 最多分数 
#include<iostream>
using namespace std;
int a[110];
int main()
{
	int i,n,max=0;
	while(cin>>n)
	{
	    a[n]++;
	}
	for(i=0; i<101; i++)
	{
		if(a[i]>max)
		    max=a[i];
	}
	for(i=0; i<101; i++)
	{
		if(a[i]==max)
		    cout<<i<<" ";
	}
	return 0;
}
