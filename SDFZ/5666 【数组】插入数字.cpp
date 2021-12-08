#include <cstdio>
#include <algorithm>
using namespace std;
int a[110],in,p=-1;
int main(){
	for(int i=1; i<=9; i++)scanf("%d",a+i); scanf("%d",&in);
	for(int i=1; i<=8; i++){
		if(in>=a[i] && in<=a[i+1]) p=i;
	}if(p==-1)p=9;
	for(int i=1; i<=9; i++){
		printf("%d\n",a[i]);
		if(i==p)printf("%d\n",in);
	}
	return 0;
}
