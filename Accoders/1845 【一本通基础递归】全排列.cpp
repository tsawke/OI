#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;
class Str{
	private:
		bool used[1100];
		char c[1100];
		char ans[1100];
		int len;
	public:
		void InIt();
		void dfs(int deep);
}str;
void Str ::InIt(){
	for(int i=1; i<=1010; i++)this -> used[i] = false;
	gets(this -> c + 1);
	this -> len = strlen(c + 1);
}
void Str ::dfs(int deep){
	for(int i=1; i<=this -> len; i++)
	if(!this -> used[c[i]]){
		this -> used[c[i]] = true;
		this -> ans[deep] = this -> c[i];
		if(deep == this -> len){
			for(int i=1; i<=this -> len; i++)printf("%c", this -> ans[i]);
			printf("\n"); this -> used[c[i]] = false; return;
		}dfs(deep + 1); this -> used[c[i]] = false;
	}
}
int main(){
	str.InIt();
	str.dfs(1);
	return 0;
}

