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
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
struct Data{
    int n;
    int value;
    Data(int, int);
};
vector<Data>temp;
vector< vector<Data> >v(110000, temp);
int main(){
    int n(read()), q(read());
    for(int i = 1; i <= q; ++i){
        int f(read());
        if(f == 1){
            int _i(read()), _j(read()), value(read());
            Data t(_j, value);
            v.at(_i - 1).push_back(t);
        }else if(f == 2){
            int _i(read()), _j(read());
            for(vector<Data>::reverse_iterator itea = v.at(_i - 1).rbegin(); itea != v.at(_i - 1).rend(); ++itea){
				if((*itea).n == _j){printf("%d\n", (*itea).value); break;}
			}
        }
    }
	
    system("pause");
    return 0;
}
Data::Data(int n, int value){
    this -> n = n;
    this -> value = value;
}template <typename T = int>
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
