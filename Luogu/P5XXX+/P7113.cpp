#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);
void Print128(__int128_t x){
    vector < int > p;
    while(x)p.emplace_back(x % 10), x /= 10;
    for(auto it = p.rbegin(); it != p.rend(); ++it)printf("%d", *it);
}

struct Frac{
    __int128_t a, b;
    Frac shrink(void){
        __int128_t div = __gcd(a, b);
        a /= div, b /= div;
        return *this;
    }
    friend const Frac operator + (const Frac &x, const Frac &y){
        __int128_t below = x.b * y.b / __gcd(x.b, y.b);
        return Frac{below / x.b * x.a + below / y.b * y.a, below}.shrink();
    }
    friend const Frac operator / (const Frac &x, const int &v){
        return Frac{x.a, x.b * v}.shrink();
    }
};

queue < int > node;
int N, M;
int ind[110000];
vector < int > vert[110000];
Frac v[110000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        v[i] = Frac{0, 1};
        int d = read();
        while(d--){
            int x = read();
            vert[i].push_back(x);
            ind[x]++;
        }
    }
    for(int i = 1; i <= N; ++i)if(!ind[i])node.push(i), v[i].a = 1;
    while(!node.empty()){
        int p = node.front(); node.pop();
        Frac addv = v[p] / (int)vert[p].size();
        for(auto i : vert[p]){
            --ind[i];
            v[i] = v[i] + addv;
            if(!ind[i])node.push(i);
        }
    }
    for(int i = 1; i <= N; ++i)if(!vert[i].size())Print128(v[i].a), printf(" "), Print128(v[i].b), printf("\n");
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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