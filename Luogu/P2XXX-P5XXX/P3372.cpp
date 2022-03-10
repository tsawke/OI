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

struct Vertex{
    int value = 0;
    int lazymark = 0;
    int lRange = 0, rRange = 0;
    int GetVertexN(void){return this->rRange - this->lRange + 1;}
};
int N, operationN;
Vertex segTree[110000 * 4];
void BuildSegTree_WithInput(int = 1, int = N, int = 1);
int main(){
	N = read(), operationN = read();
    BuildSegTree_WithInput();
    // for(int i = 1; i <= operationN; ++i){

    // }
    for(int i = 1; i <= N; ++i)printf("%d ", segTree[i].value);
    return 0;
}
void BuildSegTree_WithInput(int lRange, int rRange, int rootVertex){
    if(lRange == rRange){
        segTree[rootVertex].value = read();
        segTree[rootVertex].lRange = segTree[rootVertex].rRange = lRange;    
        return;
    }
    int mid = (rRange + lRange) / 2;
    BuildSegTree_WithInput(lRange, mid, rootVertex * 2);
    BuildSegTree_WithInput(mid + 1, rRange, rootVertex * 2 + 1);
    segTree[rootVertex].lRange = lRange;
    segTree[rootVertex].rRange = rRange;
    segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
    return;
}
void UpdateSegTree_BySection(int lSectionRange, int rSectionRange, int updValue, int rootVertex){
    if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange){
        segTree[rootVertex].value += segTree[rootVertex].GetVertexN() * updValue;
        segTree[rootVertex].lazymark += updValue;
        return;
    }
    if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange){
        segTree[rootVertex * 2].value += segTree[rootVertex].lazymark * segTree[rootVertex * 2].GetVertexN();
        segTree[rootVertex * 2 + 1].value += segTree[rootVertex].lazymark * segTree[rootVertex * 2 + 1].GetVertexN();
        segTree[rootVertex * 2].lazymark += segTree[rootVertex].lazymark;
        segTree[rootVertex * 2 + 1].lazymark += segTree[rootVertex].lazymark;
        segTree[rootVertex].lazymark = 0;
    }
    if(segTree[rootVertex * 2].GetVertexN())UpdateSegTree_BySection(segTree[rootVertex * 2].lRange, segTree[rootVertex * 2].rRange, updValue, rootVertex * 2);
    if(segTree[rootVertex * 2 + 1].GetVertexN())UpdateSegTree_BySection(segTree[rootVertex * 2 + 1].lRange, segTree[rootVertex * 2 + 1].rRange, updValue, rootVertex * 2 + 1);
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