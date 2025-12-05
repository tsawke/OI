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
int n;
int root;
vector< int > vertex[210];
void prev(int);
int main(){
    n = read();
    for(int i = 1; i <= n; ++i){
        string input;
        cin>>input;
        if(input.at(1) != '*')vertex[int(input.at(0))].push_back(int(input.at(1)));
        if(input.at(2) != '*')vertex[int(input.at(0))].push_back(int(input.at(2)));
        if(i == 1)root = int(input.at(0));
    }
    prev(root);
    printf("\n");
    return 0;
}
void prev(int root){
    printf("%c", char(root));
    for(auto i : vertex[root]){
        prev(i);
    }
}

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