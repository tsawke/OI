#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define MAXNQ (210000)

/******************************
abbr
st => Segment Tree
lt => LazyTag
gl/gr => global left/right
ms => Max Section
sec => Section
******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

int ms;
int N, Q;

class SegTree{
    private:
        #define LS (p << 1)
        #define RS ((p << 1) + 1)
        #define MID ((gl + gr) >> 1)
        int st[MAXNQ << 3], lt[MAXNQ << 3];
    public:
        void Pushdown(int p, int gl, int gr){
            if(gl == gr)return (void)(lt[p] = 0);
            st[LS] += lt[p], st[RS] += lt[p];
            lt[LS] += lt[p], lt[RS] += lt[p];
            lt[p] = 0;
        }
        void Modify(int l, int r, int val, int p = 1, int gl = 1, int gr = ms){
            // printf("modifying l=%d, r=%d, v=%d, p=%d, gl=%d, gr=%d\n", l, r, val, p, gl, gr);
            if(l <= gl && gr <= r){st[p] += val, lt[p] += val; return;}
            if(lt[p])Pushdown(p, gl, gr);
            if(l <= MID)Modify(l, r, val, LS, gl, MID);
            if(MID + 1 <= r)Modify(l, r, val, RS, MID + 1, gr);
            st[p] = st[LS] + st[RS];
        }
        bool Query(int l, int r, int p = 1, int gl = 1, int gr = ms){
            // printf("querying l=%d, r=%d p=%d, gl=%d, gr=%d\n", l, r, p, gl, gr);
            if(l <= gl && gr <= r)return st[p];
            if(lt[p])Pushdown(p, gl, gr);
            return ((l <= MID) ? Query(l, r, LS, gl, MID) : false ) | ((MID + 1 <= r) ? Query(l, r, RS, MID + 1, gr) : false); 
        }
}st;

template<typename T = int>
inline T read(void);

pair < int, int > sec[MAXNQ];
vector < int > values;
//1e5 < 2^17
int dp[MAXNQ][30];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int l = read(), r = read();
        sec[i] = make_pair(l, r);
        values.push_back(l), values.push_back(r);
    }
    sort(values.begin(), values.end());
    ms = distance(values.begin(), unique(values.begin(), values.end()));
    for(int i = 1; i <= N; ++i){
        sec[i].first = distance(values.begin(), lower_bound(values.begin(), values.begin() + ms, sec[i].first) + 1);
        sec[i].second = distance(values.begin(), lower_bound(values.begin(), values.begin() + ms, sec[i].second) + 1);
    }
    int cur(1);
    for(int i = 1; i <= N; ++i){
        while(st.Query(sec[i].first, sec[i].second))
            st.Modify(sec[cur].first, sec[cur].second, -1),
            dp[cur - 1][0] = i - 1,
            ++cur;
        st.Modify(sec[i].first, sec[i].second, 1);
    }
    while(cur <= N + 1)dp[cur - 1][0] = N, ++cur;
    for(int j = 1; j <= 17; ++j)
        for(int i = 0; i <= N; ++i)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    Q = read();
    while(Q--){
        int l = read() - 1, r = read();
        int ret(0);
        for(int dis = 17; dis >= 0; --dis){
            if(dp[l][dis] < r){
                ret += 1 << dis;
                l = dp[l][dis];
            }
        }
        printf("%d\n", ret + 1);
    }

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