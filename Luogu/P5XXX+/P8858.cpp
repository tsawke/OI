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

#define MAXN (510000)

template< typename T = int >
inline T read(void);

int N;
struct Coord{int x, y;}a[MAXN];
int bucx[MAXN], bucy[MAXN];

class SegTree{
private:
    int tr[MAXN << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Clear(int p = 1, int gl = 1, int gr = N + 1){
        if(gl == gr)return tr[p] = 0, void();
        Clear(LS, gl, MID);
        Clear(RS, MID + 1, gr);
        tr[p] = 0;
    }
    void Pushup(int p){tr[p] = tr[LS] + tr[RS];}
    void Modify(int idx, int v = 1, int p = 1, int gl = 1, int gr = N + 1){
        if(gl == gr)return tr[p] += v, void();
        if(idx <= MID)Modify(idx, v, LS, gl, MID);
        else Modify(idx, v, RS, MID + 1, gr);
        Pushup(p);
    }
    bool QueryR(int val, int cur = 0, int p = 1, int gl = 1, int gr = N + 1){
        // printf("Querying %d ~ %d, cur = %d\n", gl, gr, cur);
        if(cur + tr[p] == val)return true;
        if(gl == gr)return false;
        if(cur + tr[LS] >= val)return QueryR(val, cur, LS, gl, MID);
        else return QueryR(val, cur + tr[LS], RS, MID + 1, gr);
    }
    bool QueryL(int val, int cur = 0, int p = 1, int gl = 1, int gr = N + 1){
        // printf("Querying %d ~ %d, cur = %d\n", gl, gr, cur);
        if(cur + tr[p] == val)return true;
        if(gl == gr)return false;
        if(cur + tr[RS] >= val)return QueryL(val, cur, RS, MID + 1, gr);
        else return QueryL(val, cur + tr[RS], LS, gl, MID);
    }
}st;

int main(){
    // freopen("ex_line2.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T = read();
    while(T--){
        bool flag(false);
        memset(bucx, 0, sizeof(int) * (N + 10)), memset(bucy, 0, sizeof(int) * (N + 10));
        N = read();
        for(int i = 1; i <= N; ++i)
            a[i].x = read() + 1, a[i].y = read() + 1, bucx[a[i].x]++, bucy[a[i].y]++;
        a[N + 1].x = a[N + 1].y = 0;
        for(int i = 1; i <= N; ++i){
            bucx[i] += bucx[i - 1], bucy[i] += bucy[i - 1];
            if(bucx[i] == N >> 1 || bucy[i] == N >> 1){printf("2\n"), flag = true; break;}
        }if(flag)continue;
        sort(a + 1, a + N + 1, [](const Coord &a, const Coord &b)->bool{return a.x == b.x ? a.y < b.y : a.x < b.x;});
        st.Clear();
        for(int i = N; i >= 1; --i){
            st.Modify(a[i].y);
            while(a[i - 1].x == a[i].x)st.Modify(a[--i].y);
            if(st.QueryR(N / 2)){printf("3\n"), flag = true; break;}
        }if(flag)continue;
        st.Clear();
        for(int i = 1; i <= N; ++i){
            st.Modify(a[i].y);
            while(a[i + 1].x == a[i].x)st.Modify(a[++i].y);
            if(st.QueryL(N / 2)){printf("3\n"), flag = true; break;}
        }if(flag)continue;
        printf("4\n");
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
4
3 2
3 4
3 3
2 3
*/