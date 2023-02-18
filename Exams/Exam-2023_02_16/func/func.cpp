/*
8 5
6 4 4 1 1 4 10 5
3 7 9 10 0 1 6 2
m 3 7 1
q 84 2 3
m 5 8 1
q 30 4 6
m 1 2 10

7 5
10 4 6 4 10 4 4
3 10 5 4 6 6 5
q 93 1 4
q 42 5 6
m 2 8 3
m 1 6 3
q 17 2 7
*/
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

int N, M;
int P[11000], Q[11000];

int main(){
    freopen("func.in", "r", stdin);
    freopen("func.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)P[i] = read();
    for(int i = 1; i <= N; ++i)Q[i] = read();
    while(M--){
        char c = getchar(); while(!isalpha(c))c = getchar();
        if(c == 'm'){
            int idx = read(), p = read(), q = read();
            P[idx] = p, Q[idx] = q;
        }else{
            ll x = read(); int s = read(), t = read();
            for(int i = s; i <= t; ++i)
                x /= P[i], x += Q[i];
            printf("%lld\n", x);
        }
    }

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