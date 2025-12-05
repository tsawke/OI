#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

int N, M, H, W;
int rans[10][10];
#define ColS(x) ((bool)(S & (1 << (x - 1))))
#define S(x, y) (ColS(((x - 1) * siz + y)))
#define idx(x, y) ((x - 1) * 8 + y)
#define f(name, x, y) name[idx(x, y) - 1]
#define val(name, x, y) (x < 1 || x > H || y < 1 || y > W ? 2 : name[idx(x, y) - 1])

basic_string < int > legal;

int main(){
    int Smx = (1 << 9) - 1;
    int siz = 3;
    for(int S = Smx; S; S = (S - 1) & Smx){
        if(
            !(S(1, 1) == S(1, 2) && S(1, 2) == S(1, 3)) &&
            !(S(2, 1) == S(2, 2) && S(2, 2) == S(2, 3)) &&
            !(S(3, 1) == S(3, 2) && S(3, 2) == S(3, 3)) &&
            !(S(1, 1) == S(2, 1) && S(2, 1) == S(3, 1)) &&
            !(S(1, 2) == S(2, 2) && S(2, 2) == S(3, 2)) &&
            !(S(1, 3) == S(2, 3) && S(2, 3) == S(3, 3)) &&
            !(S(1, 1) == S(2, 2) && S(2, 2) == S(3, 3)) &&
            !(S(3, 1) == S(2, 2) && S(2, 2) == S(1, 3))
        )legal += S;
    }
    for(H = 3; H <= 8; ++H){
        for(W = 3; W <= 8; ++W){
            int ans(0);
            for(auto S : legal){
                bitset < 64 > tmp;
                for(int i = 1; i <= 3; ++i)for(int j = 1; j <= 3; ++j)f(tmp, i, j) = S(i, j);
                for(int i = 1; i <= 3; ++i)for(int j = 4; j <= W; ++j)f(tmp, i, j) = f(tmp, i, j - 1) ^ f(tmp, i, j - 2) ^ f(tmp, i, j - 3);
                for(int i = 4; i <= H; ++i)for(int j = 1; j <= W; ++j)f(tmp, i, j) = f(tmp, i - 1, j) ^ f(tmp, i - 2, j) ^ f(tmp, i - 3, j);
                bool flag(true);
                for(int i = 1; i <= H; ++i)for(int j = 1; j <= W; ++j){
                    int cnt[3]; memset(cnt, 0, sizeof cnt);
                    cnt[val(tmp, i, j)]++, cnt[val(tmp, i, j + 1)]++, cnt[val(tmp, i, j + 2)]++, cnt[val(tmp, i, j + 3)]++;
                    if(cnt[0] >= 3 || cnt[1] >= 3)flag = false;
                    memset(cnt, 0, sizeof cnt);
                    cnt[val(tmp, i, j)]++, cnt[val(tmp, i + 1, j)]++, cnt[val(tmp, i + 2, j)]++, cnt[val(tmp, i + 3, j)]++;
                    if(cnt[0] >= 3 || cnt[1] >= 3)flag = false;
                    memset(cnt, 0, sizeof cnt);
                    cnt[val(tmp, i, j)]++, cnt[val(tmp, i + 1, j + 1)]++, cnt[val(tmp, i + 2, j + 2)]++, cnt[val(tmp, i + 3, j + 3)]++;
                    if(cnt[0] >= 3 || cnt[1] >= 3)flag = false;
                    memset(cnt, 0, sizeof cnt);
                    cnt[val(tmp, i, j)]++, cnt[val(tmp, i - 1, j + 1)]++, cnt[val(tmp, i - 2, j + 2)]++, cnt[val(tmp, i - 3, j + 3)]++;
                    if(cnt[0] >= 3 || cnt[1] >= 3)flag = false;
                    if(val(tmp, i, j) == val(tmp, i + 1, j) && val(tmp, i + 1, j) == val(tmp, i + 2, j))flag = false;
                    if(val(tmp, i, j) == val(tmp, i, j + 1) && val(tmp, i, j + 1) == val(tmp, i, j + 2))flag = false;
                    if(val(tmp, i, j) == val(tmp, i + 1, j + 1) && val(tmp, i + 1, j + 1) == val(tmp, i + 2, j + 2))flag = false;
                    if(val(tmp, i, j) == val(tmp, i - 1, j + 1) && val(tmp, i - 1, j + 1) == val(tmp, i - 2, j + 2))flag = false;
                }if(flag)++ans;
            }rans[H][W] = ans;
        }
    }
    for(int H = 1; H <= 2; ++H)for(int W = 1; W <= 2; ++W)rans[H][W] = 1 << (H * W);
    for(int i = 3; i <= 8; ++i)rans[1][i] = rans[i][1] = 6;
    for(int i = 3; i <= 8; ++i)rans[2][i] = rans[i][2] = 36;
    int T = read();
    while(T--){
        int N = read(), M = read();
        N = N > 8 ? 8 : N, M = M > 8 ? 8 : M;
        printf("%d\n", rans[N][M]);
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