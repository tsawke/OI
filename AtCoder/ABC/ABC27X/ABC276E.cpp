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

int H, W;
int Sx, Sy;
map < pair < int, int >, int > mp;
map < pair < int, int >, bool > vis;
int dx[10] = {0,  -1, 0, 1, 0};
int dy[10] = {0,  0, 1, 0, -1};
void dfs(int px = Sx, int py = Sy, int dep = 1){
    if(px == Sx && py == Sy && dep > 3)printf("Yes\n"), exit(0);
    if(px != Sx || py != Sy)vis[{px, py}] = true;
    for(int i = 1; i <= 4; ++i){
        int tx = px + dx[i], ty = py + dy[i];
        if(tx < 1 || tx > H || ty < 1 || ty > W || (tx == Sx && ty == Sy && dep == 2) || vis[{tx, ty}] || !mp[{tx, ty}])continue;
        dfs(tx, ty, dep + 1);
    }
}

int main(){
    H = read(), W = read();
    for(int i = 1; i <= H; ++i)
        for(int j = 1; j <= W; ++j){
            char c = getchar(); while(c != 'S' && c != '.' && c != '#')c = getchar();
            mp[{i, j}] = c == '.' ? 1 : (c == '#' ? 0 : -1);
            if(c == 'S')Sx = i, Sy = j;
        }
    dfs();
    printf("No\n");
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