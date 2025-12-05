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

int N;
int C[20];
int mn(INT_MAX), mnp(-1);
basic_string < int > ans;

int main(){
    N = read();
    for(int i = 1; i <= 9; ++i){
        C[i] = read();
        if(C[i] < mn)mn = C[i], mnp = i;
    }
    ll mxLen = N / mn;
    for(int i = 1; i <= mxLen; ++i)
        for(int j = 9; j >= mnp; --j)
            if(N - C[j] >= (mxLen - i) * mn){
                N -= C[j], ans += j; break;
            }
    for(auto d : ans)printf("%d", d);
    printf("\n");
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