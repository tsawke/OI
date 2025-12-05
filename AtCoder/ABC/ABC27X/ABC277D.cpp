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

int N, M;
basic_string < int > vals;
map < int, ll > rval;
ll sum(0), mx(0);
ll sum0[210000];


int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int val = read();
        vals += val, rval[val] += val;
        sum += val;
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int cur0(0);
    // printf("rval %lld %lld\n", rval[0], rval[1]);
    for(auto d : vals)if(d == cur0)++cur0, mx += rval[d]; else break;
    --cur0;
    // printf("mx = %lld\n", mx);
    // printf("cur0 is %d\n", cur0);
    for(int i = 0; i <= cur0; ++i)sum0[i] = (i > 0 ? sum0[i - 1] : 0) + rval[i];
    for(int i = vals.at(0) == 0 ? cur0 + 1 : 0; i < (int)vals.size(); ++i){
        int curlen(0), curv(vals.at(i));
        for(int j = i; j < (int)vals.size(); ++j){
            if(vals.at(j) == curv)++curv, ++curlen;
            else break;
        }
        ll cans(0);
        for(int j = i; j <= i + curlen - 1; ++j)cans += rval[vals.at(j)];
        if(curv == M)cans += i > 0 && cur0 >= 0 ? sum0[min(cur0, i - 1)] : 0;
        mx = max(mx, cans);
        i += curlen - 1;
    }printf("%lld\n", sum - mx);
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