//1902 完美立方
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int n;
	scanf("d",&n);
	int a,b,c,d;
	for(a=2; a<n; a++)
	{
		for(b=2; b<n; b++)
		{
			for(c=b; c<a; c++)
			{
				for(d=c; d<a; d++)
				{
					if((a*a*a)==(b*b*b+c*c*c+d*d*d) && a<n && b<n && c<n && d<n)
					{
						if(a==n)
						{
						    continue;
						}
						else
						{
							printf("%s%d%s %s%d,%d,%d%s\n","Cube = ",a,",","Triple = (",b,c,d,")");
						}
						
					}
				}
			}
		}
	}
	return 0;
 } 
