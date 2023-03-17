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
int A[1100];

int main(){
    // freopen("in.txt", "r", stdin);
    freopen("strvct.in", "r", stdin);
    freopen("strvct.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    while(M--){
        int opt = read();
        if(opt == 1){
            int p = read(), v = read();
            A[p] = v;
        }else{
            int L = read(), R = read(), v = read();
            int ans(0);
            // int mx(-1);
            // for(int l = L; l <= R; ++l){
            //     int mx = -1;
            //     for(int r = l; r <= R; ++r){
            //         mx = max(mx, A[r]);
            //         if(mx <= v)++ans;
            //         else break;
            //     }
            // }printf("%d\n", ans);
            int cur(0);
            for(int i = L; i <= R; ++i){
                if(A[i] <= v)++cur;
                else ans += cur * (cur - 1) / 2 + cur, cur = 0;
                // printf("cur == %d, ans = %d\n", cur, ans);
            }ans += cur * (cur - 1) / 2 + cur;
            printf("%d\n", ans);
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
/*
6 6
1 1 4 5 1 4
1 1 4
2 1 4 2
2 1 1 4
2 1 5 4
1 5 4
2 3 3 3
*/