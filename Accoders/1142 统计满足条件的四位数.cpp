//1142 ͳ��������������λ��
#include<iostream>
using namespace std;
int main()
{
	int n,x,i,f=0;
	cin>>n;
	i=1;
	for( ; i<=n; i++)
	{
		cin>>x;
		if((x%10-x/1000%10-x/100%10-x/10%10)>0)
		{
			f++;
		}
	}
	cout<<f; 
	return 0;
} 
