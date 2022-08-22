#include <bits/stdc++.h>

#include <unistd.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define LEFT true
#define RIGHT false

#define dire direction
#define npt nullptr
#define pri priority

template<typename T = int>
inline T read(void);
struct Treap{
    Treap *fa;
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
int chkS(Treap *node){if(node == npt)return 0; return (node->rs == npt ? 0 : node->rs->size) - (node->ls == npt ? 0 : node->ls->size);}
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
int QueryVal(Treap*, int, int);
int QueryRank(Treap*, int, int);
void Delete(Treap*&, int);
void Insert(Treap*&, int);
void Rotate(Treap*&, bool);
void Pushup(Treap*);
void Desc(void);
void DescTree(Treap*);
Treap *root;
int main(){
    freopen("in.txt", "r", stdin);
    srand(315); (void)rand();
    N = read();
    (void)read(); int _val = read();
    root = new Treap(_val);
    for(int i = 2; i <= N; ++i){
        int opt = read(), x = read();
        switch(opt){
            case 1:{Insert(root, x); break;}
            case 2:{Delete(root, x); break;}
            case 3:{printf("%d\n", QueryRank(root, x, 0)); break;}
            case 4:{printf("%d\n", QueryVal(root, x, 0)); break;}
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
int QueryVal(Treap *node, int rank, int cur){
    // printf("Node--- left%d, right%d\n", node->ls, node->rs);
    if(node == npt)return -1;
    if(cur + (node->ls == npt ? 0 : node->ls->size) + node->cnt < rank)return QueryVal(node->rs, rank, cur + (node->ls == npt ? 0 : node->ls->size) + node->cnt);
    else if(cur + (node->ls == npt ? 0 : node->ls->size) >= rank)return QueryVal(node->ls, rank, cur);
    else return node->val;
}
int QueryRank(Treap *node, int val, int cur){
    if(node == npt)return -1;
    if(val == node->val)return cur + (node->ls == npt ? 0 : node->ls->size) + 1;
    if(val > node->val)return QueryRank(node->rs, val, cur + (node->ls == npt ? 0 : node->ls->size) + node->cnt);
    else return QueryRank(node->ls, val, cur);
}
void Delete(Treap *&node, int val){
    // Desc();printf("\n");sleep(5);
    if(node == npt)return;
    if(val == node->val){
        if(node->cnt >= 2){node->cnt--; Pushup(node); return;}
        if(node->ls == npt && node->rs == npt)return (void)(node = npt);
        if(chkP(node) > 0)Rotate(node, RIGHT), Delete(node->ls, val);
        else Rotate(node, LEFT), Delete(node->rs, val);
        Pushup(node);
        return;
    }
    if(val < node->val)Delete(node->ls, val);
    else Delete(node->rs, val);
    Pushup(node);
}
void Insert(Treap *&node, int val){
    if(node == npt)return (void)(node = new Treap(val));
    if(node->val == val)return (void)node->cnt++;
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
        node = tmp;
    }
    else{//node, node->ls != npt
        auto tmp = node->ls;
        node->ls = node->ls->rs;
        tmp->rs = node;
        node = tmp;
    }
}
void Pushup(Treap *node){
    if(node == npt)return;
    // node->lsize = node->ls == npt ? 0 : node->ls->lsize + node->ls == npt ? 0 : node->ls->rsize + node->ls->cnt;
    // node->rsize = node->rs == npt ? 0 : node->rs->lsize + node->rs == npt ? 0 : node->rs->rsize + node->rs->cnt;
    node->size = node->cnt + (node->ls == npt ? 0 : node->ls->size) + (node->rs == npt ? 0 : node->rs->size);
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