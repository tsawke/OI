//1155 七位完全平方数
#include<iostream>
using namespace std;
int main() 
{
	int a[10]={0};
	int i,j,n,f;
	int hr=0;
	for(i=1000;i<3200;i++)
	{
		for(j=0;j<10;j++)
			a[j]=0;
		n=i*i;
		if(n>9999999)
			break;
		f=1;		
	while(n)
	{
 	     a[n%10]=a[n%10]+1;
	     if(a[n%10]>1)
		f=0;
	       n=n/10;
	   }
	  if(f==1)
	{
		cout<<i*i<<" ";
		hr++;
		if(hr>=10)
		{
			cout<<endl;
			hr=0;
		}
	}		
    }	
	return 0;
}
 
