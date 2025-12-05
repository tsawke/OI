//1071: 数组合并
#include<iostream>
using namespace std;
int a[50100],b[50100],c[100100];
int main()
{
    int m,n,i=1,j=1,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    	cin>>a[i];
    for(j=1;j<=m;j++)
    	cin>>b[j];
    k=0;i=1;j=1;
    while(i<=n&&j<=m)
     {
	k++;
	if(a[i]==b[j])
	{c[k]=a[i];  
          i++;j++;continue;}
	if(a[i]<b[j])
	{ c[k]=a[i++];continue;}
        if(a[i]>b[j])
        { c[k]=b[j++];continue;}
	}	
	while(i<=n)
	  c[++k]=a[i++];
	while(j<=m)
	  c[++k]=b[j++];
	cout<<k<<endl;	
	for(int i=1;i<=k;i++)
	  cout<<c[i]<<" ";
	return 0;
}

