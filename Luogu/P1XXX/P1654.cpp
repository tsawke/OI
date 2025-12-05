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
double P[110000];
double x1[110000], x2[110000], ans[110000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        scanf("%lf", P + i);
        x1[i] = (x1[i - 1] + 1.0) * P[i];
        x2[i] = (x2[i - 1] + 2.0 * x1[i - 1] + 1.0) * P[i];
        ans[i] = (ans[i - 1] + 3.0 * (x1[i - 1] + x2[i - 1]) + 1.0) * P[i] + ans[i - 1] * (1 - P[i]);
    }printf("%.1lf\n", ans[N]);
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