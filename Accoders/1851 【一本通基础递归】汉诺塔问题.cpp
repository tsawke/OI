#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
void show_mov(char from, char to, int num);
void mov(int n, char a, char b, char c);
char a, b, c; int n;
int main(){scanf("%d %c %c %c", &n, &a, &b, &c);
	mov(n, a, b, c);
	return 0;
}
void mov(int n, char a, char b, char c){
	if(!n)return;
	if(n == 1)show_mov(a, b, n);
	else{
		mov(n-1, a, c, b);
		show_mov(a,b,n);
		mov(n-1, c, b, a);
	}
}
void show_mov(char from, char to, int num){
	printf("%c->%d->%c\n", from, num, to);
}
