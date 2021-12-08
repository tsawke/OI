//1152 最接近的数
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1004];
int main()
{
    int i,j,n,k,k1,k2,sum;
    
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]); 
    
    for(int i=1;i<=n-1;i++)
    for(int j=i+1;j<=n;j++)
        if(a[j]<a[i]) swap(a[j],a[i]);
    
    int p=2147483647; 
    for(int i=n;i>=2;i--)
    {
        k=a[i]-a[i-1];
		if(k<=p) 
		{p=k;k1=a[i-1];k2=a[i]; }
	
	}
	
	printf("%d %d",k1,k2);
}



 
