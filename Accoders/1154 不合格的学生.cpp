//1154 不合格的学生
#include<iostream>
using namespace std;
int main()
{
	int a[1000],n,i,sum=0;
	double avg;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]; 
		sum=sum+a[i];
	}
	avg=sum*1.0/n;
	for(i=1;i<=n;i++)
	{
		if(a[i]<avg)
		{
			cout<<i<<" "<<a[i]<<endl;
		}		
	}	
	return 0;
}
 
