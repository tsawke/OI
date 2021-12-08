#include <bits/stdc++.h>
using namespace std;

int a[300],b[300],c[300];
char s1[300],s2[300],s[300];

int main()
{
	ios::sync_with_stdio(false);
	cin>>s1>>s2;
	int la,lb,len;
	la=strlen(s1);
	lb=strlen(s2);
	for(int i=1; i<=la; i++) a[i]=s1[la-i]-'0';
	for(int i=1; i<=lb; i++) b[i]=s2[lb-i]-'0';
	for(int i=1; i<=la; i++)
		for(int j=1; j<=lb; j++){
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	len=la+lb;
	while(c[len]==0 && len>1) len--;
	for(int i=len; i>=1; i--) cout<<c[i]; 
	
	return 0;
}
