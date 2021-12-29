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
string strA, strB;
string strFrom[10], strTo[10];
int nN(0);
queue < string > strQ;
void BFS(int);
int main(){
	cin >> strA >> strB;
    do
        ++nN;
    while (cin >> strFrom[nN] >> strTo[nN]);

    strQ.push(strA);
    BFS(0);
    return 0;
}
void BFS(int Steps)
{
    if (Steps > 20 || strQ.empty())
        return;
    int Len = strQ.size();
    for (int i = 1; i <= Len; ++i)
    {
        if (!strQ.front().compare(strB))
        {
            printf("%d\n", Steps);
            exit(0);
        }
        string strCurrentStr = strQ.front();
        strQ.pop();
        int nStrLen = strCurrentStr.length();
        for (int j = 1; j <= nN; ++j)
        {
            string strTempStr = strCurrentStr;
            int nCurrentPos = strTempStr.find(strFrom[j]);
            if (nCurrentPos > nStrLen)
                continue;
            strTempStr.replace(nCurrentPos, strTo[j].length(), strTo[j]);
            strQ.push(strTempStr);
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