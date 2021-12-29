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
#define pow10(n) int(pow(10.0, double(n)))
//#define nxt(i, len) ((i < len && i) ? (++i) : (i = 0))
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int c2d(char);
void PrintInt(char*, int*, int);
inline void nxt(int&, const int&, bool&);
class Integer{
    public:
        Integer(char*, int);
        Integer(vector<int>);
        void Init(void);
        Integer operator+(const Integer&);
        Ingeger operator-(const Integer&);//TODO -*/
        void PrintInt(void);
    protected:
    private:
        int value_4[1100];
        int len;
        int real_len;
};


char c1[1100], c2[1100];
int main(){
	scanf("%s%s", &::c1, &::c2);
    Integer a(::c1, strlen(::c1)), b(::c2, strlen(::c2));
    (a + b).PrintInt();
    

    pause();
    return 0;
}
Integer Integer::operator+(const Integer& addend){
    vector<int>answer;
    int adv(0); //advance
    /*
    //check if value_4[1] is less than BASE
    int ans_1 = this -> value_4[1] + addend.value_4[1];
    int len_1 = max(int(log10(this -> value_4[1])), int(log10(addend.value_4[1]))) + 1;
    if(ans_1 >= pow10((len_1))){ans_1 %= (pow10((len_1))); adv = 1;}
    answer.push_back(ans_1);
    printf("Add: get ans_1: %d\n", ans_1);*/
    bool flag_i(true), flag_j(true);
    for(int i = 1, j = 1; flag_i || flag_j; nxt(i, this -> len, flag_i), nxt(j, addend.len, flag_j)){
        int ans = (flag_i ? this -> value_4[i] : 0) + (flag_j ? addend.value_4[j]: 0);
        if(adv){ans += adv; adv = 0;}
        if(ans > RANGE){adv = 1; ans %= MOD;}
        answer.push_back(ans);
        // printf("Add: get ans: %d\n", ans);
    }
    if(adv)answer.push_back(adv);
    // printf("vector.ans: "); for(auto i : answer)printf("%d ", i);printf("\n");
//    int len = max(this -> len, adden.len) + adv;
    reverse(answer.begin(), answer.end());
    Integer ret(answer);
    // ::PrintInt("Get Answer: ", ret.value_4, ret.len);
    return ret;
}
void Integer::PrintInt(void){
    for(int i = 1; i <= this -> len; ++i){
        if(i != 1){
            int num_0 = this -> value_4[i] ? (4 - int(log10(this -> value_4[i])) - 1) : 3;
            for(int j = 1; j <= num_0; ++j)printf("0");
        }
        printf("%d", this -> value_4[i]);
    }
    printf("\n");
}
void Integer::Init(void){
    reverse(this -> value_4 + 1, this -> value_4 + this -> len + 1);
    ::PrintInt("After init values : ", this -> value_4, this -> len);
}
Integer::Integer(vector<int> v){
    memset(this -> value_4, 0, sizeof(this -> value_4));
    this -> len = this -> real_len = v.size();
    int cnt(0);
    for(auto itea = v.begin(); itea != v.end(); ++itea)this -> value_4[++cnt] = *itea;
}
Integer::Integer(char *c, int len){
    memset(this -> value_4, 0, sizeof(this -> value_4));
    this -> len = int(ceil(len / 4.00));
    this -> real_len = len;
    /*
    int nowPos(0);
    for(int i = 1; i <= this -> len; ++i){
        int num(0);
        int base(BASE);
        if(nowPos + 4 >= len)base = pow10((len - nowPos - 1));
        for(int count = 1; count <= 4 && nowPos < len; ++count){
            num += c2d(c[nowPos++]) * base;
            base /= 10;
        }
//        printf("Get number: %d\n", num);
        this -> value_4[i] = num;
    }*/
    int nowPos(len - 1);//nowPos: 0 ~ len-1
    for(int i = 1; i <= this -> len; ++i){
        int num(0);
        int base(1);
//        if(nowPos - 3 < 1)base = pow10((nowPos - 1));
        for(int count = 1; count <= 4 && nowPos >= 0; ++count){
            num += c2d(c[nowPos--]) * base;
            base *= 10;
        }
//        printf("Get number: %d\n", num);
        this -> value_4[i] = num;
    }
    //  ::PrintInt("Read str to int: ", this -> value_4, this -> len);
//    this -> Init();
}
inline void nxt(int& i, const int& len, bool& flag){
    if(!flag)return;
    if(++i > len){flag = false; return;}
    return;
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