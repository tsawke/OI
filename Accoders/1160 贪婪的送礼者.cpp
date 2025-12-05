//1160 Ì°À·µÄËÍÀñÕß
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char name[11][100];
	int oldnum[11],newnum[11];
	char tname[100];
	int n,money,num,a,b,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",name[i]);
		oldnum[i]=0;
		newnum[i]=0;
    }
for(i=1;i<=n;i++)
{
    scanf("%s",tname);
    scanf("%d %d",&money,&num);
    if(num==0) 
   {
	a=money;
	b=0;
	for(j=1;j<=n;j++)
	if(strcmp(tname,name[j])==0)
	{
  	   oldnum[j]=money;
	//   newnum[j]=newnum[j]+b;
	}
     }
else
{
    a=money/num;
    b=money%num;
    for(j=1;j<=n;j++)
       if(strcmp(tname,name[j])==0)
        {
            oldnum[j]=money;
            newnum[j]=newnum[j]+b;
        }		
       for(j=1;j<=num;j++) {	
           scanf("%s",tname);
               for(k=1;k<=n;k++)
	if(strcmp(tname,name[k])==0)
                newnum[k]=newnum[k]+a;
	}
         }
}	
for(i=1;i<=n;i++)
   printf("%s %d\n",name[i],newnum[i]-oldnum[i]);
	return 0;	
}

