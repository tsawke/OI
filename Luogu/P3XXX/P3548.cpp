#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template<typename T = int>
inline T read(void);
bool readflag(void);

struct Point{
    ld x, y;
    friend Point operator + (const Point &a, const Point &b){
        return Point{a.x + b.x, a.y + b.y};
    }
    friend Point operator - (const Point &a, const Point &b){
        return Point{a.x - b.x, a.y - b.y};
    }
    friend Point operator * (const ld &k, const Point &a){
        return Point{k * a.x, k * a.y};
    }
};
struct Vec{
    ld x, y;
    friend ld operator * (const Vec &a, const Vec &b){
        return (ld)a.x * b.y - (ld)a.y * b.x;
    }
    friend bool operator < (const Vec &a, const Vec &b){
        return a * b < 0;//TODO eps
    }
    friend bool operator > (const Vec &a, const Vec &b){
        return a * b > 0;
    }
    friend bool operator == (const Vec &a, const Vec &b){
        return a * b == 0;
    }
};
Vec MakeVec(Point a, Point b){return Vec{b.x - a.x, b.y - a.y};}
Vec Point2Vec(Point p){return Vec{p.x, p.y};}
Point Vec2Point(Vec v){return Point{v.x, v.y};}
struct Line{
    Point P;
    Vec V;
};
Line MakeLine(Point a, Point b){return Line{Point{a.x, a.y}, MakeVec(a, b)};}
struct Segl{
    Point a, b;
};

int N;
Point p[1100];

int JudgePointPos(Point a, Line l){// 1 - left; -1 - right; 0 - on
    auto ret = l.V * MakeVec(l.P, a);
    return ret > 0 ? 1 : (ret < 0 ? -1 : 0);
}
int JudgeSeglPos(Segl sl, Line l){// 1 - left; -1 - right; 0 - cross
    int a = JudgePointPos(sl.a, l), b = JudgePointPos(sl.b, l);
    return (a == 1 && b == -1) || (a == -1 && b == 1)
        ? 0
        : (a == 1 || b == 1)
            ? 1
            : -1;
}
Point GetInter(Line l1, Line l2){//Intersection
    ld k = (ld)(Point2Vec(l2.P - l1.P) * l2.V) / (ld)(l1.V * l2.V);
    return l1.P + k * Vec2Point(l1.V);
}
bool check(void){
    
}

int main(){


    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

bool readflag(void){
    char c = getchar();
    while(c != 'C' && c != 'S')c = getchar();
    return c == 'S' ? true : false;
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