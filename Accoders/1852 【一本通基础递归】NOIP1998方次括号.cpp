#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int n;
inline void L(); inline void R(); inline void P2();
void func(int n);
int main(){scanf("%d", &n);
	func(n);
	return 0;
}
void func(int n){
	if(n == 1){printf("2(0)"); return;}
	if(n == 2){P2(); return;}
	if(n == 3){printf("2+2(0)"); return;}
	int temp = 2;
	while(pow(2, temp) <= n)++temp;
	P2(); L(); func(temp-1); R();
	if(n > pow(2, temp-1)){printf("+"); func(n - pow(2, temp-1));}
}
inline void L(){printf("(");}
inline void R(){printf(")");}
inline void P2(){printf("2");}
