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

int N, tN, Q;
int a[510000];
int mp[510000];
basic_string < int > data;

struct Node{
    Node *ls, *rs;
    int val;
    OPNEW;
}nd[510000 << 5];
void* Node::operator new(size_t){static Node* P = nd; return P++;}
Node* rt[510000];

class PerSegTree{
private:
    #define MID ((gl + gr) >> 1)
    #define SIZ(ptr) (ptr ? ptr->val : 0)
public:
    auto Build(int gl = 1, int gr = N){
        if(gl == gr)return new Node{};
        return new Node{Build(gl, MID), Build(MID + 1, gr)};
    }
    auto Modify(int val, Node* lst, int gl = 1, int gr = N){
        Node* node = new Node{lst->ls, lst->rs, lst->val + 1};
        if(gl == gr)return node;
        if(val <= MID)node->ls = Modify(val, node->ls, gl, MID);
        else node->rs = Modify(val, node->rs, MID + 1, gr);
        return node;
    }
    auto Query(Node* lst, Node* cur, int lim, int gl = 1, int gr = N){
        if(gl == gr)return gl = gr;
        if(SIZ(cur->ls) - SIZ(lst->ls) > lim)return Query(lst->ls, cur->ls, lim, gl, MID);
        if(SIZ(cur->rs) - SIZ(lst->rs) > lim)return Query(lst->rs, cur->rs, lim, MID + 1, gr);
        return 0;
    }
}pst;


int main(){
    tN = read(), Q = read();
    for(int i = 1; i <= tN; ++i)data += a[i] = read();
    sort(data.begin(), data.end()); data.erase(unique(data.begin(), data.end()), data.end());
    N = data.size();
    for(int i = 1; i <= tN; ++i){
        rt[i] = pst.Modify()
    }
pst.Build();    
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