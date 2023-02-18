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

#define LIM (50)

template < typename T = int >
inline T read(void);

int N, M;
ll LB[60];
void InsertLB(ll x){
    for(int i = LIM; i >= 0; --i)
        if(x & (1ll << i)){
            if(LB[i])x ^= LB[i];
            else{LB[i] = x; break;}
        }
}
void HandleLB(void){
    for(int i = 0; i <= LIM; ++i)
        for(int j = i - 1; j >= 0; --j)
            if(LB[i] & (1ll << j))LB[i] ^= LB[j];
}
ll CntLB(void){
    int cnt(0);
    for(int i = 0; i <= LIM; ++i)
        if(LB[i])++cnt;
    return 1ll << cnt;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        ll cur(0);
        for(int j = 1; j <= N; ++j){
            char c = getchar(); while(!isalpha(c))c = getchar();
            cur <<= 1;
            cur += c == 'O' ? 1 : 0;
        }InsertLB(cur);
    }//HandleLB();
    // for(int i = 0; i <= 10; ++i)printf("LB[%d] = %lld\n", i, LB[i]);
    printf("%lld\n", CntLB() % 2008);
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