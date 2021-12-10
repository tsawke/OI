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
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int c2d(char);
void PrintInt(char*, int *, int);
struct Integer{
    int value[1100];
    int len;
    Integer(char*, int);
    Integer(int*, int);
    Integer(vector<int>);
};
Integer add(Integer, Integer);
char c1[1100], c2[1100];
int main(){
//	cin.getline(c1, 1010);
//  cin.getline(c2, 1010);
	scanf("%s%s", &c1, &c2);
    Integer a(c1, strlen(c1)), b(c2, strlen(c2));
    Integer ans = add(a, b);
    for(int i = 1; i <= ans.len; ++i)printf("%d", ans.value[i]);
    printf("\n");

    pause();
    return 0;
}
Integer::Integer(int *v, int len){
    memset(this -> value, 0, sizeof(this -> value));
    this -> len = len;
    for(int i = 0; i < len; ++i)
        this -> value[i + 1] = v[i + 1];
}
Integer::Integer(char *c, int len){
    memset(this -> value, 0, sizeof(this -> value));
    this -> len = len;
    for(int i = 0; i < len; ++i)
        this -> value[i + 1] = c2d(c[i]);
//    PrintInt("Read str to int: ", this -> value, this -> len);
}
Integer::Integer(vector<int>v){
    memset(this -> value, 0, sizeof(this -> value));
    this -> len = v.size();
    int cnt(0);
    for(vector<int>::reverse_iterator itea = v.rbegin(); itea != v.rend(); ++itea)
        this -> value[++cnt] = *itea;
}
Integer add(Integer a, Integer b){
    vector<int>anst;
    bool flag(0);
    for(int i = a.len, j = b.len; i || j; (i ? --i : i), (j ? --j : j)){
//        printf("add now i = %d j = %d a[0] = %d b[0] = %d\n", i, j, a.value[0], b.value[0]);
        int v = a.value[i] + b.value[j] + flag;
        if(flag)flag = 0;
        if(v >= 10)v -= 10, flag = 1;
//        printf("now v = %d\n", v);
        anst.push_back(v);
    }
    if(flag)anst.push_back(1);
    Integer ans(anst);
    return ans;
}
void PrintInt(char *note, int *v, int len){
    printf(note);
    for(int i = 1; i <= len; ++i)
        printf("%d", v[i]);
    printf("  len = %d\n", len);
}
int c2d(char c){
    return int(c) - '0';
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
//TODO