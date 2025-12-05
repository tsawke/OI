#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int main(){
    int N = read(), X = read();
    int up(0), down(0);
    int lst(0);
    for(int i = 1; i <= N; ++i){
        int x = read(), d = read(), u = read();
        int len = x - lst;
        up + len < u
            ? up += len
            : (~((u - 1 - up) ^ len)) & 1
                ? up = u - 1
                : up = u - 2;
        down - len > d
            ? down -= len
            : (~((down - (d + 1)) ^ len)) & 1
                ? down = d + 1
                : down = d + 2;
        if(down > up){printf("NIE\n"); exit(0);}
        lst = x;
    }down -= X - lst;
    printf("%d\n", (X + down) / 2);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
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
    ret *= flag;
    return ret;
}