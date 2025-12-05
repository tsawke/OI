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
bool fibStr[2100];
void BuildPre(int, int);
int main(){
	n = read();
    int fibSize = 1 << n;
    char c;
    for(int i = 1; i <= fibSize; ++i){
        while((c = getchar()) != '0' && c != '1');
        fibStr[i] = c == '0' ? false : true;
    }
    BuildPre(1, fibSize);
    printf("\n");
    return 0;
}
void BuildPre(int rangeL, int rangeR){
    if(rangeL > rangeR)return;
    if(rangeL == rangeR){printf("%c", fibStr[rangeL] ? 'I' : 'B'); return;}
    int mid = (rangeR + rangeL) / 2;
    int len = rangeR - rangeL + 1;
    int falseNum(0);
    for(int i = rangeL; i <= rangeR; ++i)if(!fibStr[i])++falseNum;
    int flag = falseNum == len ? -1 : (!falseNum ? 1 : 0);
    BuildPre(rangeL, mid);
    BuildPre(mid + 1, rangeR);
    printf("%c", flag == -1 ? 'B' : (flag == 1 ? 'I' : 'F'));

    // int falseL(0), falseR(0);
    // for(int i = rangeL; i <= mid; ++i)if(!fibStr[i])++falseL;
    // for(int j = mid + 1; j <= rangeR; ++j)if(!fibStr[j])++falseR;
    // int flagL = falseL == len ? -1 : (!falseL ? 1 : 0);
    // int flagR = falseR == len ? -1 : (!falseR ? 1 : 0);
    // int flag
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