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
    int ind;
    int ans;
    OPNEW;
}nd[210000];
ROPNEW_NODE;
Node* root;

int N;
ll mx(0);
ll cnt[210000];
ll hashv[210000];
string Pattern;
unordered_map < ll, ll > mp;
basic_string < Node* > tot;

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
            if(p->son[i])cur.push(p->son[i]), tot += p->son[i], p->son[i]->fail = p == root ? root : p->fail->son[i], ++p->son[i]->fail->ind;
            else p->son[i] = p == root ? root : p->fail->son[i];
    }
}
void Accept(string S){
    Node* p = root;
    for(auto c : S){
        p = p->son[d(c)];
        // for(auto cur = p; cur; cur = cur->fail)if(cur->idx)mx = max(mx, ++cnt[cur->idx]);
        p->ans++;
    }
}
void Topo(void){
    queue < Node* > cur;
    for(auto p : tot)if(!p->ind)cur.push(p);
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        if(p->idx)cnt[p->idx] = p->ans;
        if(p->fail){
            p->fail->ind--, p->fail->ans += p->ans;
            if(!p->fail->ind)cur.push(p->fail);
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    root = new Node();
    N = read();
    for(int i = 1; i <= N; ++i){string S; cin >> S; hashv[i] = hash < string >{}(S); Insert(S, i);}
    cin >> Pattern;
    Build(), Accept(Pattern), Topo();
    for(int i = 1; i <= N; ++i)if(cnt[i])mp[hashv[i]] = cnt[i];
    for(int i = 1; i <= N; ++i)cout << mp[hashv[i]] << endl;
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