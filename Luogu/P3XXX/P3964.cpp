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

#define INFLL (0x3f3f3f3f3f3f3f3fll)
// #define Nod(i) (nods.at(i - 1))
#define cx(i) (cx.at(i - 1))
#define cy(i) (cy.at(i - 1))

template < typename T = int >
inline T read(void);

int N;
struct Node{ll x, y;}d[110000];
// basic_string < Node > nods;
basic_string < ll > cx, cy;
ll sx[110000], sy[110000];
ll ans(INFLL);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int x = read(), y = read();
        d[i].x = x + y, d[i].y = x - y;
        // nods += Node{x + y, x - y};
        cx += d[i].x, cy += d[i].y;
    }sort(cx.begin(), cx.end()), sort(cy.begin(), cy.end());
    for(int i = 1; i <= N; ++i)sx[i] = sx[i - 1] + cx(i), sy[i] = sy[i - 1] + cy(i);
    for(int i = 1; i <= N; ++i){
        // ll cur(0);
        ll vx = distance(cx.begin(), lower_bound(cx.begin(), cx.end(), d[i].x)) + 1;
        ll vy = distance(cy.begin(), lower_bound(cy.begin(), cy.end(), d[i].y)) + 1;
        // cur += (sx[N] - sx[i]) - (sx[i]) + cx(i) * (i - (N - i));
        ans = min(ans, (sx[N] - sx[vx]) - (sx[vx]) + cx(vx) * (vx - (N - vx)) + (sy[N] - sy[vy]) - (sy[vy]) + cy(vy) * (vy - (N - vy)));
    }
    // sort(nods.begin(), nods.end(), [](const Node &a, const Node &b)->bool{return a.x < b.x;});
    // for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + Nod(i).x;
    // ll mn(INFLL);
    // for(int i = 1; i <= N; ++i)
    //     mn = min(mn, (sum[N] - sum[i]) - (sum[i]) + Nod(i).x * (i - (N - i)));
    // ans += mn;
    // sort(nods.begin(), nods.end(), [](const Node &a, const Node &b)->bool{return a.y < b.y;});
    // for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + Nod(i).y;
    // mn = INFLL;
    // for(int i = 1; i <= N; ++i)
    //     mn = min(mn, (sum[N] - sum[i]) - (sum[i]) + Nod(i).y * (i - (N - i)));
    // ans += mn;
    printf("%lld\n", ans >> 1);
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