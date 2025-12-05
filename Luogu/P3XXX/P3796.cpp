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

#define d(c) (c - 'a')

template < typename T = int >
inline T read(void);

struct Node{
    Node* son[26];
    Node* fail;
    int idx;
    OPNEW;
}nd[1100000];
ROPNEW_NODE;
Node* root;

int N;
ll mx(0);
ll cnt[200];
string S[200];
string Pattern;

void Insert(string S, int idx){
    Node* p = root;
    for(auto c : S){
        if(!p->son[d(c)])p->son[d(c)] = new Node();
        p = p->son[d(c)];
    }p->idx = idx;
}
void Build(void){
    queue < Node* > cur; cur.push(root);
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        for(int i = 0; i <= 25; ++i)
            if(p->son[i])cur.push(p->son[i]), p->son[i]->fail = p == root ? root : p->fail->son[i];
            else p->son[i] = p == root ? root : p->fail->son[i];
    }
}
void Accept(string S){
    Node* p = root;
    for(auto c : S){
        p = p->son[d(c)];
        for(auto cur = p; cur; cur = cur->fail)if(cur->idx)mx = max(mx, ++cnt[cur->idx]);
    }
}

int main(){
    while(true){
        root = new Node();
        mx = 0;
        for(int i = 1; i <= N; ++i)cnt[i] = 0;
        N = read();
        if(!N)break;
        for(int i = 1; i <= N; ++i){cin >> S[i]; Insert(S[i], i);}
        cin >> Pattern;
        Build(), Accept(Pattern);
        printf("%lld\n", mx);
        for(int i = 1; i <= N; ++i)if(cnt[i] == mx)cout << S[i] << endl;
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