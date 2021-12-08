#include <cstdio>
#include <algorithm>
#include <ctype.h>
#include <cstring>
using namespace std;
class make{
	public:
		void change();
		void change_();
		void change__();
		void show();
		char c[110];
}str;
void make ::change(){
	for(int i=1; i<=strlen(this -> c+1); i++){
		char &ct = this -> c[i];
		if(ct >= 'A' && ct <= 'Z')ct = ct + ('a' - 'A');
		else if(ct >= 'a' && ct <='z')ct = ct - ('a' - 'A');
	}
}
void make ::change_(){
	char ct[110];
	strcpy(ct+1, this -> c+1);
	int len = strlen(ct+1);
	for(int i=1; i<=len/2; i++)swap(ct[i], ct[len+1-i]);
	strcpy(this -> c+1, ct+1);
}
void make ::change__(){
	for(int i=1; i<=strlen(this -> c+1); i++){
		this -> c[i] += 3;
	}
}
void make ::show(){
	puts(this -> c+1);
}
int main(){gets(str.c+1);
	str.change();
	str.change_();
	str.change__();
	str.show();
	return 0;
}

