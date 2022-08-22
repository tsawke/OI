#include <bits/stdc++.h>
using namespace std;

#define LSON(i) (i * 2)
#define RSON(i) (i * 2 + 1)
#define MID(l, r) ((l + r) >> 1)
#define VSIZE(i) (segT[i].r - segT[i].l + 1)
#define lT lazyTag

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);
struct Vertex{
    int val;
    int l, r;
    int lazyTag;
}segT[210000];
int N, M;
void Build(int, int, int);
void Add()




int main(){
    N = read(), M = read();
    Build(1, N, 1);
    for(int i = 1; i <= M; ++i){
        int mode = read();
        switch(mode){
            case 1:{
                int l = read(), r = read(), k = read();
                Add(l, r, 1, k);
                break;
            }
            case 2:{
                int l = read(), r = read();
                printf("%d\n", Query(l, r, 1));
            }
        }
    }

    return 0;
}
int Query(int l, int r, int vert){
    if(l <= segT[vert].l && segT[vert].r <= r){
        return segT[vert].val;
    }
    pushdown(vert);
    return Query(l, r, LSON(vert)) + Query(l, r, RSON(vert));
}
void Add(int l, int r, int vert, int add){
    if(l <= segT[vert].l && segT[vert].r <= r){
        segT[vert].val += add * VSIZE(vertss);
        segT[vert].lT += add;
        return;
    }
    pushdown(vert);
    Add(l, r, LSON(vert), add);
    Add(l, r, RSON(vert), add);
    return;
}
void pushdown(int vert){
    if(segT[vert].l == segT[vert].r){
        segT[vert].lT = 0;
        return;
    }
    if(segT[vert].lT){
        segT[LSON(vert)].lT = segT[RSON(vert)].lT = segT[vert].lT;
        segT[LSON(vert)].val += VSIZE(LSON(vert)) * segT[LSON(vert)].lT;
        segT[RSON(vert)].val += VSIZE(RSON(vert)) * segT[RSON(vert)].lT;
        segT[vert].lT = 0;
    }
    return;
}
void Build(int l, int r, int vert){
    if(l == r){
        segT[vert].val = read();
        segT[vert].l = segT[vert].r = l;
        segT[vert].lT = 0;
        return;
    }
    Build(l, MID(l, r), LSON(vert));
    Build(MID(l, r) + 1, r, RSON(vert));
    segT[vert].val = segT[LSON(vert)].val + segT[RSON(vert)].val;
    segT[vert].l = l, segT[vert].r = r;
    segT[vert].lT = 0;
    return;
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