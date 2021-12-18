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
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
bool getValue(int&);
int n;
int aScore(0), bScore(0);
int score(0);
int _aScore(0), _bScore(0);
int _score(0);
struct ANS{
    int a, b;
    ANS(int, int);
};
vector<ANS>ans;
int main(){
	while(getValue(n)){
//        printf("INPUT --- %d\n", n);
        n ? (++aScore, ++_aScore) : (++bScore, ++_bScore);
//        ++score, ++_score;
        
        if((aScore >= 11 || bScore >= 11) && abs(aScore - bScore) >= 2){
            printf("%d:%d\n", aScore, bScore);
            aScore = bScore = score = 0;
        }
        if((_aScore >= 21 || _bScore >= 21) && abs(_aScore - _bScore) >= 2){
            ANS a(_aScore, _bScore);
            ans.push_back(a);
            _aScore = _bScore = _score = 0;
        }
    }
    printf("%d:%d\n\n", aScore, bScore);
    ANS a(_aScore, _bScore);
    ans.push_back(a);
    for(vector<ANS>::iterator itea = ans.begin(); itea != ans.end(); ++itea)
        printf("%d:%d\n", (*itea).a, (*itea).b);
	
    system("pause");
    return 0;
}
ANS::ANS(int a, int b){
    this -> a = a;
    this -> b = b;
}
bool getValue(int& n){
    char c('\0');
    while(c != 'W' && c != 'L'){
        c = getchar();
        if(c == 'E')return false;
    }
    n = c == 'W' ? 1 : 0;
    return true;
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
