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

#define MOD (ll)(1e9 + 7)
#define S(i) (S.at(i - 1))

template < typename T = int >
inline T read(void);

string S;
int nxt[1100000];
int num[1100000];

int main(){
    int T = read();
    while(T--){
        ll ans(1);
        cin >> S;
        int N = S.length();
        int lst(0);
        nxt[0] = nxt[1] = num[0] = 0, num[1] = 1;
        for(int i = 2; i <= N; ++i){
            while(lst && S(lst + 1) != S(i))lst = nxt[lst];
            if(S(lst + 1) == S(i))++lst;
            nxt[i] = lst, num[i] = num[lst] + 1;
        }lst = 0;
        for(int i = 2; i <= N; ++i){
            while(lst && S(lst + 1) != S(i))lst = nxt[lst];
            if(S(lst + 1) == S(i))++lst;
            while(lst > (i >> 1))lst = nxt[lst];
            (ans *= (num[lst] + 1)) %= MOD;
        }
        // int same(1);
        // while(same + 1 <= N && S(same + 1) == S(same))++same;
        // ll ans(1);
        // for(int i = 1; i <= N; ++i)(ans *= nxt[i] ? (S(1) == S(i) ? min(nxt[i] + 1, same + 1) : 2) : 1) %= MOD;
        printf("%lld\n", ans);
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
    }
    ret *= flag;
    return ret;
}