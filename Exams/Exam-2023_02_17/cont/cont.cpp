/*
2
5 1 49
8
2
1
7
9
5 1 64
8
2
1
7
9
*/
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

int N, M; ll K;
ll A[510000];
int ans(0);
// deque < ll > q1, q2;
// basic_string < ll > tmp;

int main(){
    freopen("cont.in", "r", stdin);
    freopen("cont.out", "w", stdout);
    int T = read();
    while(T--){
        // q1.clear(), q2.clear(), tmp.clear();
        ans = 0;
        N = read(), M = read(), K = read < ll >();
        for(int i = 1; i <= N; ++i)A[i] = read();
        int cur(1);
        basic_string < ll > vals;
        while(cur <= N){
            ++ans;
            vals.clear();
            vals += A[cur];
            // tmp += A[cur];
            for(int i = cur + 1; i <= N; ++i){
                vals.insert(lower_bound(vals.begin(), vals.end(), A[i]), A[i]);
                ll sum(0);
                for(int l = 1, r = vals.size(), c = 1; l <= r && c <= M; ++l, --r, ++c)
                    sum += (vals.at(r - 1) - vals.at(l - 1)) * (vals.at(r - 1) - vals.at(l - 1));
                if(sum > K)break;
                cur = i;
            }++cur;
        }printf("%d\n", ans);
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