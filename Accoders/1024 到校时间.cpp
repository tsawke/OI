//1024 到校时间 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	const int A=a*b;
	const int B=c*d;
if(A>B)
{
	cout<<B;
}
else
{
	cout<<A;
}
    return 0;
}
