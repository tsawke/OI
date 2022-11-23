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

int N, Q;
int B;
int col[1100000];
int cntMdf(0), cntQ(0);
int cnt[1100000];
int cols(0);
int gl(1), gr(0);
int curMdf(0);
int ans[150000];

void Insert(int col){if(++cnt[col] == 1)++cols;}
void Erase(int col){if(!--cnt[col])--cols;}

struct Query{
    int l, r;
    int tim;
    int idx;
    friend const bool operator < (const Query &a, const Query &b){
        int alb = a.l / B, arb = a.r / B, blb = b.l / B, brb = b.r / B;
        if(alb == blb){
            if(arb == brb)return arb & 1 ? a.tim < b.tim : a.tim > b.tim;
            return arb < brb;
        }return alb < blb;
    }
};
basic_string < Query > qs;
struct Modify_t{
    int pos, col;
}mdf[150000];

void Modify(Modify_t &mdf){
    if(gl <= mdf.pos && mdf.pos <= gr){
        if(!--cnt[col[mdf.pos]])--cols;
        if(++cnt[mdf.col] == 1)++cols;
    }swap(col[mdf.pos], mdf.col);
}

int main(){
    N = read(), Q = read(); B = (int)pow((double)N, (double)(2.0 / 3.0));
    for(int i = 1; i <= N; ++i)col[i] = read();
    for(int i = 1; i <= Q; ++i){
        char c = getchar();
        while(c != 'Q' && c != 'R')c = getchar();
        if(c == 'Q'){
            int l = read(), r = read();
            qs += Query{l, r, cntMdf, ++cntQ};
        }else{
            int pos = read(), col = read();
            mdf[++cntMdf] = Modify_t{pos, col};
        }
    }sort(qs.begin(), qs.end());
    for(auto q : qs){
        while(q.l < gl)Insert(col[--gl]);
        while(q.r > gr)Insert(col[++gr]);
        while(q.l > gl)Erase(col[gl++]);
        while(q.r < gr)Erase(col[gr--]);
        while(q.tim > curMdf)Modify(mdf[++curMdf]);
        while(q.tim < curMdf)Modify(mdf[curMdf--]);
        // printf("Answer: %d ~ %d : cols: %d\n", q.l, q.r, cols);
        ans[q.idx] = cols;
    }for(int i = 1; i <= cntQ; ++i)printf("%d\n", ans[i]);
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