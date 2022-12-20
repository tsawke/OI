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

int N, K;
string str[20];
int buc[30];
int ans(0);

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)cin >> str[i];
    int Smx = (1 << N) - 1;
    for(int S = Smx; S; S = (S - 1) & Smx){
        memset(buc, 0, sizeof buc);
        int cnt(0);
        for(int i = 0; i < N; ++i)
            if(S & (1 << i))
                for(auto c : str[i + 1])
                    buc[c - 'a' + 1]++;
        for(int i = 1; i <= 26; ++i)if(buc[i] == K)++cnt;
        ans = max(ans, cnt);
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