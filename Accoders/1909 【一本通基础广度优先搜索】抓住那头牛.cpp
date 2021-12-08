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
class Index_{
	private:
		int moveTimes[120000];
		deque< int >dq;
		int start, end;
	protected:
	public:
		void InIt();
		void bfs(int);
}index_;

int main(){
	index_.InIt();
	index_.bfs(1);
	return 0;
}
void Index_ ::InIt(){
	memset(this -> moveTimes, -1, sizeof(this -> moveTimes));
	scanf("%d%d", &this -> start, &this -> end);
	this -> dq.push_back(this -> start);
	this -> moveTimes[start] = 0;
}
void Index_ ::bfs(int times){
	while(!this -> dq.empty()){
		int moveFrom = *this -> dq.begin();
		this -> dq.pop_front();
		int move[5]={1, -1, 2};
		for(int i=0; i<=3 - 1; ++i){
			int moveTo = i!=2?(moveFrom + move[i]):(moveFrom * move[i]);
			if(moveTo >= 0 && moveTo <= 119000 && this -> moveTimes[moveTo] == -1){
				this -> dq.push_back(moveTo);
				this -> moveTimes[moveTo] = this -> moveTimes[moveFrom] + 1;
			}
		}if(this -> moveTimes[this -> end] != -1)break;
	}printf("%d\n", this -> moveTimes[this -> end]);
}
