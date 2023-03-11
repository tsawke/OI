#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bitset>

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

#define LIM (2100)

template < typename T = int >
inline T read(void);

int N, Q;
int cnt(0);
struct HashPair{
    auto operator()(const pair < int, int > &p) const{
        return hash < int >{}(p.first) ^ hash < int >{}(p.second);
    }
};
int ass[LIM][LIM], ass_cnt[LIM][LIM];
bitset < LIM << 2 > G[LIM];
unordered_map < pair < int, int >, int, HashPair > idx;
unordered_map < int, pair < int, int > > pos;
int lim2[LIM][LIM];
bitset < LIM > vis[LIM];
int a[LIM], b[LIM], c[LIM], d[LIM], e[LIM];

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= Q; ++i){
        a[i] = read(), c[i] = read(), b[i] = read(), d[i] = read(), e[i] = read();
        if(!e[i])continue;
        auto Add = [](int x, int y)->void{if(x && y && idx.find({x, y}) == idx.end())idx[{x, y}] = ++cnt, pos[cnt] = {x, y};};
        Add(a[i] - 1, b[i] - 1), Add(a[i] - 1, d[i]), Add(c[i], b[i] - 1), Add(c[i], d[i]);
        ass[a[i]][b[i]]++, ass[a[i]][d[i] + 1]--, ass[c[i] + 1][b[i]]--, ass[c[i] + 1][d[i] + 1]++;
    }
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)
        ass[i][j] = ass[i][j] + ass[i - 1][j] + ass[i][j - 1] - ass[i - 1][j - 1];
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)
        ass_cnt[i][j] = bool(ass[i][j]) + ass_cnt[i - 1][j] + ass_cnt[i][j - 1] - ass_cnt[i - 1][j - 1];
    for(int i = 1; i <= Q; ++i)if(e[i]){
        auto Add = [i](int x, int y)->void{if(x && y)G[i][idx[{x, y}]] = 1;};
        Add(a[i] - 1, b[i] - 1), Add(a[i] - 1, d[i]), Add(c[i], b[i] - 1), Add(c[i], d[i]);
        G[i][0] = e[i] == 1 ? 0 : 1;
    }
    auto Gauss = [](void)->void{
        int curl(1);
        for(int i = 1; i <= cnt; ++i){
            int mxp(-1);
            for(int j = curl; j <= Q; ++j)
                if(G[j][i]){mxp = j; break;}
            if(!~mxp)continue;
            swap(G[curl], G[mxp]);
            for(int j = 1; j <= Q; ++j){
                if(curl == j)continue;
                if(G[j][i])G[j] ^= G[curl];
            }++curl;
        }
        for(int i = curl; i <= Q; ++i)if(G[i][0])printf("No\n"), exit(0);
        for(int i = 1; i < curl; ++i)
            for(int j = 1; j <= cnt; ++j)
                if(G[i][j]){lim2[pos[j].first][pos[j].second] = G[i][0]; break;}
    };Gauss();
    auto CntSquare = [](int a, int b, int c, int d)->int{return ass_cnt[c][d] - ass_cnt[a - 1][d] - ass_cnt[c][b - 1] + ass_cnt[a - 1][b - 1];};
    auto TotSquare = [](int a, int b, int c, int d)->int{return (c - a + 1) * (d - b + 1);};
    for(int i = 1; i <= Q; ++i)if(!e[i] && CntSquare(a[i], b[i], c[i], d[i]) == TotSquare(a[i], b[i], c[i], d[i]))printf("No\n"), exit(0);
    for(int i = 0; i <= N; ++i)lim2[0][i] = lim2[i][0] = 0;
    for(int i = N; i >= 1; --i)for(int j = N; j >= 1; --j)lim2[i][j] ^= lim2[i - 1][j] ^ lim2[i][j - 1] ^ lim2[i - 1][j - 1];
    printf("Yes\n");
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)
        printf("%d%c", ass[i][j] ? (lim2[i][j] ? 2 : 1) : 0, j == N ? '\n' : ' ');
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