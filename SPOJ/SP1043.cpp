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

#define MAXN (int)(5e4)
#define INF (0x3f3f3f3f)

template< typename T = int >
inline T read(void);

int N, M;
int lg[MAXN << 3];
int pos[MAXN << 1];
int a[MAXN];

struct Matrix3{
    int val[3][3];
    Matrix3(int v00, int v01, int v02, int v10, int v11, int v12, int v20, int v21, int v22):
        val{
            {v00, v01, v02},
            {v10, v11, v12},
            {v20, v21, v22}
        }{;}
    Matrix3(int val[][3]){for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)this->val[i][j] = val[i][j];}
    Matrix3(void) = default;
    friend const Matrix3 operator * (const Matrix3 &x, const Matrix3 &y){
        int val[3][3];
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)val[i][j] = -INF;
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)for(int p = 0; p <= 2; ++p)
            val[i][j] = max({val[i][j], x.val[i][p] + y.val[p][j], -INF});
        return Matrix3(val);
    }
    void Print(void){
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
            printf("%d%c", val[i][j], j == 2 ? '\n' : ' ');
    }
}mt[MAXN];

class CatTree{
private:
    Matrix3 tr[30][MAXN << 1];
    #define MID ((gl + gr) >> 1)
    #define LS (p << 1)
    #define RS (LS | 1)
public:
    void Build(int p = 1, int dep = 1, int gl = 1, int gr = N){
        // printf("Building l = %d, r = %d, p = %d, dep = %d\n", gl, gr, p, dep);
        if(gl == gr)return pos[gl = gr] = p, void();
        tr[dep][MID] = mt[MID];
        tr[dep][MID + 1] = mt[MID + 1];
        //Tips: Matrix operation does not have the commutative law.
        for(int i = MID - 1; i >= gl; --i)tr[dep][i] = mt[i] * tr[dep][i + 1];
        for(int i = MID + 1 + 1; i <= gr; ++i)tr[dep][i] = tr[dep][i - 1] * mt[i];
        Build(LS, dep + 1, gl, MID);
        Build(RS, dep + 1, MID + 1, gr);
    }
    Matrix3 Query(int l, int r){
        if(l == r)return mt[l = r];
        int dep = lg[pos[l]] - lg[pos[l] ^ pos[r]];
        // tr[dep][l].Print(), tr[dep][r].Print();
        return tr[dep][l] * tr[dep][r];
    }
}ct;

int main(){
    N = read();
    int rN(1); while(rN < N)rN <<= 1;
    for(int i = 1; i <= N; ++i)
        a[i] = read(),
        mt[i] = Matrix3(0, -INF, -INF, a[i], a[i], -INF, a[i], a[i], 0);
    N = rN;
    lg[0] = lg[1] = 1;
    for(int i = 2; i <= (N << 2) + 10; ++i)lg[i] = lg[i >> 1] + 1;
    ct.Build();
    M = read();
    for(int m = 1; m <= M; ++m){
        int l = read(), r = read();
        auto ans = Matrix3(-INF, 0, 0, -INF, -INF, -INF, -INF, -INF, -INF) * ct.Query(l, r);
        printf("%d\n", ans.val[0][0]);
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