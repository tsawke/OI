#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Node::operator new(size_t){static Node* P = nd; return P++;}

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
    int cnt;
    OPNEW;
}nd[510000];
ROPNEW;
Node* root;

int N;
int ans(0);
string S;
basic_string < Node* > tmp;

void Insert(string S){
    Node* cur = root;
    for(auto c : S){
        if(!cur->son[d(c)])cur->son[d(c)] = new Node();
        cur = cur->son[d(c)];
    }cur->cnt++;
}
void Build(void){
    queue < Node* > cur; cur.push(root);
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        for(int i = 0; i <= 25; ++i)
            if(p->son[i]){
                cur.push(p->son[i]), tmp += p->son[i];
                if(p == root)p->son[i]->fail = root;
                else p->son[i]->fail = p->fail->son[i];
            }else{
                if(p == root)p->son[i] = root;
                else p->son[i] = p->fail->son[i];
            }
    }
}
void SetFail(void){
    for(auto p : tmp)p->cnt += p->fail->cnt;
}
void Accept(void){
    Node* cur = root;
    for(auto c : S){
        cur = cur->son[d(c)];
        if(cur->cnt)++ans, cur = root;
    }
}

int main(){
    root = new Node();
    cin >> S;
    N = read();
    for(int i = 1; i <= N; ++i){string T; cin >> T; Insert(T);}
    Build(), SetFail(), Accept();
    printf("%d\n", ans);
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