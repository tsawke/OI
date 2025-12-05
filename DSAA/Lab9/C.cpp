#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
inline T read(void);

class Node{
public:
    Node *ls, *rs;
    int val, siz, cnt;
};

Node* root;

#define siz(p) ((p) ? (p)->siz : 0)
class Tree{
private:
public:
    void Pushup(Node* p){
        if(!p)return;
        p->siz = siz(p->ls) + siz(p->rs) + p->cnt;
    }
    Node* QueryMx(Node* p = root){
        if(!p)return p;
        if(p->rs)return QueryMx(p->rs);
        return p;
    }
    Node* QueryMn(Node* p = root){
        if(!p)return p;
        if(p->ls)return QueryMn(p->ls);
        return p;
    }
    Node* Insert(int val, Node* p = root){
        if(!p)return new Node{nullptr, nullptr, val, 1, 1};
        if(val < p->val)p->ls = Insert(val, p->ls);
        else if(val > p->val)p->rs = Insert(val, p->rs);
        else ++p->cnt;
        Pushup(p);
        return p;
    };
    Node* Delete(int val, Node* p = root){
        if(!p)return p;
        if(val < p->val)p->ls = Delete(val, p->ls);
        else if(val > p->val)p->rs = Delete(val, p->rs);
        else{
            if(p->cnt > 1)--p->cnt;
            else{
                if(!p->ls)delete exchange(p, p->rs);
                else if(!p->rs)delete exchange(p, p->ls);
                else{
                    auto succ = QueryMn(p->rs);
                    p->val = succ->val, p->cnt = succ->cnt;
                    succ->cnt = 1;
                    p->rs = Delete(succ->val, p->rs);
                }
            }
        }Pushup(p); return p;
    }
    int QueryRnk(int val, Node* p = root){
        if(!p)return 0;
        if(val == p->val)return siz(p->ls);
        if(val < p->val)return QueryRnk(val, p->ls);
        return siz(p->ls) + p->cnt + QueryRnk(val, p->rs);
    }
    Node* QueryByRnk(int rnk, Node* p = root){
        if(!p)return p;
        if(siz(p->ls) + 1 <= rnk && rnk <= siz(p->ls) + p->cnt)return p;
        if(rnk <= siz(p->ls))return QueryByRnk(rnk, p->ls);
        return QueryByRnk(rnk - siz(p->ls) - p->cnt, p->rs);
    }
    Node* QuerySuc(int val, Node* p = root){
        if(!p)return p;
        if(val >= p->val)return QuerySuc(val, p->rs);
        auto res = QuerySuc(val, p->ls);
        return res ? res : p;
    }
    Node* QueryPre(int val, Node* p = root){
        if(!p)return p;
        if(val <= p->val)return QueryPre(val, p->ls);
        auto res = QueryPre(val, p->rs);
        return res ? res : p;
    }
}tr;

int main(){
    int T = read();
    while(T--){
        int opt = read(), val = read();
        switch(opt){
            case 1: root = tr.Insert(val); break;
            case 2: root = tr.Delete(val); break;
            case 3: printf("%d\n", tr.QueryRnk(val) + 1); break;
            case 4: printf("%d\n", tr.QueryByRnk(val)->val); break;
            case 5: printf("%d\n", tr.QueryPre(val)->val); break;
            case 6: printf("%d\n", tr.QuerySuc(val)->val); break;
        }
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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