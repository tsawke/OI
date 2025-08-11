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

class Matrix4{
private:
public:
    ll v[4][4];
    Matrix4 operator *(Matrix4 b){
        Matrix4 ret = Matrix4{{
            {-INF, -INF, -INF, -INF},
            {-INF, -INF, -INF, -INF},
            {-INF, -INF, -INF, -INF},
            {-INF, -INF, -INF, -INF}
        }};
        for(int i = 0; i <= 3; ++i)
            for(int j = 0; j <= 3; ++j)
                for(int k = 0; k <= 3; ++k)
                    ret.v[i][j] = max(ret.v[i][j], this->v[i][k] + b.v[k][j]);
        return ret;
    }
    bool operator ==(Matrix4 b){
        for(int i = 0; i <= 3; ++i)
            for(int j = 0; j <= 3; ++j)
                if(this->v[i][j] != b.v[i][j])return false;
        return true;
    }
    static Matrix4 BuildMatrix4(int val){
        return Matrix4{{
            {0, 0, 0, 0},
            {val, -INF, -INF, -INF},
            {-INF, val, -INF, -INF},
            {-INF, -INF, val, -INF}
        }};
    }
}mat[LIM];

int N, Q;
Matrix4 I = Matrix4{{
    {0, -INF, -INF, -INF},
    {-INF, 0, -INF, -INF},
    {-INF, -INF, 0, -INF},
    {-INF, -INF, -INF, 0}
}};

class SegTree{
private:
    Matrix4 tr[LIM << 2];
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
    void Modify(int idx, Matrix4 v, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = v, void();
        if(idx <= MID)Modify(idx, v, LS, gl, MID);
        else Modify(idx, v, RS, MID + 1, gr);
        Pushup(p);
    }
    Matrix4 Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(r < gl || gr < l)return I;
        if(r <= MID)return Query(l, r, LS, gl, MID);
        if(l >= MID + 1)return Query(l, r, RS, MID + 1, gr);
        return Query(l, r, LS, gl, MID) * Query(l, r, RS, MID + 1, gr);
    }
}st;

int main(){
    int T = read();
    while(T--){
        N = read(), Q = read();
        for(int i = 1; i <= N; ++i)
            mat[i] = Matrix4::BuildMatrix4(read());
        st.Build();
        auto QueryAns = [](void)->ll{
            ll ans(0);
            ll cur(0);
            auto ret = st.Query(2, N);
            for(int i = 0; i <= 3; ++i)
                ans = max(ans, ret.v[i][0]);
            
            ret = st.Query(3, N);
            cur += mat[1].v[1][0];
            for(int i = 0; i <= 2; ++i)
                ans = max(ans, cur + ret.v[i][0]);

            ret = st.Query(4, N);
            cur += mat[2].v[1][0];
            for(int i = 0; i <= 1; ++i)
                ans = max(ans, cur + ret.v[i][0]);
            
            if(N >= 5){
                ret = st.Query(5, N);
                cur += mat[3].v[1][0];
                for(int i = 0; i <= 0; ++i)
                    ans = max(ans, cur + ret.v[i][0]); 
            }
            
            
            // for(int st = 0; st <= 3; ++st){
            //     for(int i = 0; i <= 3 - st; ++i)
            //         ans = max(ans, cur + ret.v[i][0]);
            //     cur += mat[st + 1].v[1][0];
            // }
            return ans;
        };
        printf("%lld\n", QueryAns());
        while(Q--){
            int p = read(), v = read();
            mat[p] = Matrix4::BuildMatrix4(v);
            st.Modify(p, mat[p]);
            printf("%lld\n", QueryAns());
        }
        
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