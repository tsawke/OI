#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int cur[1100];

// #define 1000 10

int __N = 6;

int main(){
    freopen("in.txt", "w", stdout);
    printf("%d\n", __N);
    for(int i = 1; i <= __N; ++i)printf("%d\n", i);

    freopen("out.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    int N = read();
    for(int i = 1; i <= N; ++i){
        int a = read(), b = read();
        if(a == 1)
            for(int j = 1; j <= __N; ++j)if(cur[j] == b)++cur[j];
        else    
            ++cur[b];
    }
    for(int i = 1; i <= __N; ++i)printf("%d\n", cur[i]);

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