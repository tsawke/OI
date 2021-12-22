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
#define PI double(3.14159)
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
vector< pair<int, int> >values;
class CIRCLE{
	public:
		pair<int, int>pos;
		double R = 0.000;
		bool extended = false;
}circle[20];
int n;
int base(0);
int maxS(INT_MIN);
int x1, y1_, x2, y2;
void dfs(int);
double CalMaxExtent(int);
int main(){
	n = read();
    x1 = read(), y1_ = read(), x2 = read(), y2 = read();
	if(x1 > x2)swap(x1, x2);
	if(y1_ > y2)swap(y1_, y2);
	const int height = abs(x2 - x1), width = abs(y2 - y1_);
	const double squareS = height * 1.00 * (width * 1.00);
	base = min(base, min(x1, min(x2, min(y1_, y2))));
    for(int i = 1; i <= n; ++i){
		int x = read(), y = read();
		values.push_back(pair<int, int>(x, y));
		base = min(base, min(x, y));
	}++base;
	x1 += base, x2 += base, y1_ += base, y2 += base;
	int count_(0);
	for(auto itea = values.begin(); itea != values.end(); ++itea){
		itea->first += base; itea->second += base;
		circle[++count_].pos = *itea;
	}
	// for(auto i : values){
	// 	int x , y;
	// 	tie(x, y) = i;
	// 	printf("Values: %d %d\n", x, y);
	// }
	dfs(1);
	double finalAns = squareS * 1.00 - (maxS * 1.00);
	printf("%.0lf\n", finalAns);
    return 0;
}
double CalMaxExtent(int n){
	int x, y;
	tie(x, y) = ::circle[n].pos;
	// printf("All Coord: n: %d %d   x1y1 %d %d   x2y2 %d %d\n", x, y, ::x1, ::y1_, ::x2, ::y2);
	double ret = min(x * 1.00 - ::x1, min(::x2 - x * 1.00, min(y * 1.00 - ::y1_, ::y2 - y * 1.00)));
	// printf("Return Value After Check Range:%lf\n", ret);
	for(int i = 1; i <= ::n; ++i){
		if(i == n)continue;
		//TODO Judge if circle in circle



		int delta_x(abs(::circle[i].pos.first - x));
		int delta_y(abs(::circle[i].pos.second - y));
		double d(sqrt(delta_x * 1.00 * (delta_x * 1.00) + delta_y * 1.00 * (delta_y * 1.00)));
		double maxR = d * 1.00 - ::circle[i].R * 1.00;
		// printf("CalPos %d:  no.%d  d_x=%lf  d_y=%lf  d=%lf maxR=%lf\n", n, i, delta_x, delta_y, d, maxR);
		ret = min(ret, maxR);
	}
	// printf("Return Value:%lf\n", ret);
	if(ret < 0.00)ret = 0.00;
	return ret;
}
void dfs(int deep){
	if(deep > ::n){
		int S(0);
		for(int i = 1; i <= n; ++i)
			S += ::circle[i].R * ::circle[i].R * PI;
		::maxS = max(::maxS, S);
		// printf("nowS: %lf\n", S);
		return;
	}
	for(int i = 1; i <= ::n; ++i){
		if(!::circle[i].extended){
			::circle[i].extended = true;
			::circle[i].R = CalMaxExtent(i);
			dfs(deep + 1);
			::circle[i].R = 0.000;
			::circle[i].extended = false;
		}
	}
}
template <typename T = int>
inline T read(void){
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
//TODO