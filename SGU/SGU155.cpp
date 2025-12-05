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

int N;
struct Node{
    int idx, k, v;
    friend const bool operator < (const Node &a, const Node &b){
        return a.k < b.k;
    }
}nod[51000];
unordered_map < int, int > mp, idx;
int lson[51000], rson[51000], fa[51000];
stack < int > cur;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int k = read(), v = read();
        nod[i] = Node{i, k, v};
        mp.insert({k, v});
        idx.insert({k, i});
    }sort(nod + 1, nod + N + 1);
    for(int i = 1; i <= N; ++i){
        while(!cur.empty() && mp[cur.top()] > nod[i].v)
            lson[nod[i].idx] = idx[cur.top()], cur.pop();
        if(!cur.empty())rson[idx[cur.top()]] = nod[i].idx;
        cur.push(nod[i].k);
    }for(int i = 1; i <= N; ++i)
        fa[lson[i]] = i, fa[rson[i]] = i;
    int cnt(0);
    for(int i = 1; i <= N; ++i)if(!fa[i])++cnt;
    if(cnt > 1)printf("NO\n"), exit(0);
    printf("YES\n");
    for(int i = 1; i <= N; ++i)printf("%d %d %d\n", fa[i], lson[i], rson[i]);
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