#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define PI M_PI
#define E M_E
#define npt nullptr

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef long long ll;
typedef unsigned long long unll;

template <typename T = int>
inline T read(void);

int main(){
    


    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = 1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

/* Examples:



*/