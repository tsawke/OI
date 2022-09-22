#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
typedef unsigned long long unll;
inline void readLL(unll&);
inline void read(int&);
int n;
bool composite[110000];
vector<int> prime;
int sum(0);
int main(){
    read(n);
    composite[1] = true;
    for(int i = 2; i <= n; ++i){
    	if(!composite[i])prime.push_back(i);
    	for(vector<int>::iterator itea = prime.begin(); itea < prime.end() && *itea * i <= n; ++itea){
    		composite[*itea * i] = true;
    		if(!(i % *itea))break;
		}
	}
    for(vector<int>::iterator itea = prime.begin(); itea < prime.end(); ++itea)printf("%d\n", *itea);
//    system("pause");
    return 0;
}

inline void readLL(unll& p){
    p = 0;
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p *= 10, p += (c - '0');
		c = getchar();
		p *= flag;
	}
}
inline void read(int& p) {
	p = 0;
	int flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p *= 10, p += (c - '0');
		c = getchar();
		p *= flag;
	}
}

