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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

string S;
map < pair < __int128_t, int >, ll > mp;

ll dfs(__int128_t S, int len){
    if(!len)return 1;
    if(mp.find({S, len}) != mp.end())return mp[{S, len}];
    ll ret(0);
    (ret += dfs(S >> 1, len - 1) * (S & 1 ? 2 : 1) % MOD) %= MOD;
    __int128_t siz(0), cur(0);
    for(int slen = 1; slen <= len; ++slen){
        (siz <<= 1) |= 1, cur = S & siz;
        for(int rlen = slen << 1; rlen <= len; rlen += slen){
            cur &= S >> (rlen - slen);
            (ret += dfs(cur, slen) * dfs(S >> rlen, len - rlen) % MOD) %= MOD;
        }
    }return mp[{S, len}] = ret;
}

int main(){
    cin >> S;
    int N = S.length();
    __int128_t cur(0);
    for(int i = 0; i < N; ++i)
        cur |= (__int128_t)(S.at(i) == '1') << i;
    printf("%lld\n", dfs(cur, N));
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