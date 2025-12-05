#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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
int A[1100];
int gcdv;

int main(){
    N = read();
    gcdv = A[1] = read();
    for(int i = 2; i <= N; ++i)gcdv = __gcd(gcdv, A[i] = read());
    int cnt(0);
    for(int i = 1; i <= N; ++i){
        A[i] /= gcdv;
        while(A[i] % 2 == 0)A[i] /= 2, ++cnt;
        while(A[i] % 3 == 0)A[i] /= 3, ++cnt;
        if(A[i] != 1)printf("-1\n"), exit(0);
    }printf("%d\n", cnt);

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