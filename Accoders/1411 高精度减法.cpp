#include <bits/stdc++.h>
using namespace std;

int a[110000],b[110000],c[110000],jin=0,la,lb,lc;
char s1[110000],s2[110000],s[110000];

int main()
{
	gets(s1);
	gets(s2);
	if(strcmp(s1,s2)==0) {printf("0\n"); return 0;}
	if(strlen(s1)<strlen(s2) || (strlen(s1)==strlen(s2) && strcmp(s1,s2)<0)){
		strcpy(s,s1);
		strcpy(s1,s2);
		strcpy(s2,s);
		cout<<"-";
	}
	la=strlen(s1);
	lb=strlen(s2);
	for(int i=0; i<la; i++) a[i]=s1[la-i-1]-'0';
	for(int i=0; i<lb; i++) b[i]=s2[lb-i-1]-'0';
	lc=la;
	for(int i=0; i<lc; i++){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
	}
	while(c[lc-1]==0 && lc>0)
	{
		if(lc==0){ 
			printf("0\n");
			return 0;
		}
		else lc--;
	} 
	for(int i=lc-1; i>=0; i--) printf("%d",c[i]);
	printf("\n");
	return 0;
} 
