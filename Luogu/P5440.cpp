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
int months[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void dfs(char*, int);
bool CheckYear(int);
bool CheckPrime(int);
bool CheckLegal(char*);
char num[10];
void GetNum(char*);
int ans(0);
int main(){
	int T = read();
    for(int s = 1; s <= T; ++s){
        GetNum(num);
        bool spec(true);
        for(int i = 1; i <= 8; ++i)if(num[i] != '-'){spec = false; break;}
        if(spec){printf("55157\n"); continue;}
        ans = 0;
        dfs(num, 1);
        printf("%d\n", ans);
    }
    return 0;
}
void dfs(char *num, int deep){
    if(deep > 8){
        // printf("Now Check Num %s\n", num + 1);
        if(CheckLegal(num))++ans;
        return;
    }
    if(num[deep] != '-')return dfs(num, deep + 1);
    if((1 <= deep && deep <= 4) || deep == 6 || deep == 8)
        for(int i = 0; i <= 9; ++i){
            num[deep] = char(i + int('0'));
            dfs(num, deep + 1);
            num[deep] = '-';
        }
    if(deep == 5)
        for(int i = 0; i <= 1; ++i){
            num[deep] = char(i + int('0'));
            dfs(num, deep + 1);
            num[deep] = '-';
        }
    if(deep == 7)
        for(int i = 0; i <= 3; ++i){
            num[deep] = char(i + int('0'));
            dfs(num, deep + 1);
            num[deep] = '-';
        }
}
bool CheckYear(int y){
    if(y % 400 == 0 || (y % 100 && y % 4 == 0))return true;
    return false;
}
bool CheckPrime(int n){
    if(n == 1)return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)return false;
    return true;
}
bool CheckLegal(char *num){
    // printf("Find num -- %s\n", num + 1);
    int a[10];
    for(int i = 1; i <= 8; ++i)a[i] = int(num[i]) - int('0');
    int day = a[8] + a[7] * 10;
    int month = a[6] + a[5] * 10;
    int year = a[4] + a[3] * 10 + a[2] * 100 + a[1] * 1000;
//    printf("values: year%d, month%d, day%d, range_day-%d\n", year, month, day, (::months[month] + (month == 2 && CheckYear(year) ? 1 : 0)));
//    printf("CheckValue mon = %d\n", ::months[month]);
    if(year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > (::months[month] + (month == 2 && CheckYear(year) ? 1 : 0)))return false;
    
    int val = day + month * 100;
    int val_ = val + year * 10000;
    // printf("Pass, values: val%d, val_%d, num is %s\n", val, val_, num + 1); 
    // if(!CheckPrime(day))printf("DAY  ");
    // if(!CheckPrime(val))printf("VAL  ");
    // if(!CheckPrime(val_))printf("VAL_  ");
    // printf("is not Prime\n");
    if(!CheckPrime(day) || !CheckPrime(val) || !CheckPrime(val_))return false;
    return true;
}
void GetNum(char *num){
    memset(num, 0, sizeof(num));
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    int count(0);
    for(int i = 1; i <= 8; ++i){
        num[++count] = c;
        c = getchar();
    }
    return;
}
template <typename T = int>
inline T read(void){
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