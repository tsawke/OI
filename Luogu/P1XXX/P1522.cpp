//C++11
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
#include <functional>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
class Pasture{
public:
    Pasture(pair<int, int>);
	void InitPos(pair<int, int>);
	void addEdge(int);
	vector<int>& GetToPastue(void);
	const pair<int, int>& GetPos(void);
protected:
private:
    pair<int, int>pos;
    vector<int>toPasture; 
}pasture[210];
int n;
double CalDiam(void);//Calculate Diameter
int main(){
	n = read();
	for(int i = 1; i <= n; ++i){
		int x = read(), y = read();
		pasture[i].InitPos(pair<int, int>(x, y));
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			bool flag = bool(int(getchar() - '0'));
			if(flag)
				pasture[i].addEdge(j);
		}char c_temp = getchar();
	}
//TODO Completion Required

    return 0;
}
double CalDiam(void){
	
}
const pair<int, int>& Pasture::GetPos(void){
	return this->pos;
}
vector<int>& Pasture::GetToPastue(void){
	return this->toPasture;
}
void Pasture::InitPos(pair< int, int >pos){
	this->pos = pos;
}
void Pasture::addEdge(int toPasture){
	this->toPasture.push_back(toPasture);
}
Pasture::Pasture(pair<int, int>_pos):pos(_pos){;}
template <typename T = int>
inline T read(void)
{
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}