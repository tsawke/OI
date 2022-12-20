#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

struct Node{ll val; int cnt;};
struct MyPair{int idx; Node val;};
basic_string < Node > buc[110];
int N, K, D;

int main(){
    N = read(), K = read(), D = read();
    for(int i = 1; i <= N; ++i){
        int val = read();
        int idx = val % D;
        basic_string < MyPair > mdf;
        mdf += MyPair{idx, Node{val, 1}};
        for(int i = 0; i <= D - 1; ++i)
            for(auto nod : buc[i])
                mdf += MyPair{(i + idx) % D, Node{nod.val + val, nod.cnt + 1}};
        for(auto md : mdf)buc[md.idx] += md.val;
    }ll mx(-1);
    for(auto nod : buc[0])if(nod.cnt == K)mx = max(mx, nod.val);
    printf("%lld\n", mx);
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