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

#define EPS (ld)(1e-6)

template < typename T = int >
inline T read(void);

ld c, b, m;

int main(){
    scanf("%Lf%Lf%Lf", &c, &b, &m);
    ld y = (ld)(4 * m * m - b * b - c * c) / (ld)(2 * c);
    ld x = (ld)b * b - y * y;
    if(x < -EPS)printf("Mission impossible\n"), exit(0);
    if(fabs(x) <= EPS)x = 0.0;
    if(fabs(y) <= EPS)y = 0.0;
    x = sqrt(x);
    printf("0.00000 0.00000\n0.00000 %.5Lf\n", c);
    printf("%.5Lf %.5Lf\n", x, y);
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