#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

#define LIM (210000)
#define INF (0x3f3f3f3f)

class Matrix2{
private:
public:
    int v[2][2];
    Matrix2 operator *(Matrix2 b){
        // return Matrix2{{
        //     {
        //         max({this->v[0][0] + b.v[0][0], this->v[0][1] + b.v[1][0], -INF}),
        //         max({this->v[0][0] + b.v[0][1], this->v[0][1] + b.v[1][1], -INF})
        //     }, {
        //         max({this->v[1][0] + b.v[0][0], this->v[1][1] + b.v[1][0], -INF}),
        //         max({this->v[1][0] + b.v[0][1], this->v[1][1] + b.v[1][1], -INF})
        //     }
        // }};
        Matrix2 ret = Matrix2{{{-INF, -INF}, {-INF, -INF}}};
        for(int i = 0; i <= 1; ++i)
            for(int j = 0; j <= 1; ++j)
                for(int k = 0; k <= 1; ++k)
                    ret.v[i][j] = max(ret.v[i][j], this->v[i][k] + b.v[k][j]);
        return ret;
    }
    bool operator ==(Matrix2 b){
        for(int i = 0; i <= 1; ++i)
            for(int j = 0; j <= 1; ++j)
                if(this->v[i][j] != b.v[i][j])return false;
        return true;
    }
}mat[LIM];

int N, Q;

class SegTree{
private:
    Matrix2 tr[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = tr[LS] * tr[RS];}
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = mat[gl = gr], void();
        Build(LS, gl, MID);
        Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int idx, Matrix2 v, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = v, void();
        if(idx <= MID)Modify(idx, v, LS, gl, MID);
        else Modify(idx, v, RS, MID + 1, gr);
        Pushup(p);
    }
    Matrix2 Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(r < gl || gr < l)return Matrix2{{{0, -INF}, {-INF, 0}}};
        if(r <= MID)return Query(l, r, LS, gl, MID);
        if(l >= MID + 1)return Query(l, r, RS, MID + 1, gr);
        return Query(l, r, LS, gl, MID) * Query(l, r, RS, MID + 1, gr);
    }
}st;

set < int > posR;

int main(){
    Matrix2 lMat = Matrix2{{{1, -INF}, {0, 0}}}, rMat = Matrix2{{{0, -INF}, {-INF, 1}}};
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i){
        char c = getchar(); while(!isupper(c))c = getchar();
        mat[i] = c == 'L' ? lMat : rMat;
        if(c == 'R')posR.insert(i);
    }st.Build();
    while(Q--){
        int x = read();
        if(mat[x] == rMat)posR.erase(x);
        else posR.insert(x); 
        st.Modify(x, mat[x] = mat[x] == lMat ? rMat : lMat);
        if(posR.empty()){
            printf("0\n");
            continue;
        }
        auto res = st.Query(*posR.begin(), N);
        printf("%d\n", max(res.v[0][0], res.v[1][0]));
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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