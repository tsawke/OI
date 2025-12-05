//2893 Çóf(x,n) 
#include<bits/stdc++.h>
using namespace std;

double func(double x,double n){
	double ans;
	if(n==0) return x;
	else ans=sqrt(n+func(x,n-1));
	return ans;
}

int main()
{
	double x,n;
	scanf("%lf %lf",&x,&n);
	printf("%.2lf\n",func(x,n));
	return 0;
}
