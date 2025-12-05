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

ll N, M;

set < pair < int, int > > used[11];
pair < int, int > BuildDiff(void){
    int x = rndd(1, N);
    int y = rndd(1, N);
    while(y == x)y = rndd(1, N);
    return {x, y};
}
int main(){
    int Ts = 1, Tt = 30;
    for(int t = Ts; t <= Tt; ++t){
        // N = rndd(800000, 1000000), M = rndd(800000, 1000000);
        // ll N = rndd(1, 100000);
        // do{N = (ll)rndd(1, INT_MAX) * rndd(1, INT_MAX);}while(N > (ll)1e16);
        // ll X = rndd(1, 10);
        char c[11000];
        sprintf(c, "/build/grammmmmmmar%d.out", t);
        FILE* input = fopen(c, "w");
        fclose(input);
    }
    

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