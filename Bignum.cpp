#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <unistd.h>
#define BASE 1000
#define MOD 10000
#define RANGE 9999
#define nxt(i, len) (i < len ? ++i : i)
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
inline unll readULL(void);
inline int read(void);
int c2d(char);
void PrintInt(char*, int*, int);
class Integer{
    public:
        Integer(char*, int);
        void Init(void);
        Integer operator+(const Integer&);
    protected:
    private:
        int value_4[1100];
        int len;
        int real_len;
};


char c1[1100], c2[1100];
int main(){
	scanf("%s%s", &c1, &c2);
    Integer a(c1, strlen(c1)), b(c2, strlen(c2));
    

    pause();
    return 0;
}
Integer Integer::operator+(const Integer& addend){
    vector<int>answer;
    int adv(0); //advance
    //check if value_4[1] is less than BASE
    int ans_1 = this -> value_4[1] + adden.value_4[1];
    int len_1 = max(log10(this -> value_4[1]), log10(addend.value_4[1])) + 1;
    if(ans_1 > 10 * (len_1 - 1))
    for(int i = 2, j = 2; i <= this -> len || j <= addend.len; nxt(i, this -> len), nxt(j, addend.len)){
        int ans = this -> value_4[i] +addend.value_4[j];
        if(adv){ans += adv; adv = 0;}
        if(ans > RANGE){adv = 1; ans %= MOD;}
        answer.push_back(ans);
    }
    if(adv)answer.push_back(adv);
    int len = max(this -> len, adden.len) + adv;

}
void Integer::Init(void){
    reverse(this -> value_4 + 1, this -> value_4 + this -> len + 1);
    PrintInt("After init values : ", this -> value_4, this -> len);
}
Integer::Integer(char *c, int len){
    memset(this -> value_4, 0, sizeof(this -> value_4));
    this -> len = int(ceil(len / 4.00));
    this -> real_len = len;
    int nowPos(0);
    for(int i = 1; i <= this -> len; ++i){
        int num(0);
        int base(BASE);
        if(nowPos + 4 >= len)base = 10 * (len - nowPos - 1);
        for(int count = 1; count <= 4 && nowPos < len; ++count){
            num += c2d(c[nowPos++]) * base;
            base /= 10;
        }
//        printf("Get number: %d\n", num);
        this -> value_4[i] = num;
    }
    PrintInt("Read str to int: ", this -> value_4, this -> len);
    this -> Init();
}

void PrintInt(char *note, int *v, int len){
    printf(note);
    for(int i = 1; i <= len; ++i)
        printf("%d ", v[i]);
    printf("  len = %d\n", len);
}
int c2d(char c){
    return int(c) - int('0');
}
inline unll readULL(void){
	unll ret(0);
	int flag(1);
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
inline int read(void) {
	int ret(0);
	int flag(1);
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