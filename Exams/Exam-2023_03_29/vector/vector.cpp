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

int N;
int B;
int tot(0);
int lst(0);
struct Vec{
    int x, y;
    friend const bool operator < (const Vec &a, const Vec &b){
        //y1 / x1 < y2 / x2
        return a.y * b.x < b.y * a.x;
    }
};
Vec vs[310000];
// basic_string < Vec > vs;
// basic_string < Vec > vecs[610];

int main(){
    freopen("vector.in", "r", stdin);
    freopen("vector.out", "w", stdout);
    N = read(), B = sqrt(N);
    while(N--){
        int opt = read();
        if(opt == 1){
            int x = read() ^ lst, y = read() ^ lst; //++tot;
            vs[++tot] = {x, y};
            // vecs[tot / B].insert(lower_bound(vecs[tot / B].begin(), vecs[tot / B].end(), Vec{x, y}), Vec{x, y});
        }else{
            int x = read() ^ lst, y = read() ^ lst, l = read() ^ lst, r = read() ^ lst;
            // static auto Annel = [](int b, int x, int y, int sx, int sy)->int{

            // }
            int ans(0);
            for(int i = l; i <= r; ++i){
                ans = max(ans, vs[i].x * x + vs[i].y * y);
            }lst = ans;
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
    }ret *= flag;
    return ret;
}