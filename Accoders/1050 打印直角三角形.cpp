//1050 ��ӡֱ��������
#include<iostream>
using namespace std;
int main()
{
	int n,i,j;//i��ʾ������ 
	cin>>n;
	i=1;
	for( ; i<=n; i++)
	{
		j=1;
		for( ; j<=i; j++)
		{
			cout<<"*";
		}
		j=0;
		cout<<endl;
	}
	return 0;
} 
