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

#define EPS (1e-7)

template < typename T = int >
inline T read(void);

ld tA, tB;
__float128 A, B;
// __int128_t pow2[200];

int main(){
    scanf("%Lf%Lf", &tA, &tB);
    A = tA, B = tB;
    __float128 cur = 0.0;
    // __int128_t tms = 0;
    __int128_t l = 0, r = A * A/*sqrtf128(A)*/, ans(-1);
    while(l <= r){
        // printf("l = %lld, r = %lld\n", (ll)l, (ll)r);
        __int128_t mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        // printf("mid1 = %lld, mid2 = %lld\n", (ll)mid1, (ll)mid2);
        __float128 val1 = A / sqrt(1.0 + mid1) + B * mid1;
        __float128 val2 = A / sqrt(1.0 + mid2) + B * mid2;
        // printf("val1 = %.8Lf, val2 = %.8Lf\n", (ld)val1, (ld)val2);
        if(val1 >= val2)l = mid1 + 1, ans = mid1, cur = val1;
        else r = mid2 - 1, ans = mid2, cur = val2;
    }printf("%.8Lf\n", (ld)cur);
    
    // // ll tms = 0;
    // for(int i = 60; i >= 0; --i){
    //     if(A / sqrt(1.0 + tms + (1ll << i)) + B * (tms + (1ll << i)) < cur)cur = A / sqrt(1.0 + tms + (1ll << i)) + B * (tms + (1ll << i));
    // }printf("%.8Lf\n", (ld)cur);
    // // while((double)clock() / CLOCKS_PER_SEC <= 1.80){
    // //     ll nxt = 
    // // }

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