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
inline int readTime(void);
inline bool readSign(void);
inline int readChar(void);
int T;

bool usedAlphabet[1024];
int main(){
    // freopen("./P3952-in.txt", "r", stdin);
	T = read();
    for(int t = 1; t <= T; ++t){
        memset(usedAlphabet, 0, sizeof(usedAlphabet));
        int maxLen(INT_MIN);
        int nowLen(0);
        bool fault(false);
        bool err(false);
        int L = read();
        stack< pair<int, int> >oper;
        int dataTime = readTime();
        for(int i = 1; i <= L; ++i){
            bool sign = readSign();
            if(sign){
                int alpha = readChar();
                if(usedAlphabet[alpha])err = true;
                else usedAlphabet[alpha] = true;
                int s = readChar(), e = readChar();
                if(s == 'n' && e == 'n')oper.push(make_pair(0, alpha));
                else if(s != 'n' && e == 'n' && !fault)oper.push(make_pair(1, alpha)), ++nowLen;
                else if((s == 'n' && e != 'n') || (s > e))oper.push(make_pair(-1, alpha)), fault = true;
                // else if(s == 'n' && e != 'n')oper.push(make_pair(0, alpha));
                // else if(s != 'n' && e == 'n')oper.push(make_pair(1, alpha)), ++nowLen;
                else oper.push(make_pair(0, alpha));
                maxLen = max(maxLen, nowLen);
            }
            else{
                if(oper.empty())err = true;
                else{
                    pair<int, int> mode = oper.top();
                    oper.pop();
                    if(mode.first == 1)--nowLen;
                    if(mode.first == -1)fault = false;
                    usedAlphabet[mode.second] = false;
                }
            }
            // printf("i = %d, nowLen = %d, maxLen = %d\n", i, nowLen, maxLen);
        }
        if(!oper.empty())err = true;
        // printf("MAXLEN = %d,  DATATIME = %d\n", maxLen, dataTime);
        if(err)printf("ERR\n");
        else{
            if(maxLen == dataTime)printf("Yes\n");
            else printf("No\n");
        }
    }


    return 0;
}
inline int readChar(void){
    int ret = getchar();
    while(!isalpha(ret) && !isdigit(ret))ret = getchar();
    if(isalpha(ret))return ret;
    else{
        int retN(0);
        while(isdigit(ret)){
            retN *= 10;
            retN += int(ret - '0');
            ret = getchar();
        }
        return retN;
    }
}
inline int readTime(void){
    int ret(0);
    char c = getchar();
    while(c != 'O')c = getchar();
    while(c != '(')c = getchar();
    c = getchar();
    if(c == '1')return 0;
    else{
        while(c != 'n')c = getchar();
        while(c != '^')c = getchar();
        c = getchar();
        int retN(0);
        while(isdigit(c)){
            retN *= 10;
            retN += int(c - '0');
            c = getchar();
        }
        return retN;
    }
    return ret;
}
inline bool readSign(void){
    char c = getchar();
    while(c != 'F' && c != 'E')c = getchar();
    return c == 'F' ? true : false;
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