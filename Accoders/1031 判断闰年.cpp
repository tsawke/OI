//1031 ÅĞ¶ÏÈòÄê 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int year;
	cin>>year;
	if(year%100==0)
	{
		if(year%400==0)
		{
			cout<<"L";
		}
		else
		{
			cout<<"N";
		}
	}
	else
	{
		if(year%4==0)
		{
			cout<<"L";
		}
		else
		{
			cout<<"N";
		}
	}
    return 0;
} 
