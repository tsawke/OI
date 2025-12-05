#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char sBefore[110], sChange[110];
char sInput[210];
char word[110][110];
int n(0);
int main(){
	//scanf("%s %s %s",sInput, sBefore, sChange);
	gets(sInput+1); gets(sBefore+1); gets(sChange+1); 
	for(int i=1; i<=strlen(sInput+1)-1; i++){
		if(sInput[i] == ' ' || sInput[i] == '\n' || sInput[i] == '\0' || sInput[i] == EOF)continue;
		char c[110]; memset(c, '\0', sizeof(c));
		int now(1); c[now] = sInput[i];
		bool flag(true);
		for(int j=i+1; j<=strlen(sInput)-1; j++){
			if(sInput[j] == ' ' || sInput[j] == '\n' || sInput[j] == '\0' || sInput[j] == EOF){flag=false; break;}
			++now; c[now] = sInput[j]; i=j+1;
		}
		if(!strcmp(sBefore+1, c+1)){++n; strcpy(word[n]+1, sChange+1);}
		else {++n; strcpy(word[n]+1, c+1);}
	}
	for(int i=1; i<=n; i++){
		printf("%s%c", word[i]+1, i!=n?' ':'\n');
	}
	return 0;
}

