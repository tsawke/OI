#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
// #define E M_E
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

int N, M, K;
ll P[1100000];
int C[1100000];
int cnt[1100000];
basic_string < int > cry[510000];
ll E[1100000];
ll cur(0);
ll ans(0);

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    N = read(), M = read(), K = read();
    for(int i = 1; i <= N; ++i)E[i] = E[i + N] = read();
    for(int i = 1; i <= K; ++i){
        C[i] = read(), P[i] = read();
        for(int j = 1; j <= C[i]; ++j){
            int idx = read();
            cry[idx] += i;
        }
    }
    int l = 1, r = 0;
    auto add = [](int idx)->void{
        if(idx > N)idx -= N;
        for(auto p : cry[idx]){
            if(++cnt[p] == C[p])cur += P[p];
            ans = max(ans, cur);
        }
    };
    auto erase = [](int idx)->void{
        if(idx > N)idx -= N;
        for(auto p : cry[idx]){
            if(cnt[p]-- == C[p])cur -= P[p];
        }
    };
    ll sum(0);
    while(l < N * 2){
        while(r < N * 2 && sum + E[r + 1] <= M)add(++r), sum += E[r];
        sum -= E[l], erase(l++);
    }printf("%lld\n", ans);
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
/*
5 4 3
4 1 1 2 1
2 4 1 5
1 1 3
2 2 2 4

6 5 5
2 3 1 2 1 2
3 10 1 3 5
2 4 4 6
2 3 3 5
2 5 1 6
2 2 3 4
*/