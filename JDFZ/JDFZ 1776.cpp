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
int S[11000]; //-300~-1 -> 701-1000; *p = 1001
int height(0);
int main(){
	int n = read() * read();
	int *p = &S[1001];
	for(int i = 1; i <= n; ++i){
		int t = read();
		if(t >= 0)++S[t];
		else ++p[t];
		height += t;
	}
	for(int i = -300; i <= -1; ++i)if(p[i])printf("%d %d\n", i, p[i]);
	for(int i = 0; i <= 400; ++i)if(S[i])printf("%d %d\n", i, S[i]);
	printf("%d", height >= 0 ? height / n : -1);
//TODO Debug Required
//    system("pause");
    return 0;
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