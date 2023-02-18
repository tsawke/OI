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
basic_string < int > squ;
unordered_set < int > exists;
bitset < 410 > vis[410];
int ans[410][410];
struct Dire{
    int x, y; int step;
    friend Dire operator + (const Dire &a, const Dire &b){
        return Dire{a.x + b.x, a.y + b.y, a.step + b.step};
    }
};
basic_string < Dire > mov;

void BFS(void){
    queue < Dire > cur;
    cur.push(Dire{1, 1, 0}); vis[1][1] = true; ans[1][1] = 0;
    while(!cur.empty()){
        auto p = cur.front(); cur.pop();
        for(auto d : mov){
            auto tp = p + d;
            if(tp.x < 1 || tp.x > N || tp.y < 1 || tp.y > N || vis[tp.x][tp.y])continue;
            cur.push(tp), vis[tp.x][tp.y] = true, ans[tp.x][tp.y] = tp.step;
        }
    }
}

int main(){
    memset(ans, -1, sizeof ans);
    N = read(), M = read();
    squ += 0, exists.insert(0);
    for(int i = 1; i * i <= M; ++i)squ += i * i, exists.insert(i * i);
    for(auto v : squ)if(exists.find(M - v) != exists.end())
        mov += {
            {(int)sqrt(v), (int)sqrt(M - v), 1},
            {-(int)sqrt(v), (int)sqrt(M - v), 1},
            {(int)sqrt(v), -(int)sqrt(M - v), 1},
            {-(int)sqrt(v), -(int)sqrt(M - v), 1}
        };
    BFS();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            printf("%d%c", ans[i][j], j == N ? '\n' : ' ');
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