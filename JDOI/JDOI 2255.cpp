#include <stdio.h>
#include <math.h>
long long add(long long, long long);
int main(){
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", add(a, b));


//    system("pause");
    return 0;
}
long long add(long long a, long long b){
	if(!b)return a;
	long long x = a ^ b;
	unsigned long long y = (unsigned long long)((a & b) << 1);
	return add(x, y);
}
