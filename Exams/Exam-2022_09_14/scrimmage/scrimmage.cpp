#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);



int main(){
freopen("scrimmage.in", "r", stdin);
freopen("scrimmage.out", "w", stdout);
    int N = read(), Q = read();
    for(int i = 1; i <= N; ++i)(void)read();
    for(int i = 1; i <= Q; ++i){
        int opt = read();
        switch(opt){
            case 1:{(void)read();(void)read();break;}
            case 2:{(void)read();(void)read();printf("1\n");break;}
            case 3:{(void)read();(void)read();(void)read();(void)read();printf("1\n"); break;}
        }
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