#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
class make{
	public:
		void change();
		void show();
		char c[110];
		int len;
}str;
void make ::change(){
	this -> len = strlen(this -> c+1);
	char z = this -> c[len];
	char y = this -> c[len-1];
	char x = this -> c[len-2];
	if((y == 'e' && z == 'r') || (y == 'l' && z == 'y'))len-=2;
	else if(x == 'i' && y == 'n' && z == 'g')len-=3;
}
void make ::show(){
	for(int i=1; i<=this -> len; i++)printf("%c",this -> c[i]); puts("");
}
int main(){gets(str.c+1);
	str.change();
	str.show();
	return 0;
}

