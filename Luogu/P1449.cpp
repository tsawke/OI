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
#include <stack>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
char c;
stack<int>cal;
int GetTop(stack<int>&);
int main(){
    while((c = getchar()) != EOF && c != '@'){
        if('0' <= c && c <= '9'){
            int value(int(c - '0'));
            char cc;
            while((cc = getchar()) != EOF && cc != '.' && cc != '@'){
                value *= 10;
                value += int(cc - '0');
            }
            cal.push(value);
            continue;
        }
        switch(c){
            case '+':{
                int a(GetTop(cal)), b(GetTop(cal));
                cal.push(a + b);
                break;
            }
            case '-':{
                int a(GetTop(cal)), b(GetTop(cal));
                cal.push(b - a);
                break;
            }
            case '*':{
                int a(GetTop(cal)), b(GetTop(cal));
                cal.push(a * b);
                break;
            }
            case '/':{
                int a(GetTop(cal)), b(GetTop(cal));
                cal.push(b / a);
                break;
            }
            default:break;
        }
    }
    printf("%d\n", cal.top());
    system("pause");
    return 0;
}
int GetTop(stack<int>&s){
    int ret = s.top();
    s.pop();
    return ret;
}template <typename T = int>
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
