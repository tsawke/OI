//1050 打印直角三角形
#include<iostream>
using namespace std;
int main()
{
	int n,i,j;//i表示多少行 
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
