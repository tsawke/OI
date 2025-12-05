//1035 Êä³öÅ¼Êı
#include <stdio.h>

int main()
{
	int a,b,i;
	
	scanf("%d %d",&a,&b);
	
	if(a<1){
		a=1;
	}
	if(b<1){
		b=1;
	}
	
	for(i=a;i<=b&&i<=1000000;i=i+1){
		if(i%2==0){
		printf("%d\n",i);}
	}
	
}
