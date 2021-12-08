//1062 求具有abcd=(ab+cd)^2性质的四位数
#include<iostream>
using namespace std;

int main()
{
	int i,a,b;
	for(i=1000;i<10000;i++)
	{
		a=i/100;
		b=i%100;
		if((a+b)*(a+b)==i)
			cout<<i<<" ";
		
	}
	
	return 0;
}

