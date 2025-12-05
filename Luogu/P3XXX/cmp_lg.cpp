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
    int lim = 50;
    for(int i = 1; i <= lim; ++i){
        char c[110000];
        sprintf(c, "/home/jdoi/cpp/OI/std < /home/jdoi/cpp/P3549-in/%d.in > /home/jdoi/cpp/P3549-in/std.out", i);
        system(c);

        sprintf(c, "/home/jdoi/cpp/OI/my < /home/jdoi/cpp/P3549-in/%d.in > /home/jdoi/cpp/P3549-in/my.out", i);
        system(c);

        if(system("diff /home/jdoi/cpp/P3549-in/std.out /home/jdoi/cpp/P3549-in/my.out"))printf("%d\n", i),exit(1);
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