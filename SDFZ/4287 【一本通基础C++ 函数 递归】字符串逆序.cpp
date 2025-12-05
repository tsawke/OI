#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char c[1100];
void func(int n){
	if(c[n]!='!')func(n+1);
	else return ;
	printf("%c",c[n]);
}
int main(){gets(c);
	func(0);
	
	return 0;
}
