#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

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
    freopen("sugar.in", "r", stdin);
    freopen("sugar.out", "w", stdout);
//     for(int base = 1; base <= 20; ++base){
//         ld x(0.0);
//         for(int i = 1; i <= 1000; ++i){
//             x += (2.0 * (ld)i - 1.0) / powf64x(base, (ld)i);
    
//        }
// cout << x << endl;
//     }
    // cout << x << endl;
    printf("%d\n",rndd(1, 214748364) % 998244353);
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