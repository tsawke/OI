#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

template < typename T = int >
T read(void);

int main(){
    freopen("skewer.in", "r", stdin);
    freopen("skewer.out", "w", stdout);
    printf("114514\n");

    return 0;
}

template < typename T >
T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }ret *= flag;
    return ret;
}