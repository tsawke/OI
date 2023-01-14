#include <bits/stdc++.h>
using namespace std;
mt19937 myrand(time(0));
int Rand(int x,int y)
{
	unsigned a=myrand();
	return a%(y-x+1)+x;
}
void data(int n)
{
	FILE *fp=fopen("D.in","w");
	int K=Rand(1,100000000);
	fprintf(fp,"%d %d\n",n,K);
	for(int i=1;i<=n;i++)
	{
		fprintf(fp,"%d ",Rand(1,10000000));
	}
	fclose(fp);
}
int main()
{
	data(Rand(3500000,4000000));
	/*for(int i=1;i;i++)
	{
		data();
		system("x <D.in >x.out");
		system("D <D.in >d.out");
		if(system("fc x.out d.out >lj.out"))
		{
			printf("WA on #%d\n",i);
			return 0;
		}
		printf("AC on #%d\n",i);
	}*/
}