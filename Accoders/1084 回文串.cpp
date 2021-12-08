//1084 ╩ьнд╢╝
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,f=1;
	char a[300];
	cin>>a;
	i=0;
	for( ; i<strlen(a)/2; i++)
	{
		if(a[i]!=a[strlen(a)-1-i])
		{
			f=0;
			break;
		}
	}
	
	
	if(f==1)
	{
		cout<<"Y";
	}
	else
	{
		cout<<"N";
	}
	
	return 0;
	
} 
