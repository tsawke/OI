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



template < typename T = int >
inline T read(void);

int N, Q;
int idx[910000];
// int siz[310000];
// basic_string < int > box[310000];
int belong[910000];
// int cur;
// int cur_box;

int curBall, curBox;

class UnionFind{
private:
    
public:
    int fa[910000];
    UnionFind(void){for(int i = 1; i <= 901000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

int main(){
    N = read(), Q = read(); curBall = N, curBox = N + Q; // cur = N; //cur_box = N;
    for(int i = 1; i <= 901000; ++i)idx[i] = i, belong[i] = i;//, box[i] += i, siz[i] = 1, belong[i] = i;
    while(Q--){
        int opt = read();
        switch(opt){
            case 1:{
                int x = read(), y = read();
                uf.Union(idx[y], idx[x]);
                idx[y] = ++curBox; belong[curBox] = belong[y];
                // if(siz[idx[y]] > siz[idx[x]])swap(idx[x], idx[y]);
                // for(auto p : box[idx[y]])belong[p] = idx[x];//, printf("p = %d, x = %d\n", p, x);
                // siz[idx[x]] += siz[idx[y]], siz[idx[y]] = 0, box[idx[x]] += box[idx[y]]; box[idx[y]].clear();
                break;
            }
            case 2:{
                int p = read();
                uf.Union(++curBall, idx[p]);
                // box[idx[p]] += ++cur; belong[cur] = idx[p];
                break;
            }
            case 3:{
                int p = read();
                printf("%d\n", belong[uf.Find(p)]);
                break;
            }
        }
            //     for(int i = 1; i <= cur; ++i)printf("%d ", belong[i]);
            // printf("\n");
            // printf("idx : ");
            // for(int i = 1; i <= cur; ++i)printf("%d ", idx[i]);
            // printf("\n");
    }

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