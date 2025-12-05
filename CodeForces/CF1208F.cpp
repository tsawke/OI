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

const int Smx = (1 << 21) - 1;
int N;
int A[2500000];
int mnp[2500000];
pair < int, int > mxp[2500000];

int main(){
    auto Merge = [](pair < int, int > A, pair < int, int > B)->pair < int, int >{
        basic_string < int > vals;
        vals += {A.first, A.second, B.first, B.second};
        sort(vals.begin(), vals.end(), greater < int >());
        return {vals.at(0), vals.at(1)};
    };
    auto Check = [](int val)->bool{
        for(int sub = val; ~sub; --sub/*sub = (sub - 1) & val*/)if(mnp[sub] < mxp[sub ^ val].second)return true;
        return false;
    };
    memset(mnp, 0x3f, sizeof mnp);
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= N; ++i)mnp[A[i]] = min(mnp[A[i]], i), mxp[A[i]] = Merge(mxp[A[i]], {i, 0});
    for(int i = 0; i <= 20; ++i)
        for(int S = Smx; ~S; --S/*S = (S - 1) & Smx*/)
            if(!(S & (1 << i)))
                mnp[S] = min(mnp[S], mnp[S ^ (1 << i)]), mxp[S] = Merge(mxp[S], mxp[S ^ (1 << i)]);
    int cur(0);
    for(int i = 20; i >= 0; --i)
        if(Check(cur | (1 << i)))cur |= 1 << i;
    printf("%d\n", cur);
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