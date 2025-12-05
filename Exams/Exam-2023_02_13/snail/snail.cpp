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

int N, M, Q;

// class SegTree{
// private:
//     int cnt[110000 << 2];
//     int sum[110000 << 2];
//     int lz[110000 << 2];
//     #define LS (p << 1)
//     #define RS (LS | 1)
//     #define MID ((gl + gr) >> 1)
// public:
//     void Pushup(int p){
//         sum[p] = sum[LS] + sum[RS];
//         cnt[p] = cnt[LS] + cnt[RS];
//     }
//     void Pushdown(int p){
//         if(!lz[p])return;

//     }
// }

struct Sline{
    int l, r;
    friend const bool operator < (const Sline &a, const Sline &b){
        return a.l == b.l ? a.r < b.r : a.l < b.l;
    }
}s[110000];

int main(){
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i)s[i].l = read(), s[i].r = read();
    sort(s + 1, s + M + 1);
    Q = read();
    if((ll)M * Q <= (ll)(1e8)){
        while(Q--){
            int l = read(), r = read();
            int curl = l, curr = l;
            for(int i = 1; i <= M; ++i)
                if(curl <= s[i].l && s[i].l <= curr && s[i].r <= r)curr = max(curr, s[i].r);
            printf("%d\n", curr);
        }
    }else{
        bool spLine(true);
        for(int i = 1; i <= M - 1; ++i)
            if(s[i].l < s[i + 1].l && s[i + 1].l < s[i].r){spLine = false; break;}
        if(spLine){
            basic_string < int > ans[110000];
            for(int i = M; i >= 1; --i){
                ans[s[i].l] += s[i].r;
            }
            for(int i = N; i >= 1; --i){
                basic_string < int > tmp = ans[i];
                for(auto v : tmp)ans[i] += ans[v];
            }
            while(Q--){
                int l = read(), r = read();
                int anss(l);
                for(auto v : ans[l])if(v <= r)anss = max(anss, v);
                printf("%d\n", anss);
                // for(int i = 1; i <= M; ++i)
                //     if(curl <= s[i].l && s[i].l <= curr && s[i].r <= r)curr = max(curr, s[i].r);
                // printf("%d\n", curr);
            }
        }
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