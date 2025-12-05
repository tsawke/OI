#include <bits/stdc++.h>
using namespace std;
char c[11000]; int word=1,letter=0; 
int main() { gets(c);
	for(int i=0; i<strlen(c); i++){
		if(c[i]!=' ' && c[i]!='.') letter++;
		else if(c[i]==' ') word++;
		else if(c[i]=='.') break;
	} //printf("test&   word=%d;  letter=%d; \n",word,letter);
	printf("%.1lf\n",letter*1.0/word);
	return 0;
} 
