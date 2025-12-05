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
int A[50][50];
ll ans(0);
unordered_map < int, int > Scnt[50][50], Tcnt[50][50];

void dfs_S(int x = 1, int y = 1, int cur = A[1][1]){
    if(x > N || y > N || x + y > N + 1)return;
    // printf("S dfs %d %d, cur = %d\n", x, y, cur);
    if(x + y == N + 1)Scnt[x][y][cur]++;
    dfs_S(x + 1, y, cur ^ A[x + 1][y]);
    dfs_S(x, y + 1, cur ^ A[x][y + 1]);
}
void dfs_T(int x = N, int y = N, int cur = A[N][N]){
    if(x < 1 || y < 1 || x + y < N + 1)return;
    // printf("T dfs %d %d, cur = %d\n", x, y, cur);
    if(x + y == N + 1)Tcnt[x][y][cur]++;
    dfs_T(x - 1, y, cur ^ A[x - 1][y]);
    dfs_T(x, y - 1, cur ^ A[x][y - 1]);
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)A[i][j] = read();
    dfs_S(), dfs_T();
    for(int i = 1; i <= N; ++i){
        int X = i, Y = N - i + 1;
        for(auto mp : Scnt[X][Y])ans += (ll)mp.second * Tcnt[X][Y][mp.first ^ A[X][Y]];
    }
    printf("%lld\n", ans);
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