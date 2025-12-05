#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a,b; char c;
int ans(int a,int b,char c){
	switch(c){
		case '+':{return a+b; break;} 
		case '-':{return a-b; break;}
		case '*':{return a*b; break;}
		case '/':{return a/b; break;}
	}
}
int main(){scanf("%d%d %c",&a,&b,&c);
	if(b==0 && c=='/'){printf("Divided by zero!\n"); return 0;}
	if(c!='+' && c!='-' && c!='*' && c!='/'){printf("Invalid operator!\n"); return 0;}
	printf("%d\n",ans(a,b,c)); return 0;
}
