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
bool notPrime[1100000];
basic_string < int > Prime;
struct MyPair{int x, y;};
basic_string < MyPair > ans;

int main(){
    N = read();
    for(int i = 2; i <= N + 10; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if(p * i > 1010000)break;
            notPrime[p * i] = true;
            if(p % i == 0)break;
        }
    }
    for(auto p : Prime)if(p + 2 <= N && !notPrime[p + 2])ans += MyPair{2, p};
    printf("%d\n", (int)ans.size());
    for(auto p : ans)printf("%d %d\n", p.x, p.y);
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