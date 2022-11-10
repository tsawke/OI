#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

template < typename T = int >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }return ret * flag;
}

int N, M1, M2, lim;

int main(){
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    N = read(), M1 = read(), M2 = read(), lim = read();
    // if(!M1 && !M2){

    // }

if(lim == 1 && M1 != 0)printf("-1 0\n"), exit(0);
printf("1 1\n");
    return 0;
}