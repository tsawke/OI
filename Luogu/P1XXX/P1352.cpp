//C++11 - Template
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
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int N;
vector< int >vertex[6100];
int __index[6100];
pair<int, int> dfs(int, int);
int main(){
	N = read();
    for(int i = 1; i <= N; ++i)__index[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int from = read(), to = read();
        vertex[from].push_back(to);
        vertex[to].push_back(from);
    }
    int root = rand() % N + 1;
    int Rans, URans;
    tie(Rans, URans) = dfs(root, -1);
    printf("%d\n", max(Rans, URans));
    return 0;
}
pair<int, int>/*rooted, unrooted*/ dfs(int root, int father){
    int rootedIndex(__index[root]);
    int unrootedIndex(0);
    for(auto i : vertex[root]){
        if(i != father){
            int RI, URI;
            tie(RI, URI) = dfs(i, root);
            rootedIndex += URI;
            unrootedIndex += max(RI, URI);
        }
    }
    return make_pair(rootedIndex, unrootedIndex);
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