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
	return 0;
}
void Index_ ::InIt(){
	char c[11000];
	while(gets(c + 1)){
		memset(this -> dp, -1, sizeof(this -> dp));
		memset(this -> CX, '\0', sizeof(this -> CX));
		memset(this -> CY, '\0', sizeof(this -> CY));
		char CT[210]; int now(0); memset(CT, '\0', sizeof(CT)); now = 0;
		while(c[++now] != ' ' && c[now] != '\n' && c[now] != '\0' && c[now] != EOF)CT[now] = c[now];
		strcpy(this -> CX + 1, CT + 1); this -> lenx = strlen(this -> CX + 1);
		while(c[now++] == ' ' || c[now] == '\n' || c[now] == '\0' || c[now] == EOF); --now;
		char CT2[210]; memset(CT2, '\0', sizeof(CT2)); int now2(0);  now2 = 0; --now;
		while(c[++now] != ' ' && c[now] != '\n' && c[now] != '\0' && c[now] != EOF)CT2[++now2] = c[now];
		strcpy(this -> CY + 1, CT2 + 1); this -> leny = strlen(this -> CY + 1);
		this -> make();
	}
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

