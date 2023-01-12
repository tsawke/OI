#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

struct Coord{int x, y;}p[10];
struct Vec{int x, y;}v[10];

int main(){
    for(int i = 1; i <= 4; ++i)p[i].x = read(), p[i].y = read();
    for(int i = 1; i <= 3; ++i)v[i].x = p[i + 1].x - p[i].x, v[i].y = p[i + 1].y - p[i].y;
    v[4].x = p[1].x - p[4].x, v[4].y = p[1].y - p[4].y;
    for(int i = 1; i <= 3; ++i){
        // printf("this is %d\n", v[i].x * v[i + 1].y - v[i].y * v[i + 1].x);
        if(v[i].x * v[i + 1].y - v[i].y * v[i + 1].x < 0)printf("No\n"), exit(0);
    }if(v[4].x * v[1].y - v[4].y * v[1].x < 0)printf("No\n"), exit(0);
    printf("Yes\n");
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