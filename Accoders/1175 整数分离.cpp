//1175 ÕûÊı·ÖÀë 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int digit(int n,int k)
{
	int i;
	i=1;
	for( ; i<k; i++)
	{
		n=n/10;
	}
	return n%10;
}

int main()
{
	int n,k; 
	cin>>n>>k;
	cout<<digit(n,k)<<endl;

	return 0;
} 
