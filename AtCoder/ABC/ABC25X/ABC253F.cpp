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

int N, M, Q;
int lst[210000], pos[210000];
ll ans[210000];
struct Query{int opt; int a, b, c;}qs[210000];
basic_string < int > del[210000];

class BIT{
private:
    ll tr[210000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v){while(x <= M)tr[x] += v, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
    void ModifyRange(int l, int r, ll v){Modify(l, v), Modify(r + 1, -v);}
}bit;

int main(){
    // freopen("test_05.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), M = read(), Q = read();
    for(int i = 1; i <= Q; ++i){
        int opt = read();
        switch(opt){
            case 1:{
                int l = read(), r = read(), v = read(); qs[i] = Query{opt, l, r, v};
                break;
            }
            case 2:{
                int p = read(), v = read(); qs[i] = Query{opt, p, v};
                pos[p] = i;
                break;
            }
            case 3:{
                int x = read(), y = read(); qs[i] = Query{opt, x, y};
                ans[i] = qs[pos[x]].b;
                del[pos[x]] += i;
                break;
            }
            default: break;
        }
    }
    for(int i = 1; i <= Q; ++i){
        switch(qs[i].opt){
            case 1:{bit.ModifyRange(qs[i].a, qs[i].b, qs[i].c); break;}
            case 2:{for(auto p : del[i])ans[p] -= bit.Query(qs[p].b); break;}
            case 3:{ans[i] += bit.Query(qs[i].b); break;}
            default: break;
        }
    }
    for(int i = 1; i <= Q; ++i)if(qs[i].opt == 3)printf("%lld\n", ans[i]);
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