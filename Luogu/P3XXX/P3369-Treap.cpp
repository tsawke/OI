#include <bits/stdc++.h>

#include <unistd.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define LEFT true
#define RIGHT false

#define lsize(node) (node->ls ? node->ls->size : 0)
#define rsize(node) (node->rs ? node->rs->size : 0)

#define dire direction
#define npt nullptr
#define pri priority

template<typename T = int>
inline T read(void);
struct Treap{
    Treap *ls, *rs;
    int size;
    int val;
    int cnt;
    int pri;
    Treap(int val){
        this->val = val;
        this->ls = this->rs = npt;
        this->size = this->cnt = 1;
        this->pri = rand();
    }
};
int chkS(Treap *node){if(node == npt)return 0; return (rsize(node)) - (lsize(node));}
int chkP(Treap *node){
    if(node == npt)return 0;
    if(node->ls == npt && node->rs == npt)return 0;
    if(node->ls == npt)return INT_MIN;
    if(node->rs == npt)return INT_MAX;
    return node->rs->pri - node->ls->pri;
}
int N;
int CalSuf(Treap*, int);
int CalPre(Treap*, int);
int QueryVal(Treap*, int);
int QueryRank(Treap*, int);
void Delete(Treap*&, int);
void Insert(Treap*&, int);
void Rotate(Treap*&, bool);
void Pushup(Treap*);
void Desc(void);
void DescTree(Treap*);
Treap *root;
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    srand(315); (void)rand();
    N = read();
    (void)read(); int _val = read();
    root = new Treap(_val);
    for(int i = 2; i <= N; ++i){
        int opt = read(), x = read();
        switch(opt){
            case 1:{Insert(root, x); break;}
            case 2:{Delete(root, x); break;}
            case 3:{printf("%d\n", QueryRank(root, x)); break;}
            case 4:{printf("%d\n", QueryVal(root, x)); break;}
            case 5:{printf("%d\n", CalPre(root, x)); break;}
            case 6:{printf("%d\n", CalSuf(root, x)); break;}
        }
    }
    return 0;
}
int CalSuf(Treap *node, int val){
    int ret(INT_MAX);
    while(node != npt){
        if(val < node->val)ret = node->val, node = node->ls;
        else node = node->rs;
    }
    return ret;
}
int CalPre(Treap *node, int val){
    int ret(-1);
    while(node != npt){
        if(val > node->val)ret = node->val, node = node->rs;
        else node = node->ls;
    }
    return ret;
}
int QueryVal(Treap *node, int rank){
    // printf("Node--- left%d, right%d\n", node->ls, node->rs);
    // if(node == npt)return -1;
    // if(cur + (lsize(node)) + node->cnt < rank)return QueryVal(node->rs, rank, cur + (lsize(node)) + node->cnt);
    // else if(cur + (lsize(node)) >= rank)return QueryVal(node->ls, rank, cur);
    // else return node->val;
    if(node == npt)return -1;
    if(rank <= (lsize(node))) return QueryVal(node->ls, rank);
    else if(rank <= (lsize(node)) + node->cnt)return node->val;
    else return QueryVal(node->rs, rank - (lsize(node)) - node->cnt);
}
int QueryRank(Treap *node, int val){
    // printf("Querying Val= %d, node->val = %d\n", val, node->val);
    if(node == npt)return -1;
    if(val == node->val)return (lsize(node)) + 1;
    else if(val < node->val){
        if(node->ls == npt)return 1;
        else return QueryRank(node->ls, val);
    }else{
        if(node->rs == npt)return node->size + 1;
        else return (lsize(node)) + node->cnt + QueryRank(node->rs, val);
    }
    // if(val > node->val)return QueryRank(node->rs, val, cur + (lsize(node)) + node->cnt);
    // else return QueryRank(node->ls, val, cur);
}
void Delete(Treap *&node, int val){
    // Desc();printf("\n");sleep(5);
    if(node == npt)return;
    if(val == node->val){
        if(node->cnt >= 2){node->cnt--; node->size--; return;}
        if(node->ls == npt && node->rs == npt){node = npt; return;}//return (void)(node = npt);
        if(node->ls == npt || node->rs == npt){node = node->ls ? node->ls : node->rs; return;}
        if(node->ls->pri < node->rs->pri)Rotate(node, RIGHT), Delete(node->rs, val);
        else Rotate(node, LEFT), Delete(node->ls, val);
        Pushup(node);
        return;
    }
    else if(val < node->val)Delete(node->ls, val);
    else Delete(node->rs, val);
    Pushup(node);
}
void Insert(Treap *&node, int val){
    if(node == npt)return (void)(node = new Treap(val));
    if(node->val == val){node->cnt++, node->size++; return;}
    if(val < node->val)Insert(node->ls, val);
    else Insert(node->rs, val);
    if(node->ls != npt && node->ls->pri < node->pri)Rotate(node, RIGHT);
    if(node->rs != npt && node->rs->pri < node->pri)Rotate(node, LEFT);
    Pushup(node);
}
void Rotate(Treap *&node, bool dire){
    if(node == npt || (node->ls == npt && dire == RIGHT) || (node->rs == npt && dire == LEFT))return;
    // if(dire == LEFT){
    //     auto tmp = node;
    //     if(node != npt)swap(node, node->rs);
    //     if(node != npt && tmp != npt)swap(tmp->rs, node->ls);//node->rs=>node,  node=>node->rs
    //     Pushup(node), Pushup(node->ls);
    // }
    // else{
    //     auto tmp = node;
    //     if(node != npt)swap(node, node->ls);
    //     if(node != npt && tmp != npt)swap(tmp->ls, node->rs);
    //     Pushup(node), Pushup(node->rs);
    // }
    if(dire == LEFT){//node, node->rs != npt
        auto tmp = node->rs;
        node->rs = node->rs->ls;
        tmp->ls = node;
        Pushup(tmp), Pushup(node);
        node = tmp;
    }
    else{//node, node->ls != npt
        auto tmp = node->ls;
        node->ls = node->ls->rs;
        tmp->rs = node;
        Pushup(tmp), Pushup(node);
        node = tmp;
    }
}
void Pushup(Treap *node){
    if(node == npt)return;
    // node->lsize = node->ls == npt ? 0 : node->ls->lsize + node->ls == npt ? 0 : node->ls->rsize + node->ls->cnt;
    // node->rsize = node->rs == npt ? 0 : node->rs->lsize + node->rs == npt ? 0 : node->rs->rsize + node->rs->cnt;
    node->size = node->cnt + (lsize(node)) + (rsize(node));
}
void Desc(void){DescTree(root);}
void DescTree(Treap *node){
    if(node == npt)return;
    printf("%d ls->%d, rs->%d\n", node->val, node->ls == npt ? -1 : node->ls->val, node->rs == npt ? -1 : node->rs->val);
    if(node->ls != npt)DescTree(node->ls);
    if(node->rs != npt)DescTree(node->rs);
    fflush(stdout);
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