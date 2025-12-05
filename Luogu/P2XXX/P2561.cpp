#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template < typename T = int >
inline T read(void);

int N;

class Bignum{
private:
public:
    basic_string < int > nums;
    friend Bignum operator + (Bignum a, Bignum b){
        reverse(a.nums.begin(), a.nums.end());
        reverse(b.nums.begin(), b.nums.end());
        while(a.nums.size() < b.nums.size())a.nums += 0;
        while(b.nums.size() < a.nums.size())b.nums += 0;
        Bignum ret; bool plus(false);
        for(int i = 0; i < (int)a.nums.size(); ++i){
            a.nums.at(i) += b.nums.at(i) + plus;
            plus = false;
            if(a.nums.at(i) >= 10)
                plus = true, a.nums.at(i) %= 10;
        }
        if(plus)a.nums += 1;
        reverse(a.nums.begin(), a.nums.end());
        return a;
    }
    friend Bignum operator * (Bignum a, Bignum b){
        reverse(a.nums.begin(), a.nums.end());
        reverse(b.nums.begin(), b.nums.end());
        Bignum ret;
        for(int i = 1; i <= (int)(a.nums.size() + b.nums.size()); ++i)ret.nums += 0;
        for(auto i = 0; i < (int)a.nums.size(); ++i)
            for(int j = 0; j < (int)b.nums.size(); ++j)
                ret.nums.at(i + j) += a.nums.at(i) * b.nums.at(j);
        for(int i = 0; i < (int)ret.nums.size() - 1; ++i)
            ret.nums.at(i + 1) += ret.nums.at(i) / 10, ret.nums.at(i) %= 10;
        if(ret.nums.back() >= 10)ret.nums += ret.nums.back() / 10, *prev(ret.nums.end(), 2) %= 10;
        while(ret.nums.size() > 1 && ret.nums.back() == 0)ret.nums.pop_back();
        reverse(ret.nums.begin(), ret.nums.end());
        return ret;
    }
    friend Bignum operator / (Bignum a, ll div){
        Bignum ret;
        ll cur(0); bool flag(false);
        for(auto i : a.nums){
            cur *= 10, cur += i;
            if(cur < div && !flag)continue;
            flag = true, ret.nums += cur / div, cur %= div;
        }return ret;
    }
    void Print(void){
        for(auto v : nums)printf("%d", v);
        printf("\n");
    }
};

Bignum qpow(Bignum a, ll b){
    Bignum ret, mul(a);
    ret.nums += 1;
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

int main(){
    N = read();
    Bignum ans; ans.nums += 0;
    Bignum base; base.nums += 2;
    ans = ans + (qpow(base, (ll)ceil((ld)N * (N + 1) / 6.0)) * base);
    ll num(0);
    for(int i = 1; i <= N; ++i)num += (i + 1) >> 1;
    Bignum mul; mul.nums += 3;
    ans = ans + (qpow(base, num) * mul);
    ans = ans + qpow(base, (N * (N + 1)) >> 1);
    ans = ans / 6ll;
    ans.Print();
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}