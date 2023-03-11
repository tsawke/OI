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
#define c(d) (char(d + 'a'))

template < typename T = int >
inline T read(void);

struct Node{
    Node* tr[26];
    Node* fail;
    int len;
    OPNEW;
}nd[110000];
ROPNEW_NODE;
Node* root;

basic_string < char > ans;

void Insert(string S){
    Node* p = root;
    for(auto c : S){
        if(!p->tr[d(c)])p->tr[d(c)] = new Node();
        p = p->tr[d(c)];
    }p->len = S.length();
}
void Build(void){
    queue < Node* > cur;
    cur.push(root);
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        for(int i = 0; i < 26; ++i)
            if(p->tr[i])p->tr[i]->fail = p == root ? root : p->fail->tr[i], cur.push(p->tr[i]);
            else p->tr[i] = p == root ? root : p->fail->tr[i];
    }
}
void Accept(string S){
    basic_string < Node* > cur;
    cur += root;
    Node* p = root;
    for(auto c : S){
        p = p->tr[d(c)];
        ans += c, cur += p;
        if(p->len){
            for(int i = 1; i <= p->len; ++i)ans.pop_back(), cur.pop_back();
            p = cur.back();
        }
    }
}

string pat, txt;

int main(){
    root = new Node();
    cin >> txt;
    int N = read();
    while(N--)cin >> pat, Insert(pat);
    Build(), Accept(txt);
    for(auto c : ans)printf("%c", c);
    printf("\n");
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