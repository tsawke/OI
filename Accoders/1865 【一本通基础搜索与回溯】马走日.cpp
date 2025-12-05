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
//vector< vector<bool> > used(110, vector<bool>(110, false));
//vector< vector<bool> > ::iterator iter;
//vector< bool >temp;
//vector<bool> ::iterator iter_;
class Index_{
	private:
		int T;
		int height, width;
		int start_x, start_y;
		int ans;
		int move_x[10]={1,1,2,2,-1,-1,-2,-2};
		int move_y[10]={2,-2,1,-1,2,-2,1,-1};
		bool used[110][110];
	protected:
	public:
		void make(int, int, int);
		inline void InIt();
}index_;

int main(){
	index_.InIt();
	return 0;
}
void Index_ ::make(int sx, int sy, int sum){
	if(sum == this -> height * this -> width){++ans; return;}
	for(int i=0; i<8; i++){
		int movetoX = sx + this -> move_x[i];
		int movetoY = sy + this -> move_y[i];
//		iter = used.begin() + movetoX;
//		temp = *iter;
//		iter_ = temp.begin() + movetoY;
		if(movetoX >= 0 && movetoX < this -> height && movetoY >= 0 && movetoY < width && !used[movetoX][movetoY]){
//			*iter_ = true;
			used[movetoX][movetoY] = true;
			this -> make(movetoX, movetoY, sum + 1);
//			*iter_ = false;
			used[movetoX][movetoY] = false;
		}
	}
}
inline void Index_ ::InIt(){
	scanf("%d", &this -> T);
	for(int i=1; i<=this -> T; i++){
		scanf("%d%d%d%d", &this -> height, &this -> width, &this -> start_x, &this -> start_y);
		this -> make(this -> start_x, this -> start_y, 1);
		printf("%d\n", this -> ans);
		this -> ans = 0;
	}
}
