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


ll ans(0);
int N;
basic_string < int > Prime;
// unordered_set < int > Pri;
bitset < 310 > notPrime;

int main(){
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    for(int i = 2; i <= 300; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if(i * p > 300)break;
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }
    Prime.erase(Prime.begin());
    N = read();
    int cur(0), len(0);
    for(int i = 1; i <= N; ++i){
        int val = read();
        if(val == cur + 1)cur = val, ++len;
        else{
            if(len){
                auto itR = lower_bound(Prime.begin(), Prime.end(), len);
                while(len != 1){
                    while(len % *itR == 0)++ans, len /= *itR;
                    if(itR != Prime.begin())advance(itR, -1);
                }
            }
            cur = val, len = 1;
        }
    }
    auto itR = lower_bound(Prime.begin(), Prime.end(), len);
    while(len != 1){
        printf("%d\n", *itR);
        exit(0);
        while(len % *itR == 0)++ans, len /= *itR;
        if(itR != Prime.begin())advance(itR, -1);
    }
    printf("%lld\n", ans);
//有问题，当成乘法算了。。



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
/*
8
1 2 3 5 6 7 8 9
*/