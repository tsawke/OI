//1908 Îå»§¹²¾® 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring> 
using namespace std;

int main()
{
	int k,n1,n2,n3,n4,n5;
	int len,s1,s2,s3,s4,s5;
	scanf("%d %d %d %d %d %d %d",&k,&n1,&n2,&n3,&n4,&n5);
	
	for(len=1; len<=100*k; len++)
	{
		for(s1=1; s1<=len; s1++)
		{
			s2=len-n1*s1;
			s3=len-n2*s2;
			s4=len-n3*s3;
			s5=len-n4*s4;
			
			if(s1<0 || s2<0 || s3<0 || s4<0 || s5<0) continue;
			if(s1==s2 || s1==s3 || s1==s4 || s1==s5) continue;
			if(s2==s3 || s2==s4 || s2==s5) continue;
			if(s3==s4 || s3==s5) continue;
			if(s4==s5) continue;
			
			if(len==n5*s5+s1)
			{
				printf("%d %d %d %d %d %d\n",len,s1,s2,s3,s4,s5);
				return 0;
			}
		}
	}
}
