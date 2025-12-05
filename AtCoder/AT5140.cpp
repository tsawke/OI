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

int lowbit(int x){return x & -x;}

int main(){
    int N = read();
    if(lowbit(N) == N)puts("No"), exit(0);
    puts("Yes");
    for(int i = 2; i <= N - 1; i += 2){
        printf("%d %d\n", 1, i);
        printf("%d %d\n", i, i + 1);
        printf("%d %d\n", 1, i + 1 + N);
        printf("%d %d\n", i + 1 + N, i + N);
    }
    printf("%d %d\n", 3, 1 + N);
    if(!(N & 1)){
        printf("%d %d\n", N, lowbit(N) + 1 + N);
        printf("%d %d\n", N - lowbit(N), N + N);
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