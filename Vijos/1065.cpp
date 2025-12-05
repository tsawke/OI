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

int K, T;
bitset < 10 > ban;
basic_string < int > vals;
bitset < 1100000 > vis;

struct Node{
    int p; int val; Node* pre;
};
void Print(Node* p){
    basic_string < int > ans;
    for(auto cur = p; ~cur->val; cur = cur->pre)
        ans += cur->val;
    reverse(ans.begin(), ans.end());
    for(auto v : ans)printf("%d", v);
    printf("\n");
    exit(0);
}
void bfs(void){
    queue < Node* > cur;
    cur.push(new Node{0, -1, npt});
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        for(auto i : vals){
            if(p->p == 0 && i == 0)continue;
            int np = (p->p * 10 + i) % K;
            auto nod = new Node{np, i, p};
            if(!np)return Print(nod);
            if(vis[np])continue;
            vis[np] = true;
            cur.push(nod);
        }
    }
}

int main(){
    K = read(), T = read();
    for(int i = 1; i <= T; ++i)vals += read();
    bfs();
    printf("-1\n");
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