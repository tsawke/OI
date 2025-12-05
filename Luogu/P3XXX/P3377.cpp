#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

struct Heap{
    Heap *ls, *rs;
    int val;
    int dist;
    Heap *fa;
    void* operator new(size_t);
    Heap(int _val, int _dist = 1):val(_val), dist(_dist){;}
    Heap(void) = default;
}hData[110000];
Heap* hnpt = new Heap(0, 0);
void* Heap::operator new(size_t){static Heap* P = hData; ++P; P->ls = P->rs = hnpt; return P;}
Heap* heap[110000];
int N, M;
Heap* Merge(Heap* l, Heap* r){
    if(l == hnpt || r == hnpt)return l != hnpt ? l : r;
    if(l->val > r->val || (l->val == r->val && (l - hData) > (r - hData)))swap(l, r);
    l->rs = Merge(l->rs, r);
    if(l->ls->dist < l->rs->dist)swap(l->ls, l->rs);
    l->dist = l->rs->dist + 1;
    return l;
}
Heap* DelRoot(Heap* x){
    // if(x == hnpt)return npt;
    // if(x->ls == hnpt || x->rs == hnpt)return x->ls == hnpt ? x->rs : x->ls;
    return Merge(x->ls, x->rs);
}
Heap* GetFa(Heap* x){
    if(x->fa == x)return x;
    return x->fa = GetFa(x->fa);
}
// void MergeUni(Heap* x, Heap* y){
//     y->fa = x;
// }
int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)heap[i] = new Heap(read());
    for(int i = 1; i <= N; ++i)heap[i]->fa = heap[i];
    for(int i = 1; i <= M; ++i){
        int opt = read();
        switch(opt){
            case 1:{
                int x = read(), y = read();
                if(!~heap[x]->val || !~heap[y]->val)break;
                auto FaX = GetFa(heap[x]), FaY = GetFa(heap[y]);
                if(FaX == FaY)break;
                FaX->fa = FaY->fa = Merge(FaX, FaY);
                // if(heap[x]->val == -1 || heap[y]->val == -1 || heap[x] == hnpt || heap[y] == hnpt)break;
                // heap[x] = heap[y] = Merge(heap[x], heap[y]);
                break;
            }
            case 2:{
                int x = read();
                if(!~heap[x]->val){printf("-1\n"); break;}
                auto Fa = GetFa(heap[x]);
                printf("%d\n", Fa->val);
                Fa->val = -1;
                Fa->ls->fa = Fa->rs->fa = Fa->fa = DelRoot(Fa);
                // Fa->dist  = 0;
                // Fa->ls = Fa->rs = hnpt;
                // heap[x] = DelRoot(heap[x]);
                // auto tmp2 = DelRoot(heap[x]);
                // heap[x]->val = -1;
                // auto tmp = heap[x];
                // heap[x] = DelRoot(heap[x]);
                // for(int i = 1; i <= N; ++i)if(heap[i] == tmp)heap[i] = heap[x];
                break;
            }
        }
        // for(int j = 1; j <= N; ++j)printf("%d  ", heap[j]->val);
        // printf("\n");
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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