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
pair < ld, ld > pts[2100];
ld dis[2100][2100];
ld dp[2100][2100][2];
tuple < int, int, int > frm[2100][2100][2];
int top(-1); ld topy(-1e8);

int main(){
    auto CalDis = [](pair < ld, ld > a, pair < ld, ld > b)->ld{
        return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    };
    auto Update = [](int l, int r, int k, int sl, int sr, int sk, int dl, int dr)->void{
        if(dp[sl][sr][sk] >= 1e12)return;
        if(dp[sl][sr][sk] + dis[dl][dr] < dp[l][r][k])
            dp[l][r][k] = dp[sl][sr][sk] + dis[dl][dr], frm[l][r][k] = {sl, sr, sk};
    };

    for(int i = 0; i <= 2010; ++i)for(int j = 0; j <= 2010; ++j)for(int k = 0; k <= 1; ++k)dp[i][j][k] = 1e12;
    N = read();
    for(int i = 1; i <= N; ++i){
        scanf("%Lf%Lf", &pts[i].first, &pts[i].second);
        pts[i + N] = pts[i];
        if(pts[i].second > topy)topy = pts[i].second, top = i;
    }
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)
        dis[i][j] = dis[i + N][j] = dis[i][j + N] = dis[i + N][j + N] = CalDis(pts[i], pts[j]);
    dp[top][top][0] = dp[top][top][1] = dp[top + N][top + N][0] = dp[top + N][top + N][1] = 0.0;
    for(int len = 2; len <= N; ++len)
        for(int l = 1; l <= (N << 1) - len + 1; ++l){
            int r = l + len - 1;
            Update(l, r, 0, l + 1, r, 0, l + 1, l);
            Update(l, r, 0, l + 1, r, 1, r, l);
            Update(l, r, 1, l, r - 1, 0, l, r);
            Update(l, r, 1, l, r - 1, 1, r - 1, r);
        }
    ld ansv(1e12); tuple < int, int, int > curp(0, 0, 0);
    for(int l = 1; l < N; ++l){
        int r = l + N - 1;
        if(dp[l][r][0] < ansv)ansv = dp[l][r][0], curp = {l, r, 0};
        if(dp[l][r][1] < ansv)ansv = dp[l][r][1], curp = {l, r, 1};
    }
    basic_string < int > rans;
    auto [l, r, k] = curp;
    auto lst = curp; curp = frm[l][r][k];
    while(get < 0 >(curp)){
        auto [l, r, k] = lst;
        auto [cl, cr, ck] = curp;
        if(l != cl)rans += l;
        else rans += r;
        lst = curp;
        curp = frm[cl][cr][ck];
    }rans += get < 0 >(lst);
    for_each(rans.rbegin(), rans.rend(), [rans](auto val)->void{printf("%d%c", val > N ? val - N : val, val == *prev(rans.rend()) ? '\n' : ' ');});
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