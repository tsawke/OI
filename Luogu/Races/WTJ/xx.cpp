#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int N;
bool mp[110][110];
bool vis[110][110];

int dx[10] = {0,  1, 1, -1, -1};
int dy[10] = {0,  1, -1, 1, -1};

int mx[10] = {0,  1, 1, 0, 0};
int my[10] = {0,  1, 0, 1, 0};


ll ans(0);
void bfs(int x, int y){
    int len(1);
    while(true){
        int tx[10], ty[10];
        for(int i = 1; i <= 4; ++i)tx[i] = x + dx[i] * len, ty[i] = y + dy[i] * len;
        /////
        // for(int i = 1; i <= 4; ++i)printf("Dire%d:  x = %d, y = %d\n", i, tx[i], ty[i]);
        /////
        bool flag(false);
        for(int i = 1; i <= 4; ++i){
            if(tx[i] <= 0 || tx[i] > N || ty[i] <= 0 || ty[i] > N){flag = true; break;}
        }
        if(flag)break;
        for(int i = 1; i <= 4; ++i){
            if(!mp[tx[i]][ty[i]]){flag = true; break;}
        }
        if(flag)break;
        ++ans;
        ++len;
    }
}
void bfs2(int x, int y){
    int len(0);
    while(true){
        int tx[10], ty[10];
        for(int i = 1; i <= 4; ++i)tx[i] = x + mx[i] + dx[i] * len, ty[i] = y + my[i] + dy[i] * len;
        bool flag(false);
        for(int i = 1; i <= 4; ++i){
            if(tx[i] <= 0 || tx[i] > N || ty[i] <= 0 || ty[i] > N){flag = true; break;}
        }
        if(flag)break;
        for(int i = 1; i <= 4; ++i){
            if(!mp[tx[i]][ty[i]]){flag = true; break;}
        }
        if(flag)break;
        ++ans;
        ++len;
    }
}



int main(){
    N = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N;++j){
        char c = getchar();
        while(c != '0' && c != '1')c = getchar();
        mp[i][j] = c == '0' ? false : true;
    }
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)bfs(i, j), bfs2(i, j);
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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