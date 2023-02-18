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
int A[5100];
int mxcnt(-1);
unordered_map < int, int > cnt;

void Check(int M){
    if(M < 3)return;
    cnt.clear(); mxcnt = 0;
    for(int i = 1; i <= N; ++i)
        mxcnt = max(mxcnt, ++cnt[A[i] % M]);
    if(mxcnt > (N >> 1))printf("%d\n", M), exit(0);
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    int T = 30;
    while(T--){
        int v1 = A[rndd(1, N)], v2 = A[rndd(1, N)];
        int base = abs(v1 - v2);
        for(int i = 1; (ll)i * i <= base; ++i)
            if(base % i == 0)Check(i), Check(base / i);
    }printf("-1\n");
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