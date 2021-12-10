#pragma GCC optimize(2)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;
typedef unsigned long long unll;
template <typename T = int>
inline T read(void);
vector<int>list;

int main(){
	int n(read());
	for(int i = 1; i <= n; ++i)list.push_back(i);
	int count(0);
	vector<int>::iterator p = list.begin() - 1;
	while(list.size() > 1){
		if(distance(p, list.end() - 1) >= 3)advance(p, 3);
		else{
			int mov = 3 - distance(p, list.end() - 1) - 1;
			p = list.begin();
			while(mov){
				if(distance(p, list.end() - 1) >= mov){advance(p, mov); break;}
				mov -= (distance(p, list.end() - 1) + 1);
//				printf("Now mov = %d\n", mov);
			}
		}
		list.erase(p);
		--p;
//		if(p == list.end())p = list.begin();
//		for(auto i : list)printf("%d ", i);
//		puts("");
	}
	printf("%d\n", *list.begin());

//    system("pause");
    return 0;
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
