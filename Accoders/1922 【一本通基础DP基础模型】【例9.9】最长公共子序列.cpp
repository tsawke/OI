#include <cstdio>
#include <algorithm>
#include <climits>
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
typedef unsigned long long unll;
class Index_{
	private:
		char CX[210];
		char CY[210];
		int dp[210][210];
		int lenx;
		int leny;
	protected:
	public:
		void InIt();
		void make();
}index_;

int main(){
	index_.InIt();
	index_.make();
	return 0;
}
void Index_ ::InIt(){
	memset(this -> dp, -1, sizeof(this -> dp));
	gets(this -> CX + 1);
	gets(this -> CY + 1);
	this -> lenx = strlen(this -> CX + 1);
	this -> leny = strlen(this -> CY + 1);
}
void Index_ ::make(){
	for(int i=0; i<=this -> lenx; ++i){
		for(int j=0; j<=this -> leny; ++j){
			if(!i || !j)this -> dp[i][j] = 0;
			else if(this -> CX[i] == this -> CY[j])this -> dp[i][j] = this -> dp[i - 1][j - 1] + 1;
			else this -> dp[i][j] = max(this -> dp[i][j - 1], this -> dp[i - 1][j]);
		}
	}printf("%d\n", dp[lenx][leny]);
}

