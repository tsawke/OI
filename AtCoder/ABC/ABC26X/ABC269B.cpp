#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

int mnLine(114514), mxLine(-1), mnRow(114514), mxRow(-1);

int main(){
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= 10; ++j){
            char c = getchar(); while(c != '.' && c != '#')c = getchar();
            if(c == '#')mnLine = min(mnLine, i), mxLine = max(mxLine, i), mnRow = min(mnRow, j), mxRow = max(mxRow, j);
        }
    }printf("%d %d\n%d %d\n", mnLine, mxLine, mnRow, mxRow);

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