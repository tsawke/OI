#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

#define npt nullptr
#define siz(p) (p ? p->siz : 0)
#define son(p, dir) ((dir) ? p->rson : p->lson)

struct Node{
    Node* lson;
    Node* rson;
    Node* fa;
    int cnt;
    int siz;
    int val;
    bool rev;
    int lz;
};

Node* root;

class LCT{
private:
public:
    void PushUp(Node* p){
        p->siz = p->cnt + siz(p->lson) + siz(p->rson);
    }
    void Reverse(Node* p){
        swap(p->lson, p->rson);
        p->rev ^= true;
    }
    void PushDown(Node* p){
        if(!p->rev)return;
        if(p->lson)Reverse(p->lson);
        if(p->rson)Reverse(p->rson);
        p->rev ^= true;
    }
    bool IsRoot(Node* p){
        return !p->fa ? true : (p->fa->lson != p && p->fa->rson != p);
    }
    bool GetDir(Node* p){
        return p->fa ? p->fa->rson == p : false;
    }
    void Connect(Node* p, Node* fa, bool dir){
        if(fa)son(fa, dir) = p, PushUp(fa);
        if(p)p->fa = fa;
    }
    void Rotate(Node* p){
        auto fa = p->fa, gfa = fa->fa;
        auto dir1 = GetDir(p), dir2 = GetDir(fa);
        if(!IsRoot(fa))son(gfa, dir2) = p;
        Connect(son(p, !dir1), fa, dir1), Connect(fa, p, !dir1), Connect(p, gfa, dir2);
    }
    void Update(Node* p){
        if(!p)return;
        if(!IsRoot(p))Update(p->fa);
        PushDown(p);
    }
    void Splay(Node* p){
        if(!p)return;
        Update(p);
        while(p->fa)
            if(!IsRoot(p->fa))
                Rotate(GetDir(p) == GetDir(p->fa) ? p->fa : p);
    }
    Node* Access(Node* p){
        auto cur = root;
        while(p){
            Splay(p), p->rson = cur, PushUp(p);
            cur = p, p = p->fa;
        }return cur;
    }
    void MakeRoot(Node* p){
        p = Access(p);
        if(!p)return;
        swap(p->lson, p->rson);
        p->rev ^= 1;
    }
    void Link(Node* p, Node* fa){
        MakeRoot(p);
        Splay(p);
        p->fa = fa;
    }
    void Split(Node* x, Node* y){
        MakeRoot(x), Access(y), Splay(y);
    }
    void Cut(Node* x, Node* y){
        Split(x, y);
        x->fa = y->lson = npt;
    }
    Node* Find(Node* p){
        Access(p), Splay(p);
        while(p->lson)p = p->lson, PushDown(p);
        Splay(p);
        return p;
    }
}lct;

int main(){


    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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