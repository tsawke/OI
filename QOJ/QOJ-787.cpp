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

#define S(i) (S.at(i - 1))

template < typename T = int >
inline T read(void);

int N;
string S, baseS;
int dp[2100000];
int ans(0);

int main(){
    cin >> baseS;
    S += '#';
    for(auto c : baseS)S += {c, '#'};
    N = S.length();
    int mxr(0), mid(0);
    for(int i = 1; i <= N; ++i){
        int len = i > mxr ? 0 : min(mxr - i, dp[mid - (i - mid)]);
        while(i + len + 1 <= N && i - len - 1 >= 1 && S(i + len + 1) == S(i - len - 1))++len;
        dp[i] = len;
        if(i + len > mxr)mxr = i + len, mid = i;
    }for(int i = 1; i <= N; ++i)ans = max(ans, dp[i]);
    printf("%d\n", ans);
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