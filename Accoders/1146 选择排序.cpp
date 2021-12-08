//1146 πÃ÷¥µƒ—°‘Ò≈≈–Ú
#include<iostream>
using namespace std;
int main()
{
	int a[10],i,j,k,t;
	for(i=0;i<10;i++)
		cin>>a[i];
	for(i=0;i<9;i++)
	{
		k=i;
		for(j=i+1;j<10;j++)
		{
			if(a[j]>a[k])
				k=j;
		}
		if(k!=i)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
}
 
