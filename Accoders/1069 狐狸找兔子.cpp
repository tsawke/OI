//1069 КќРъевЭУзг
#include <iostream>
using namespace std;
int main()
{
	int n,m,d[1010]={1},j=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		d[i]=1;	
	for(int i=1;i<=m;i++)
	{
		j=(j+i)%n;
		if(j==0)
		      j=n;
		d[j]=0;
	}
	j=0;
	for(int i=1;i<=n;i++)
	if(d[i]==1)
	{
		j++;
		cout<<i<<" ";
	}
	if(j==0)
	      cout<<j;
	return 0;	
}
 
