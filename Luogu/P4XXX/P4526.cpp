#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

double a;
double f(double x){
    return pow(x, a / x - x);
}
double Simpson(double a, double b){
    return (b - a) * (f(a) + f(b) + 4 * f((a + b) / 2.0)) / 6.0;
}
double Adaptive(double l, double r, double cur, double eps = 1e-7){
    double mid = (l + r) / 2.0;
    double lval = Simpson(l, mid), rval = Simpson(mid, r);
    if(fabs(lval + rval - cur) <= eps * 15.0)return lval + rval + (lval + rval - cur) / 15.0;
    return Adaptive(l, mid, lval, eps / 2.0) + Adaptive(mid, r, rval, eps / 2.0);
}

int main(){
    scanf("%lf", &a);
    if(a < 0.0)puts("orz"), exit(0);
    printf("%.5lf\n", Adaptive(1e-7, 20.0, Simpson(1e-7, 20.0)));
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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