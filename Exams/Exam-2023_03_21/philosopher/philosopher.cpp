#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cmath>

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

int N;
ll ans[1100];
struct Node{
    int x, y; ld val;
    friend const bool operator < (const Node &a, const Node &b){return a.val < b.val;}
};
basic_string < Node > nods;
int main(){
    freopen("philosopher.in", "r", stdin);
    freopen("philosopher.out", "w", stdout);
    auto CalVal = [](int x, int y)->ld{
        if(x > 0 && y > 0)return atanl(fabs((ld)y / (ld)x));
        if(x < 0 && y > 0)return 1e7 + 9e6 - atanl(fabs((ld)y / (ld)x));
        if(x < 0 && y < 0)return 2e7 + atanl(fabs((ld)y / (ld)x));
        if(x > 0 && y < 0)return 3e7 + 9e6 - atanl(fabs((ld)y / (ld)x));
        return -114514;
    };
    N = read();
    for(int i = 1; i <= 2; ++i){
        int x = read(), y = read(); ld val = CalVal(x, y);
        nods.insert(lower_bound(nods.begin(), nods.end(), Node{x, y, val}), Node{x, y, val});
    }
    for(int i = 3; i <= N; ++i){
        int x = read(), y = read(); ld val = CalVal(x, y);
        ld opv = CalVal(-x, -y);
        for(auto p : nods){
            ld opv2 = CalVal(-p.x, -p.y);
            ld a = opv, b = opv2;
            if(a > b)swap(a, b);
            ld mid = b - a, other = a + (4e7 - b);
            // printf("x = %d, y = %d, a = %.5Lf, b = %.5Lf\n", x, y, a, b);
            if(mid <= other){
                auto itl = upper_bound(nods.begin(), nods.end(), Node{-1, -1, a}), itr = lower_bound(nods.begin(), nods.end(), Node{-1, -1, b});
                ans[i] += distance(itl, itr);
            }else{
                auto itl = lower_bound(nods.begin(), nods.end(), Node{-1, -1, a}), itr = upper_bound(nods.begin(), nods.end(), Node{-1, -1, b});
                ans[i] += distance(nods.begin(), itl) + distance(itr, nods.end());
            }
        }
        nods.insert(lower_bound(nods.begin(), nods.end(), Node{x, y, val}), Node{x, y, val});
    }
    // for(int i = 1; i <= N; ++i)printf("%.5Lf\n", nods.at(i - 1).val);
    for(int i = 1; i <= N; ++i)(ans[i] >>= 1) += ans[i - 1];
    for(int i = 1; i <= N; ++i)printf("%lld\n", ans[i]);
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
5
2 3
3 2
-1 -1
3 3
4 1
*/