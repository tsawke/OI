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

bitset < 10 > ans;

int main(){
    for(int i = 1; i <= 2; ++i){
        int v = read();
        switch(v){
            case 1:{ans[1] = true; break;}
            case 2:{ans[2] = true; break;}
            case 3:{ans[1] = ans[2] = true; break;}
            case 4:{ans[4] = true; break;}
            case 5:{ans[1] = ans[4] = true; break;}
            case 6:{ans[2] = ans[4] = true; break;}
            case 7:{ans[1] = ans[2] = ans[4] = true; break;}
        }
    }
    printf("%d\n", 1 * ans[1] + 2 * ans[2] + 4 * ans[4]);
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