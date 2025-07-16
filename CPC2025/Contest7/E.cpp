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

int N;
ll A[210000];
ll mx[210000], mn[210000];
ll curMn = LONG_LONG_MAX, curMx = LONG_LONG_MIN;
long double ans[210000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read < ll >();
    mx[0] = LONG_LONG_MIN, mn[0] = LONG_LONG_MAX;
    for(int i = 1; i <= N; ++i)
        mx[i] = max(mx[i - 1], A[i]),
        mn[i] = min(mn[i - 1], A[i]);

    for(int i = N; i >= 1; --i){
        curMn = min(curMn, A[i]), curMx = max(curMx, A[i]);
        if(curMx >= mx[i - 1]){
            ans[i] = 1.0 - ((long double)mx[i - 1] / curMx);
            if(mn[i - 1] < curMn * (1.0 - ans[i]))
                ans[i] = 1.0 - ((long double)mn[i - 1] / curMn);
        }else
            ans[i] = curMn <= mn[i - 1] ? 0.0 : (1.0 - (long double)mn[i - 1] / curMn);
    }
    for(int i = 1; i <= N; ++i)printf("%.10lf%c", i == 1 ? 1.00 : (double)ans[i], i == N ? '\n' : ' ');
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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