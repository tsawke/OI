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
#define sum(p) (p ? p->sum : 0)
#define son(p, dir) ((dir) ? p->rson : p->lson)

struct Node{
    Node* lson;
    Node* rson;
    Node* fa;
    int cnt;
    int siz;
    int val;
    int sum;
    bool rev;
};

class LCT{
private:
public:
    void PushUp(Node* p){
        p->siz = p->cnt + siz(p->lson) + siz(p->rson);
        p->sum = sum(p->lson) ^ sum(p->rson) ^ p->val;
    }
    void Reverse(Node* p){
        swap(p->lson, p->rson);
        p->rev ^= true;
    }
    void PushDown(Node* p){
        if(!p->rev)return;
        if(p->lson)Reverse(p->lson);
        if(p->rson)Reverse(p->rson);
        p->rev = false;
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
        while(!IsRoot(p)){
            if(!IsRoot(p->fa))
                Rotate(GetDir(p) == GetDir(p->fa) ? p->fa : p);
            Rotate(p);
        }PushUp(p);
    }
    void Access(Node* p){
        Node* lst = npt;
        while(p){
            Splay(p), Connect(lst, p, true), PushUp(p);
            lst = p, p = p->fa;
        }
    }
    void MakeRoot(Node* p){
        Access(p), Splay(p);
        if(!p)return;
        swap(p->lson, p->rson);
        p->rev ^= 1;
        PushUp(p);
    }
    void Link(Node* p, Node* fa){
        if(FindRoot(p) == FindRoot(fa)) return;
        MakeRoot(p);
        Splay(p);
        p->fa = fa;
    }
    void Split(Node* p, Node* fa){
        MakeRoot(p), Access(fa), Splay(fa);
    }
    void Cut(Node* p, Node* fa){
        if(FindRoot(p) != FindRoot(fa))return;
        Split(p, fa);
        if(p->fa != fa || p->rson)return;
        p->fa = fa->lson = npt;
        PushUp(p); PushUp(fa);
    }
    Node* FindRoot(Node* p){
        Access(p), Splay(p);
        while(p->lson)PushDown(p), p = p->lson;
        Splay(p);
        return p;
    }
}lct;

Node* p[110000];

int main(){
    int N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int val = read();
        p[i] = new Node{npt, npt, npt, 1, 1, val, val, false};
    }
    while(M--){
        int opt = read(), x = read(), y = read();
        // printf("Get opt = %d\n", opt);
        switch(opt){
            case 0: lct.Split(p[x], p[y]), printf("%d\n", p[y]->sum); break;
            case 1: lct.Link(p[x], p[y]); break;
            case 2: lct.Cut(p[x], p[y]); break;
            case 3: lct.Splay(p[x]); p[x]->val = y; lct.PushUp(p[x]); break;
        }
    }

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