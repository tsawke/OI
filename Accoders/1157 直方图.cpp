//1157 Ö±·½Í¼
#include<iostream>
using namespace std;
int a[100001];

int main()
{
	int n,max=0,m,i;
	cin>>n;
	for(i=0;i<n;i++)
	{	
		cin>>m;
		if(m>max)
			max=m;
		a[m]=a[m]+1;
	}
	for(i=0;i<=max;i++)
	{
		cout<<a[i]<<endl;
	}
	
	return 0; 
}

