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

#define BLK(x) (x / B + 1)

template < typename T = int >
inline T read(void);

int N, Q;
// int B;
int a[510000];
bool vis[510000];
// bool ans[510000];
// struct Query{
//     int l, r;
//     int idx;
//     friend const bool operator < (const Query &a, const Query &b){
//         int ablk = BLK(a.l), bblk = BLK(b.l);
//         if(ablk != bblk)return ablk < bblk;
//         return ablk & 1 ? a.r < b.r : a.r > b.r;
//     }
// };
// basic_string < Query > qs;
// int gl(1), gr(0);

int main(){
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    N = read(), Q = read(); //B = sqrt(N);
    for(int i = 1; i <= N; ++i)a[i] = read();
    while(Q--){
        int l = read(), r = read();
        memset(vis, false, sizeof vis);
        bool flag(false);
        for(int i = l; i <= r; ++i)
            if(vis[a[i]]){printf("No\n"); flag = true; break;}
            else vis[a[i]] = true;
        if(flag)continue;
        printf("Yes\n");
    }
    // for(int i = 1; i <= Q; ++i){int l = read(), r = read(); qs += Query{l, r, i};}
    // sort(qs.begin(), qs.end());
    // for(auto q : qs){
    //     while(gl > q.l)vis[a[--gl]] ? ans[q.idx] = true : vis[a[gl]] = true;
    //     while(gr < q.r)vis[a[++gr]] ? ans[q.idx] = true : vis[a[gr]] = true;
    //     while(gl < q.l)vis[a[gl++]] = false;
    //     while(gr > q.r)vis[a[gr--]] = false;
    //     // printf("Modifying : ");
    //     // for(int i = 1; i <= N; ++i)printf("%d%c", vis[i] ? 1 : 0, i == N ? '\n' : ' ');
    // }
    // for(int i = 1; i <= Q; ++i)printf("%s\n", ans[i] ? "No" : "Yes");
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
/*
4 2
1 2 3 2
1 3
2 4
*/