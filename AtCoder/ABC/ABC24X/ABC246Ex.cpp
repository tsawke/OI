#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MAXN (int)(1e5 + 100)
#define MOD (int)(998244353)

template< typename T = int >
inline T read(void);

int N, Q;
int S[MAXN];

struct Matrix3{
    int val[3][3];
    Matrix3(int v00, int v01, int v02, int v10, int v11, int v12, int v20, int v21, int v22):
        val{
            {v00, v01, v02},
            {v10, v11, v12},
            {v20, v21, v22}
        }{;}
    Matrix3(int S):
        val{
            {1, S != 0, 0},
            {S != 1, 1, 0},
            {S != 1, S != 0, 1}
        }{;}
    Matrix3(int val[][3]){for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)this->val[i][j] = val[i][j];}
    Matrix3(void) = default;
    friend const Matrix3 operator * (const Matrix3 &x, const Matrix3 &y){
        int val[3][3]; memset(val, 0, sizeof val);
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)for(int p = 0; p <= 2; ++p)
            val[i][j] = ((ll)val[i][j] + (ll)x.val[i][p] * y.val[p][j] % MOD) % MOD;
        return Matrix3(val);
    }
    void Print(void){
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
            printf("%d%c", val[i][j], j == 2 ? '\n' : ' ');
    }
}mt[MAXN];

class SegTree{
private:
    Matrix3 tr[MAXN << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = tr[LS] * tr[RS];}
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = mt[gl = gr], void();
        Build(LS, gl, MID);
        Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int idx, Matrix3 v, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = v, void();
        if(idx <= MID)Modify(idx, v, LS, gl, MID);
        else Modify(idx, v, RS, MID + 1, gr);
        Pushup(p);
    }
    Matrix3 Query(void){return tr[1];}
}st;

int main(){
    N = read(), Q = read();
    string s; cin >> s;
    for(int i = 1; i <= (int)s.size(); ++i)
        S[i] = s.at(i - 1) == '?' ? -1 : int(s.at(i - 1) - '0'),
        mt[i] = Matrix3(S[i]);
    st.Build();
    Matrix3 origin(0, 0, 1, 0, 0, 0, 0, 0, 0);
    while(Q--){
        int p = read();
        char c = getchar(); while(c != '0' && c != '1' && c != '?')c = getchar();
        int flag = c == '?' ? -1 : int(c - '0');
        st.Modify(p, Matrix3(flag));
        auto ans = origin * st.Query();
        printf("%d\n", (int)((ll)(ans.val[0][0] + ans.val[0][1]) % MOD));
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
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