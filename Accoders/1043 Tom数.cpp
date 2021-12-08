//1043 TomÊı
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() 
{
	long long n,s=0;
	cin>>n;
while(n>0)
{
	s=s+n%10;
	n=n/10;
}
    cout<<s; 
	return 0;
}
