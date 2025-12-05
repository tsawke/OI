#define _USE_MATH_DEFINES
// #include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

int read(void){
    int ret(0);
    short flag(1);
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

// template<typename T = int>
// inline T read(void);

class TreeArray{
private:
    int lim;
    int tr[35000];
public:
    void set(int lim){this->lim = lim;}
    int lowbit(int x){return x & -x;}
    void add(int x, int v = 1){while(x <= lim)tr[x] += v, x += lowbit(x);}
    int query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}tr;
int cnt[35000];

int main(){
    int N = read(); tr.set(34000);
    for(int i = 1; i <= N; ++i){
        int x = read() + 1, y = read();
        ++cnt[tr.query(x)];
        tr.add(x);
    }
    for(int i = 0; i <= N - 1; ++i)printf("%d\n", cnt[i]);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



// template<typename T>
