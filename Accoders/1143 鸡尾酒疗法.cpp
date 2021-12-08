//1043 ¼¦Î²¾ÆÁÆ·¨
#include<iostream>
using namespace std;
int main()
{
	int n,i;
	double x,y;
	int a,b;
	cin>>n;
	cin>>a>>b;
	x=b*100.0/a;
	for(i=2;i<=n;i++)
	{
		cin>>a>>b;
		y=b*100.0/a;	
	if(y-x>5)	
	     cout<<"better"<<endl;
	else if(x-y>5)
	      cout<<"worse"<<endl;
	else
	     cout<<"same"<<endl;
	     }
	return 0;
	}

