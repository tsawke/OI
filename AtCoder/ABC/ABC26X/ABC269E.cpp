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

int N;

int main(){
    N = read();
    int l = 1, r = N, line = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        printf("? %d %d 1 %d\n", l, mid, N); fflush(stdout);
        int v = read();
        if(v == mid - l + 1)l = mid + 1;
        else line = mid, r = mid - 1;
    }
    l = 1, r = N; int row = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        printf("? 1 %d %d %d\n", N, l, mid); fflush(stdout);
        int v = read();
        if(v == mid - l + 1)l = mid + 1;
        else row = mid, r = mid - 1;
    }cout << "! " << line << " " << row << endl;
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    // T ret(0);
    // int flag(1);
    // char c = getchar();
    // while(c != '-' && !isdigit(c))c = getchar();
    // if(c == '-')flag = -1, c = getchar();
    // while(isdigit(c)){
    //     ret *= 10;
    //     ret += int(c - '0');
    //     c = getchar();
    // }
    // ret *= flag;
    // return ret;
    T ret(-114514);
    cin >> ret;
    return ret;
}