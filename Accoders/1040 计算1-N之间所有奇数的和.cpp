//1040 计算1-N之间所有奇数的和
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
