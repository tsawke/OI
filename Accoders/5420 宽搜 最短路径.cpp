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
class coord{
	public:
		int x;
		int y;
};
class Index_{
	private:
		int movex[10]={1,1,2,2,-1,-1,-2,-2};
		int movey[10]={2,-2,1,-1,2,-2,1,-1};
		int moveTimes[2100][2100];
		int n;
		deque< coord > dq;
		coord start, end;
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
	scanf("%d", &this -> n);
	memset(this -> moveTimes, -1, sizeof(this -> moveTimes));
	scanf("%d%d%d%d", &this -> start.x, &this -> start.y, &this -> end.x, &this -> end.y);
	this -> moveTimes[this -> start.x][this -> start.y] = 0;
	this -> dq.push_back(this -> start);
}
void Index_ ::make(){
	while(!this -> dq.empty()){
		coord moveFrom = this -> dq.front();
		this -> dq.pop_front();
		for(int i=0; i<=8 - 1; ++i){
			coord moveTo;
			moveTo.x = moveFrom.x + this -> movex[i];
			moveTo.y = moveFrom.y + this -> movey[i];
			if(moveTo.x >= 0 && moveTo.x < this -> n && moveTo.y >= 0 && moveTo.y < this -> n && this -> moveTimes[moveTo.x][moveTo.y] == -1){
				this -> dq.push_back(moveTo);
				this -> moveTimes[moveTo.x][moveTo.y] = this -> moveTimes[moveFrom.x][moveFrom.y] + 1;
			}
		}if(this -> moveTimes[this -> end.x][this -> end.y] != -1)break;
	}printf("%d\n", this -> moveTimes[this -> end.x][this -> end.y]);
}
