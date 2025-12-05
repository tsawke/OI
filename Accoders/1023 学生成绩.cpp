//1023 Ñ§Éú³É¼¨
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() 
{
	int a;
	cin>>a;
if(a>89)
{
	cout<<"A";
}
else
{
if((a>79)&&(a<90))
{
	cout<<"B";
}
else
{
if((a>69)&&(a<80))
{
	cout<<"C";
}
else
{
if((a>59)&&(a<70))
{
	cout<<"D";
}
else
{
if(a<60)
{
	cout<<"E";
}
else
{
	cout<<"?";
}
}
}
}
}
    return 0;
} 
