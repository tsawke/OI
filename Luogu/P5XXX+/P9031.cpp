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

#define P(i) (Prime.at(i - 1))
#define LIMV_SIZE (int)(1e7)

template < typename T = int >
inline T read(void);

int N;
int tot;
int LIMV(0);
pair < int, int > pos[1100000];
bitset < LIMV_SIZE + 114514 > notPrime;
basic_string < int > Prime;
pair < int, int > fact[LIMV_SIZE + 114514];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)LIMV = max({LIMV, pos[i].first = read(), pos[i].second = read()});
    for(int i = 2; i <= LIMV; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if((ll)i * p > LIMV)break;
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }tot = Prime.size();
    auto dfs = [](auto&& self, int dep = 1, int cnt2 = 0, int cnt_odd = 1, ll val = 1)->void{
        if(val > LIMV)return;
        if(dep > tot || val * P(dep) > LIMV)return fact[val] = {cnt2, cnt_odd}, void();
        int tims(1);
        while(val <= LIMV){
            self(self, dep + 1, cnt2, cnt_odd, val);
            val *= P(dep);
            if(P(dep) == 2)++cnt2;
            else cnt_odd /= tims, cnt_odd *= ++tims;
        }
    }; dfs(dfs);
    for(int i = 1; i <= N; ++i){
        int X = pos[i].first, Y = pos[i].second;
        if(!X && !Y){printf("0\n"); continue;}
        if(!X || !Y){printf("%d\n", fact[X ^ Y].second); continue;}
        int pow2X = fact[X].first, pow2Y = fact[Y].first;
        if((!pow2X && !pow2Y) || pow2X == pow2Y){printf("0\n"); continue;}
        printf("%d\n", fact[__gcd(X, Y)].second);
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
    }ret *= flag;
    return ret;
}