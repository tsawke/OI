//1061 连续自然数和
#include<cstdio>
using namespace std;
int main(){
	int m,i,j,sum;
	scanf("%d",&m);
	for(i=1;i<m;i++)	{
		sum=0;
		for(j=i;j<m;j++)
		{
			sum=sum+j;
			if(sum==m)
			{
				printf("%d %d\n",i,j);
				break;
			}
			if(sum>m)
				break;
		}
	}	
	return 0;
}
 
