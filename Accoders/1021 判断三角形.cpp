//1021 еп╤охЩ╫гпн
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() 
{
	int a,b,c;
	cin>>a>>b>>c;
if((a+b)>c)
{
if((a+c)>b)
{
if((b+c)>a)
{
	cout<<"yes";
}
else
{
	cout<<"no";
}
}
else
{
	cout<<"no";
}
}
else
{
	cout<<"no";
}
    return 0;
} 
