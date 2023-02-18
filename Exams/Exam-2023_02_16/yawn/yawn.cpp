/*
5 4
.XXX
.XXX
.XXX
.XXX
.XXX
3 3
...
.XX
.XX
5 5
..XXX
..XXX
.XXXX
.XXXX
.XXX.
5 5
..XXX
..XXX
XXXXX
XXX..
XXX..
5 5
XXXXX
XXXXX
XXXXX
XXXXX
XXXXX

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

int N, M;
// int ans(INT_MAX);
vector < vector < bool > > mp;
vector < vector < int > > sum;
// vector < vector < bool > > vis;

vector < vector < bool > > mark;
vector < vector < int > > csum;

// void dfs(int sx, int sy){
//     int row(1);
//     int cx(sx), cy(sy);
//     while(mp[cx + 1][sy])++cx;
//     while(mp[sx][cy + 1])++cy;
//     int real_sum = sum[cx][cy] - sum[sx - 1][cy] - sum[cx][sy - 1] + sum[sx - 1][sy - 1];
//     int exp_sum = (cx - sx + 1) * (cy - sy + 1);
//     if(real_sum != exp_sum)
// }
bool Check(int siz){
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            mark[i][j] = false, csum[i][j] = 0;
    for(int i = siz + 1; i <= N - siz; ++i){
        for(int j = siz + 1; j <= M - siz; ++j){
            int sx = i - siz, sy = j - siz, tx = i + siz, ty = j + siz;
            int rsum = sum[tx][ty] - sum[sx - 1][ty] - sum[tx][sy - 1] + sum[sx - 1][sy - 1];
            int esum = ((siz << 1) | 1) * ((siz << 1) | 1);
            if(esum == rsum)mark[i][j] = true;
        }
    }
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            csum[i][j] = csum[i - 1][j] + csum[i][j - 1] - csum[i - 1][j - 1] + mark[i][j];
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j){
            int sx = i - siz, sy = j - siz, tx = i + siz, ty = j + siz;
            if(mp[i][j] && !(csum[tx > N ? N : tx][ty > M ? M : ty] - csum[tx > N ? N : tx][sy - 1 < 0 ? 0 : sy - 1] - csum[sx - 1 < 0 ? 0 : sx - 1][ty > N ? N : ty] + csum[sx - 1 <= 0 ? 0 : sx - 1][sy - 1 < 0 ? 0 : sy - 1]))
                return false;
        }
    return true;
}

int main(){
    freopen("yawn.in", "r", stdin);
    freopen("yawn.out", "w", stdout);
    N = read(), M = read();
    for(int i = 0; i <= N; ++i){
        mark.emplace_back(vector < bool >());
        csum.emplace_back(vector < int >());
        for(int j = 0; j <= M; ++j)
            // mark[i] += false, csum[i] += 0;
            mark[i].emplace_back(false), csum[i].emplace_back(0);
    }
    // mp += vector < bool >();
    mp.emplace_back(vector < bool >());
    // vis += vector < bool >();
    for(int i = 0; i <= M; ++i)mp[0].emplace_back(false);//, vis[0] += false;
    for(int i = 1; i <= N; ++i){
        mp.emplace_back(vector < bool >());//   += vector < bool >();
        // vis += vector < bool >();
        // mp[i] += false;//, vis[i] += false;
        mp[i].emplace_back(false);
        for(int j = 1; j <= M; ++j){
            char c = getchar(); while(c != '.' && c != 'X')c = getchar();
            // mp[i] += c == '.' ? false : true;
            mp[i].emplace_back(c == '.' ? false : true);
            // vis[i] += c == '.' ? false : true;
        }
    }
    // sum += vector < int >();
    sum.emplace_back(vector < int >());
    for(int i = 0; i <= M; ++i)sum[0].emplace_back(0);  //sum[0] += 0;
    for(int i = 1; i <= N; ++i){
        // sum += vector < int >();
        sum.emplace_back(vector < int >());
        // sum[i] += 0;
        sum[i].emplace_back(0);
        for(int j = 1; j <= M; ++j)
            // sum[i] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];
            sum[i].emplace_back(sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j]);
    }
    int l = 1, r = min((N - 1) >> 1, (M - 1) >> 1), ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(Check(mid))ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    if(!~ans){
        printf("0\n");
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
                printf("%c%s", mp[i][j] ? 'X' : '.', j == M ? "\n" : "");
        exit(0);
    }
    int siz = ans;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            mark[i][j] = false;
    for(int i = siz + 1; i <= N - siz; ++i){
        for(int j = siz + 1; j <= M - siz; ++j){
            int sx = i - siz, sy = j - siz, tx = i + siz, ty = j + siz;
            int rsum = sum[tx][ty] - sum[sx - 1][ty] - sum[tx][sy - 1] + sum[sx - 1][sy - 1];
            int esum = ((siz << 1) | 1) * ((siz << 1) | 1);
            if(esum == rsum)mark[i][j] = true;
        }
    }
    printf("%d\n", ans);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            printf("%c%s", mark[i][j] ? 'X' : '.', j == M ? "\n" : "");
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