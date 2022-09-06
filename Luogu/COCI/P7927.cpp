#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

int as(0), bs(0);
void shot(int n){n <= 4 ? as += 100 : bs += 100;}
void doub(int n){n <= 4 ? as += 50 : bs += 50;}
int lshot[10];
int main(){
    for(int i = 0; i <= 9; ++i)lshot[i] = -114514;
    int N = read();
    for(int i = 1; i <= N; ++i){
        int t = read(), a = read(); (void)read();
        if(t - lshot[a] <= 10)doub(a);
        shot(a);
        lshot[a] = t;
    }
    printf("%d %d\n", as, bs);
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