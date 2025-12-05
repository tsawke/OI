	#include <bits/stdc++.h>
	using namespace std;
	
	int main()
	{
		stack<char>s; char a[111000];
		gets(a);// s.push(a[1]);
		for(int i=0; i<strlen(a); i++){
			if(a[i]=='(' || a[i]=='[') s.push(a[i]);
			else if(a[i]==')'){
				if(s.empty()) {printf("Wrong\n"); exit(0);}
				if(s.top()=='(') s.pop();
				else {printf("Wrong\n"); exit(0);}
			} 
			else if(a[i]==']'){
				if(s.empty()) {printf("Wrong\n"); exit(0);}
				if(s.top()=='[') s.pop();
				else {printf("Wrong\n"); exit(0);}
			}
		}
		if(s.empty()) printf("OK\n");
		else printf("Wrong\n");		
		return 0;
	} 
