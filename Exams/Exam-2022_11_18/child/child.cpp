#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MAXN (110000)

template< typename T = int >
inline T read(void);

int N, M;
bitset < 11000 > vis[11000];
bool laugh[11000];

// class SegTree{
// private:
//     unordered_map < int, int > tr[MAXN << 2];
//     int v[MAXN << 2];
//     basic_string < int > lz[MAXN << 2];
//     #define LS (p << 1)
//     #define RS (LS | 1)
//     #define MID ((gl + gr) >> 1)
// public:
//     void Pushup(int p){
//         for(auto son : tr[LS])tr[p][son.first] += son.second;
//         for(auto son : tr[RS])tr[p][son.first] += son.second;
//         v[p] = v[LS] + v[RS];
//     }
//     void Pushdown(int p){
//         lz[LS] += lz[p], lz[RS] += lz[p];
//         for(auto modf : lz[p]){
//             v[LS] -= tr[LS][modf], tr[LS][modf] = 0;

//         }
//     }
// }

int main(){
    freopen("child.in", "r", stdin);
    freopen("child.out", "w", stdout);
    N = read(), M = read();
    while(M--){
        int opt = read();
        if(opt == 1){
            int x = read(), idx = read(), dis = read();
            for(int i = max(1, x - dis); i <= min(N, x + dis); ++i){
                if(!vis[i][idx])vis[i][idx] = true, laugh[i] = true;
                else laugh[i] = false;
            }
        }else{
            int l = read(), r = read();
            int cnt(0);
            for(int i = l; i <= r; ++i)if(laugh[i])++cnt;
            printf("%d\n", cnt);
        }
    }
    // if(N <= 20000){
    //     while(M--){
    //         int opt = read();
    //         if(opt == 1){
    //             int x = read(), idx = read(), dis = read();
    //             for(int i = max(1, x - dis); i <= min(N, x + dis); ++i){
    //                 if(!vis[i][idx])vis[i][idx] = true, laugh[i] = true;
    //                 else laugh[i] = false;
    //             }
    //         }else{
    //             int l = read(), r = read();
    //             int cnt(0);
    //             for(int i = l; i <= r; ++i)if(laugh[i])++cnt;
    //             printf("%d\n", cnt);
    //         }
    //     }
    // }else{
    //     printf("qwq\n");
    //     exit(0);
    // }
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
10 14
1 3 11 0
2 3 3
1 3 11 2
2 1 5
1 5 12 1
2 4 6
1 8 13 2
2 6 10
1 7 11 2
2 5 9
1 10 12 1
2 9 10
1 9 12 0
2 1 10
*/