//1032 ½±½ð 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x;
	scanf("%lf",&x);
	if(x<=100000)
	{
		printf("%0.0lf",x*0.1);
	}
	else
	{
		if(x>100000 && x<=200000)
		{
			printf("%0.0lf",10000+((x-100000)*0.075));
		}
		else
		{
			if(x>200000 && x<=400000)
			{
				printf("%0.0lf",10000+7500+(x-200000)*0.05);
			}
			else
			{
				if(x>400000 && x<=600000)
				{
					printf("%0.0lf",10000+7500+10000+(x-400000)*0.03);
				}
				else
				{
					if(x>600000 && x<=1000000)
					{
						printf("%0.0lf",10000+7500+10000+6000+(x-600000)*0.015);
					}
					else
					{
						printf("%0.0lf",10000+7500+10000+6000+9000+(x-1000000)*0.01);
					}
				}
			}
		}
	}
    return 0;
} 
