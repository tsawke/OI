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
#include <queue>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
string A, B;
string From[10], To[10];
int N(0);
queue < string > Q;
void BFS(int);
int main(){
	cin >> A >> B;
    do ++N;
    while (cin >> From[N] >> To[N]);
    //TODO while(cin) or while(scanf!=EOF)结束循环是在全部输入后还是输入完成后下一次循环
    Q.push(A);
    BFS(0);
    return 0;
}
//TODO Debug Required
void BFS(int Steps)
{
    if (Steps > 20 || Q.empty())
        return;
    int Len = Q.size();
    for (int i = 1; i <= Len; ++i)
    {
        if (!Q.front().compare(B))
        {
            printf("%d\n", Steps);
            exit(0);
        }
        string Current = Q.front();
        Q.pop();
        int nLen = Current.length();
        for (int j = 1; j <= N; ++j)
        {
            string Temp = Current;
            int CurrentPos = Temp.find(From[j]);
            if (CurrentPos > nLen)
                continue;
            Temp.replace(CurrentPos, To[j].length(), To[j]);
            Q.push(Temp);
        }
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