#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int ans(0); int n, m;
const int minASCII = int('0');
int maxASCII;
bool isWord(false);
const int minWord = int('A');
int maxWord;
bool CheckC(char c);
bool CheckS(char c[]);
int main(){scanf("%d%d", &n, &m); char ct = getchar();
	if(m<=10)maxASCII = minASCII - 1 + m;
	else{isWord = true; maxASCII = '9'; maxWord = minWord - 1 + m - 10;}
	for(int i=1; i<=n; i++){
		char c[110]; gets(c);
		if(CheckS(c))++ans;
	}printf("%d\n",ans);
	return 0;
}
bool CheckC(char c){
	return (c >= minASCII && c <= maxASCII) || (c >= minWord && c <= maxWord);
}
bool CheckS(char c[]){
	bool flag(true);
	for(int i=0; i<strlen(c); i++){
		if(!CheckC(c[i])){flag = false; break;}
	}return flag;
}

