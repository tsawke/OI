//1079 É¸ÍøÇóËØÊı
#include<iostream>
using namespace std;
int a[10001];
int main(){
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)	a[i]=i;
	for(i=2;i<=n;i++)	{
	   	if(a[i]!=1) 	{
	   		for(j=i+1;j<=n;j++)	{
		   		if(a[j]%a[i]==0)
		   			a[j]=1;
		   	}
	   	}
	}
	for(i=2;i<=n;i++)	{
		if(a[i]!=1)
			cout<<a[i]<<endl;
	}
	return 0;
}

