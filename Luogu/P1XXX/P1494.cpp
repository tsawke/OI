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
int sock[51000];
int cnt[51000];
int curA(0), curB(0);
int tot(0);
pair < int, int > ans[51000];
int gl(1), gr(0);

void add(int col){
    curA += cnt[col], curB += tot++ - cnt[col]++;
}
void remove(int col){
    curA -= cnt[col] - 1, curB -= --tot - --cnt[col];
}
struct Query{
    int l, r;
    int idx;
    friend const bool operator < (const Query &a, const Query &b){
        int ablk = a.l / B + 1, bblk = b.l / B + 1;
        if(ablk != bblk)return ablk < bblk;
        return ablk & 1 ? a.r < b.r : a.r > b.r;
    }
};
basic_string < Query > qs;

int main(){
    N = read(), Q = read(); B = sqrt(N);
    for(int i = 1; i <= N; ++i)sock[i] = read();
    for(int i = 1; i <= Q; ++i){int l = read(), r = read(); qs += Query{l, r, i};}
    sort(qs.begin(), qs.end());
    for(auto q : qs){
        while(gl > q.l)add(sock[--gl]);
        while(gr < q.r)add(sock[++gr]);
        while(gl < q.l)remove(sock[gl++]);
        while(gr > q.r)remove(sock[gr--]);
        if(!curA){ans[q.idx] = {0, 1}; continue;}
        int div = __gcd(curA, curA + curB);
        ans[q.idx] = {curA / div, (curA + curB) / div};
        // printf("Querying %d ~ %d : curA = %d, curB = %d, tot = %d\n", q.l, q.r, curA, curB, tot);
    }for(int i = 1; i <= Q; ++i)printf("%d/%d\n", ans[i].first, ans[i].second);
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