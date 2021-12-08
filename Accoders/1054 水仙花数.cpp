//1054 Ë®ÏÉ»¨Êý
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i;
	i=100;
	for( ; i<=999; i++)
	{
		const int A=i%10;
		const int B=i/10%10;
		const int C=i/10/10%10;
		const int X=A*A*A+B*B*B+C*C*C;
		if(i==X)
			cout<<i<<endl;
	}
	return 0;
}
