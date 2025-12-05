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

#define LIM (41000)

template < typename T = int >
inline T read(void);

int N;
int phi[LIM + 100];
int ans(0);
basic_string < int > Prime;
bitset < LIM + 100 > notPrime;

int main(){phi[1] = 1;
    for(int i = 2; i <= LIM; ++i){
        if(!notPrime[i])Prime += i, phi[i] = i - 1;
        for(auto p : Prime){
            if(i * p > LIM)break;
            phi[i * p] = i % p ? phi[i] * phi[p] : p * phi[i];
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }N = read();
    if(N == 1)printf("0\n"), exit(0);
    for(int i = 1; i <= N - 1; ++i)ans += phi[i] * 2;
    printf("%d\n", ans + 1);
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