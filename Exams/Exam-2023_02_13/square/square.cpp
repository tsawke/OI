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

#define MOD (ll)(1e9 + 7)
#define LIM (110000)

template < typename T = int >
inline T read(void);

int N;
int A[310];
struct Fact{int val, cnt;};
basic_string < Fact > facts[310];
basic_string < int > legal[310];
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;


int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    N = read();
    // for(int i = 2; i <= LIM; ++i){
    //     if(!notPrime[i])Prime += i;
    //     for(auto p : Prime){
    //         if((ll)i * p > LIM)break;
    //         notPrime[i * p] = true;
    //         if(i % p == 0)break;
    //     }
    // }
    for(int i = 1; i <= N; ++i){
        int val = A[i] = read();
        // for(auto p : Prime){
        //     if((ll)p * p > val)break;
        //     if(val % p == 0)facts[i] += Fact{p, 0};
        //     while(val % p == 0)facts[i].back().cnt++, val /= p;
        // }if(val != 1)facts[i] += Fact{val, 1};
    }
    int ans(0);
    int base(1);
    for(int i = 1; i <= N; ++i)base *= i;
    for(int i = 1; i <= base; ++i){
        bool flag(true);
        for(int j = 1; j < N; ++j){
            ll val = (ll)A[j] * A[j + 1];
            if((ll)sqrt(val) * (ll)sqrt(val) == val){flag = false; break;}
        }if(flag)++ans;
        next_permutation(A + 1, A + N + 1);
    }printf("%d\n", ans);

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