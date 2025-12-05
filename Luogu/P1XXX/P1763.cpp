#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
inline T read(void);

int gcd(int, int);
int lcm(int, int);
class Frac{
    public:
        int a, b; //a / b
        void Reset(void){
            int _gcd = gcd(this->a, this->b);
            if(_gcd != 1){
                this->a /= _gcd;
                this->b /= _gcd;
            }
            return;
        }
        bool operator==(const Frac f){return f.a == this->a && f.b == this->b;}
        Frac operator+(const Frac f){
            Frac ret;
            ret.b = lcm(f.b, this->b);
            ret.a = f.a * (ret.b / f.b) + this->a * (ret.b / this->b);
            ret.Reset();
            return ret;
        }
        Frac operator-(const Frac f){
            Frac ret;
            ret.b = lcm(f.b, this->b);
            ret.a = f.a * (ret.b / f.b) - this->a * (ret.b / this->b);
            ret.Reset();
            return ret;
        }
};
Frac F;
bool dfs()
int main(){
    F.a = read(), F.b = read();
    F.Reset();
    for(int deep = 1; true; ++deep){
        if(dfs())break;
    }
    return 0;
}
bool dfs(int maxDeep, int curDeep, )
int gcd(int a, int b){
    if(a < b)swap(a, b);
    if(!b)return a;
    return gcd(b, a % b);
}
int lcm(int a, int b){
    return int((long long)a * b / gcd(a, b));
}


template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    return (T)(ret * flag);
}