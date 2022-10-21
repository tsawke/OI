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

#define int ll

template<typename T = int>
inline T read(void);

int N, Q;
int K;
int s[1100000];
stack < int > lft;
int ans(0);
void Solve(void){
    ans = 0;

    for(int i = 1; i <= N; ++i){
        s[i] -= K * i;
        if(lft.empty() || s[i] < s[lft.top()])lft.push(i);
    }
    // for(int i = 1; i <= N; ++i)printf("%d%c", s[i], i == N ? '\n' : ' ');
    int tpr(INT_MIN);
    for(int i = N; i >= 1; --i){
        if(s[i] >= 0)ans = max(ans, i);
        if(i == N || s[i] > tpr){
            while(!lft.empty() && s[i] - s[lft.top()] >= 0)
                ans = max(ans, i - lft.top()), lft.pop();
            tpr = s[i];
        }
    }
    for(int i = 1; i <= N; ++i)s[i] += K * i;
    while(!lft.empty())lft.pop();
}
signed main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)s[i] = read() + s[i - 1];
    while(Q--){
        K = read();
        Solve();
        printf("%lld%c", ans, Q ? ' ' : '\n');
    }
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