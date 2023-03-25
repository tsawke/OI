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

int N, M; ld P;
// bitset < 5 > vis[5];
// double ans(0.0);
// int dx[10] = {0,  -1, 0, 1, 0};
// int dy[10] = {0,  0, 1, 0, -1};

int ansp[20][30] = {{},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,2,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,3,12,17,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,4,24,61,76,40,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,3,12,17,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,6,48,166,312,334,192,64,12,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,10,120,661,2179,4718,6929,6897,4568,2065,643,134,17,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,4,24,61,76,40,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,10,120,661,2179,4718,6929,6897,4568,2065,643,134,17,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,20,360,3066,16332,60670,165956,344033,547944,672928,635632,460680,258144,112742,38392,10071,1976,274,24,1,0,0,0,0,0}
};

int edg[20] = {0,  0, 1, 2, 3, 1, 4, 7, 10, 2, 7, 12, 17, 3, 10, 17, 24};

ld powP[30], pow0P[30];
ld ans(0.0);

int main(){
    freopen("socialman.in", "r", stdin);
    freopen("socialman.out", "w", stdout);
    int T = read();
    // auto dfs = [](auto&& self, int px = 1, int py = 1, double p = 1.0)->void{
    //     if(px == N && py == M)return ans += p, printf("add ans p is %.6lf\n", p), void();
    //     for(int i = 1; i <= 4; ++i){
    //         int tx = px + dx[i], ty = py + dy[i];
    //         if(tx < 1 || tx > N || ty < 1 || ty > M || vis[tx][ty])continue;
    //         vis[tx][ty] = true;
    //         self(self, tx, ty, p * (1.0 - P));
    //         vis[tx][ty] = false;
    //     }
    // };
    while(T--){
        ans = 0.0;
        N = read(), M = read(); scanf("%Lf", &P);
        powP[0] = pow0P[0] = 1.0;
        for(int i = 1; i <= 29; ++i)powP[i] = powP[i - 1] * P, pow0P[i] = pow0P[i - 1] * (1.0 - P);
        int idx = (N - 1) * 4 + M;
        int cntE = edg[idx];
        for(int i = 0; i <= cntE; ++i)ans += pow0P[i] * powP[cntE - i] * ansp[idx][i];
        printf("%.8Lf\n", ans);
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
3
2 2 0.5
3 2 0.7
1 1 0.2
*/

/*


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

#define d(x, y) ((x - 1) * M + y)

template < typename T = int >
inline T read(void);

int p[30];
int dx[10] = {0,  -1, 0, 1, 0};
int dy[10] = {0,  0, 1, 0, -1};
int N, M;

class UnionFind{
private:
    int fa[20];
    stack < pair < int, int > > opt;
public:
    UnionFind(void){for(int i = 1; i <= 19; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : Find(fa[x]);}
    void Union(int s, int t){
        int fs = Find(s), ft = Find(t);
        opt.push({fs, fa[fs]});
        fa[fs] = ft;
    }
    void Repeal(void){
        if(!opt.empty())fa[opt.top().first] = opt.top().second, opt.pop();
    }
    void Clear(void){for(int i = 1; i <= 19; ++i)fa[i] = i; while(!opt.empty())opt.pop();}
}uf;

struct edge{int s, t;};
basic_string < edge > edgs;

int e[20];
int cnt(0);

int main(){
    freopen("out.txt", "w", stdout);
    auto dfs = [](auto&& self, int dep = 1, int cnt = 0){
        if(dep > (int)edgs.size()){
            if(uf.Find(d(1, 1)) == uf.Find(d(N, M)))++p[cnt];
            return;
        }
        self(self, dep + 1, cnt);
        uf.Union(edgs.at(dep - 1).s, edgs.at(dep - 1).t);
        self(self, dep + 1, cnt + 1);
        uf.Repeal();
    };
    printf("ansp[20][30] = {{}, \n");
    for(N = 1; N <= 4; ++N){
        for(M = 1; M <= 4; ++M){
            printf("{");
            memset(p, 0, sizeof p);
            uf.Clear(); edgs.clear();
            for(int i = 1; i <= N; ++i){
                for(int j = 1; j <= M; ++j){
                    int tx = i + 1, ty = j;
                    if(!(tx < 1 || tx > N || ty < 1 || ty > M))edgs += edge{d(i, j), d(tx, ty)};
                    tx = i, ty = j + 1;
                    if(!(tx < 1 || tx > N || ty < 1 || ty > M))edgs += edge{d(i, j), d(tx, ty)};
                }
            }e[++cnt] = edgs.size();
            dfs(dfs);
            for(int i = 0; i <= 29; ++i)printf("%d%c", p[i], i == 29 ? '}' : ',');
            printf(",\n");
        }
    }printf("};\n");

    printf("int edg[20] = {0,  ");
    for(int i = 1; i <= 16; ++i)printf("%d, ", e[i]);
    printf("}\n");
    // int T = read();
    // auto dfs = [](auto&& self, int p = 1){

    // }
    // while(T--){
    //     int N = read(), M = read();

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

*/