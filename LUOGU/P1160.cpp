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
#include<iterator>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
bool unexist[110000];
vector<int>::iterator _pos[110000];
vector<int>que;
int main(){
    int n(read());
    que.push_back(1);
    _pos[1] = que.begin();
    for(int i = 2; i <= n; ++i){
        int k(read()); int pos(read());
        que.insert(next(_pos[k], pos), i);
        _pos[i] = next(_pos[k], pos);
        //TODO
        
        /*for(vector<int>::iterator itea = que.begin(); itea != que.end(); ++itea){
            if(*itea == k){que.insert(next(itea, pos), i); break;}
        }*/
    }
    int m(read());
    for(int i = 1; i <= m; ++i)unexist[read()] = true;
    for(vector<int>::iterator itea = que.begin(); itea != que.end(); ++itea){
        if(!unexist[*itea])printf("%d ", *itea);
    }printf("\n");

    system("pause");
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
