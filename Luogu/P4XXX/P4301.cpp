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
ll sum(0), cur(0);
basic_string < ll > A;

class LinearBasis{
private:
    #define LIM (62)
    ll LB[70];
    bool exist0;
public:
    LinearBasis(void){memset(LB, 0, sizeof LB); exist0 = false;}
    void Insert(ll x){
        if(!x)return exist0 = true, void();
        for(int i = LIM; i >= 0; --i)
            if(x & (1ll << i)){
                if(LB[i])x ^= LB[i];
                else{LB[i] = x; break;}
            }
    }
    bool Exists(ll x){
        if(!x)return exist0;
        for(int i = LIM; i >= 0; --i)
            if(x & (1ll << i)){
                if(LB[i])x ^= LB[i];
                else return false;
            }
        return true;
    }
}lb;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A += read(), sum += A.back();
    sort(A.begin(), A.end(), greater < ll >());
    for(auto v : A)
        if(!lb.Exists(v))lb.Insert(v), cur += v;
    if(!cur)printf("-1\n"), exit(0);
    printf("%lld\n", sum - cur);
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