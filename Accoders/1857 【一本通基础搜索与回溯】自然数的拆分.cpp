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
		int ans[11000]={1};
	public:
		int n;
		void InIt();
		void dfs(int deep, int all);
		void show(int deep);
}str;

int main(){
	str.InIt();
	str.dfs(1, str.n);
	return 0;
}
void Str ::InIt(){
	scanf("%d",&this -> n);
}
void Str ::show(int deep){
	for(int i=1; i<=deep; i++)printf("%d%c", this -> ans[i], i==deep?'\n':'+');
}
void Str ::dfs(int deep, int all){
	int i;
	for(int i=ans[deep - 1]; i<=all; i++)
	if(i < this -> n){
		this -> ans[deep] = i;
		all -= i;
		if(!all)this -> show(deep);
		else dfs(deep + 1, all);
		all += i;
	}return;
}
