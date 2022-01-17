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
vector< tuple<int, int, int>/*fromVertex, toVertex, wealth*/ >edge;
class Union_Find{
public:
    Union_Find(void);
    int Find(int);
    void Merge(int, int);
    int Kruskal(void);
private:
    int fa[5100];
    int size[5100];
}unionFind;
int n, m;
int main(){
    n = read(), m = read();
	for(int i = 1; i <= m; ++i){
        int from = read(), to = read(), wealth = read();
        edge.push_back(tuple<int, int, int>(from, to, wealth));
    }
    printf("%d\n", unionFind.Kruskal());

    return 0;
}
const bool tuple<int, int, int>::operator<(const tuple<int, int, int>tup)const{
    return get<2>(*this) < get<2>(tup);
}//TODO Modification Required
int Union_Find::Kruskal(void){
    int ans(INT_MAX);

}
void Union_Find::Merge(int a, int b){
    int a_f = this->Find(a), b_f = this->Find(b);
    if(this->size[a_f] < this->size[b_f])swap(a_f, b_f);
    this->fa[b_f] = a_f;
}
int Union_Find::Find(int x){
    if(this->fa[x] == x)return x;
    this->fa[x] = this->Find(this->fa[x]);
    return this->fa[x];
}
Union_Find::Union_Find(void){
    for(int i = 1; i <= 5010; ++i)this->fa[i] = i, this->size[i] = 1;
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