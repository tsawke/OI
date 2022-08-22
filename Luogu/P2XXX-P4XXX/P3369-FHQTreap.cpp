#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
#define sptr shared_ptr < Treap > 

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

template<typename T = int>
inline T read(void);

struct Treap{
    sptr ls, rs;
    int size;
    int val;
    int pri;
    void* operator new(size_t);
    Treap(int, int = 1);
};
sptr npt( new Treap(0, 0) );
int main(){


    
    return 0;
}
Treap::Treap(int _val, int _size):size(_size), val(_val){ this->pri = rnd(); this->ls = this->rs = npt; }
void Merge()
pair<sptr, sptr> Split(sptr node, int val){
    if(node == npt)return {npt, npt};
    if(node->val < val){
        sptr lt, rt;
        tie(lt, rt) = Split(node->rs, val);
        node->rs = lt;
        return {node, rt};
    }
    else{
        sptr lt, rt;
        tie(lt, rt) = Split(node->ls, val);
        node->ls = rt;
        return {lt, node};
    }
}
void Pushup(sptr node){
    if(node == npt)return;
    node->size = node->ls->size + node->rs->size;
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