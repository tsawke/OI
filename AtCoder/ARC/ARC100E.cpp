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
int Smx = (1 << 18) - 1;
int val[280000];
pair < int, int > mx[280000];

int main(){
    auto Merge = [](pair < int, int > A, pair < int, int > B)->pair < int, int >{
        basic_string < int > vals;
        vals += {A.first, A.second, B.first, B.second};
        sort(vals.begin(), vals.end(), greater < int >());
        return {vals.at(0), vals.at(1)};
    };
    N = 1 << read();
    for(int i = 0; i <= N - 1; ++i){
        val[i] = read();
        mx[i] = {val[i], 0};
    }
    for(int i = 0; i <= 17; ++i)
        for(int S = Smx; S; S = (S - 1) & Smx)
            if(S & (1 << i))
                mx[S] = Merge(mx[S], mx[S ^ (1 << i)]);
    int ans(0);
    for(int K = 1; K <= N - 1; ++K){
        if(mx[K].first && mx[K].second)ans = max(ans, mx[K].first + mx[K].second);
        printf("%d\n", ans);
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