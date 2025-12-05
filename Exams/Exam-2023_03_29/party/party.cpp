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

int N, M;
int B;
int ans(0);
int mxv(0);
struct Guest{int l, r, c;}g[210000];
int mx[510];
int sumB[510];
// int sum[210000];
map < int, int, greater < int > > vals[510];
unordered_set < int > seg[210000];
unordered_set < int > segB[510];

int main(){
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);
    N = read(), M = read();
    mxv = max({mxv, N, M});
    for(int i = 1; i <= N; ++i){
        int l = read(), r = read() - 1, c = read();
        g[i] = Guest{l, r, c};
        mxv = max(mxv, r);
    }B = sqrt(mxv);
    for(int id = 1; id <= N; ++id){
        int l = g[id].l, r = g[id].r, c = g[id].c;
        int LB = l / B, RB = r / B;
        if(LB == RB){
            for(int i = l; i <= r; ++i){
                vals[LB][i] += c; seg[i].insert(id);// += id;
            }
        }else{
            for(int b = LB + 1; b <= RB - 1; ++b)sumB[b] += c, segB[b].insert(id);// += id;
            for(int i = l; i <= (LB + 1) * B; ++i)vals[LB][i] += c, seg[i].insert(id);// += id;
            for(int i = RB * B + 1; i <= r; ++i)vals[RB][i] += c, seg[i].insert(id);// += id;
        }
    }
    for(int m = 1; m <= M && m <= N; ++m){
        int mxv(0), mxp(-1);
        for(int i = 0; i <= mxv / B; ++i){
            if(vals[i].begin()->second + sumB[i] > mxv)tie(mxp, mxv) = *vals[i].begin(), mxv += sumB[i];// mxv = vals[i].begin()->second, mxp = i;
        }if(!~mxp)break;
        ans += mxv;
        for(auto line : seg[mxp]){
            int l = g[line].l, r = g[line].r, c = g[line].c;
            int LB = l / B, RB = r / B;
            if(LB == RB){
                for(int i = l; i <= r; ++i){
                    vals[LB][i] -= c;
                    if(i != mxp)seg[i].erase(line);// += id;
                }
            }else{
                for(int b = LB + 1; b <= RB - 1; ++b){
                    sumB[b] -= c;
                    segB[b].erase(line);// += id;
                }
                for(int i = l; i <= (LB + 1) * B; ++i){
                    vals[LB][i] -= c;
                    if(i != mxp)seg[i].erase(line);// += id;
                }
                for(int i = RB * B + 1; i <= r; ++i){
                    vals[RB][i] -= c;
                    if(i != mxp)seg[i].erase(line);// += id;
                }
            }
        }seg[mxp].clear();
        for(auto line : segB[mxp / B]){
            int l = g[line].l, r = g[line].r, c = g[line].c;
            int LB = l / B, RB = r / B;
            if(LB == RB){
                for(int i = l; i <= r; ++i){
                    vals[LB][i] -= c; seg[i].erase(line);// += id;
                }
            }else{
                for(int b = LB + 1; b <= RB - 1; ++b){
                    sumB[b] -= c;
                    if(b != mxp / B)segB[b].erase(line);// += id;
                }
                for(int i = l; i <= (LB + 1) * B; ++i)vals[LB][i] -= c, seg[i].erase(line);// += id;
                for(int i = RB * B + 1; i <= r; ++i)vals[RB][i] -= c, seg[i].erase(line);// += id;
            }
        }segB[mxp / B].clear();
    }
    printf("%d\n", ans);
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
    }ret *= flag;
    return ret;
}

/*
5 2
2 4 3
1 5 6
4 8 10
7 8 2
10 11 2
*/