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

template < typename T = int >
inline T read(void);

int N, M;
ll ans(0);
basic_string < int > arr;
basic_string < int > sub;
set < basic_string < int > > exist;

void dfs_sub(int dep = 1){
    if(dep > N){
        if(exist.find(sub) == exist.end())++ans, exist.insert(sub);
        return;
    }
    sub += arr.at(dep - 1);
    dfs_sub(dep + 1);
    sub.pop_back();
    dfs_sub(dep + 1);
}

void Cal(void){
    exist.clear();
    dfs_sub();
    ans %= MOD;
}

void dfs(int dep = 1){
    if(dep > N)return Cal();
    for(int i = 1; i <= M; ++i)
        arr += i, dfs(dep + 1), arr.pop_back();
}

int main(){
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    N = read(), M = read();
    if((ll)N * M > (ll)1e6)exit(1);
    if(M == 1)printf("%d\n", N + 1), exit(0);
    dfs();
    printf("%lld\n", ans);
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