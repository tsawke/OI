//1040 ����1-N֮�����������ĺ�
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,all,N;
	cin>>n;
	all=0;
if(n%2==0)
{
	N=((n-1)-1)/2+1;
	all=(1+(n-1))*N/2;
}
else
{
	N=(n-1)/2+1;
	all=(1+n)*N/2;
}
    cout<<all;
    return 0;
} 
