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

string S, T;
char s[1100000];
int dp[1100000];
int nxt[1100000];

int main(){
    memset(dp, 0x3f, sizeof dp);
    cin >> S >> T;
    sprintf(s + 1, "%s#%s", S.c_str(), T.c_str());
    int lenS = S.length(), lenT = T.length();
    dp[lenS + 1] = 0;
    int cur(0);
    for(int i = 2; i <= lenS + lenT + 1; ++i){
        while(cur && s[cur + 1] != s[i])cur = nxt[cur];
        if(s[cur + 1] == s[i])++cur;
        if(i > lenS + 1)dp[i] = dp[i - cur] + 1;
        nxt[i] = cur;
    }printf("%d\n", dp[lenS + lenT + 1] < 0x3f3f3f3f ? dp[lenS + lenT + 1] : -1);
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