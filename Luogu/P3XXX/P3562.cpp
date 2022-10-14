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
segl => line segment
lft => left
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

struct Point{
    int x, y;
    friend ll operator * (const Point &a, const Point &b){
        return (ll)a.x * b.y - (ll)a.y * b.x;
    }
    friend bool operator < (const Point &a, const Point &b){
        return a * b < 0;
    }
    friend bool operator == (const Point &a, const Point &b){
        return a * b == 0;
    }
};
int K, N;
pair < Point, Point > segl[510000];
pair < int, int > seg[510000];
vector < Point > arr;
int cnt[1100000];
int lft[1100000];
int dp[1100000];

int main(){
    K = read(), N = read();
    for(int i = 1; i <= N; ++i){
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        segl[i] = {Point{x1, y1}, Point{x2, y2}};
        arr.push_back(Point{x1, y1}), arr.push_back(Point{x2, y2});
    }
    sort(arr.begin(), arr.end(), [](const Point &a, const Point &b)->bool{return a * b < 0;});
    auto endpos = unique(arr.begin(), arr.end());
    int siz = distance(arr.begin(), endpos);
    for(int i = 1; i <= N; ++i){
        seg[i].first = distance(arr.begin(), lower_bound(arr.begin(), endpos, segl[i].first) + 1);
        seg[i].second = distance(arr.begin(), lower_bound(arr.begin(), endpos, segl[i].second) + 1);
        if(seg[i].first > seg[i].second)swap(seg[i].first, seg[i].second);
    }
    for(int i = 1; i <= siz; ++i)lft[i] = siz;
    for(int i = 1; i <= N; ++i){
        ++cnt[seg[i].first], --cnt[seg[i].second + 1];
        lft[seg[i].second] = min(lft[seg[i].second], seg[i].first);
    }
    for(int i = 1; i <= siz; ++i)cnt[i] += cnt[i - 1];
    for(int i = siz - 1; i >= 1; --i)lft[i] = min(lft[i], lft[i + 1]);
    for(int j = 1; j <= K; ++j){
        for(int i = siz; i >= 1; --i)dp[i] = max(dp[i], dp[lft[i] - 1] + cnt[i]);
        for(int i = 1; i <= siz; ++i)dp[i] = max(dp[i], dp[i - 1]);
    }
    printf("%d\n", dp[siz]);

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