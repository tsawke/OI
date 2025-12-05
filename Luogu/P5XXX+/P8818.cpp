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

#define UNEXIST(x) (x == INT_MIN || x == INT_MAX || !x)
#define MAXNM (110000 << 1)

template< typename T = int >
inline T read(void);

int N, M, Q;
int A[MAXNM], B[MAXNM];
int posA[MAXNM];
int posB[MAXNM];
int lg[MAXNM << 3];

class CatTreeA{
private:
    int mxNeg[20][MAXNM], mnNeg[20][MAXNM];
    int mxPos[20][MAXNM], mnPos[20][MAXNM];
    bool exist0[20][MAXNM];
    #define MID ((gl + gr) >> 1)
    #define LS (p << 1)
    #define RS (LS | 1)
public:
    void Build(int p = 1, int dep = 1, int gl = 1, int gr = N){
        if(gl == gr)return posA[gl = gr] = p, void();
        mxNeg[dep][MID] = A[MID] < 0 ? A[MID] : INT_MIN,
        mnNeg[dep][MID] = A[MID] < 0 ? A[MID] : INT_MAX;
        mxNeg[dep][MID + 1] = A[MID + 1] < 0 ? A[MID + 1] : INT_MIN,
        mnNeg[dep][MID + 1] = A[MID + 1] < 0 ? A[MID + 1] : INT_MAX;
        mxPos[dep][MID] = A[MID] > 0 ? A[MID] : INT_MIN,
        mnPos[dep][MID] = A[MID] > 0 ? A[MID] : INT_MAX;
        mxPos[dep][MID + 1] = A[MID + 1] > 0 ? A[MID + 1] : INT_MIN,
        mnPos[dep][MID + 1] = A[MID + 1] > 0 ? A[MID + 1] : INT_MAX,
        exist0[dep][MID] = !A[MID], exist0[dep][MID + 1] = !A[MID + 1];
        for(int i = MID - 1; i >= gl; --i)
            mxNeg[dep][i] = max(mxNeg[dep][i + 1], A[i] < 0 ? A[i] : INT_MIN),
            mnNeg[dep][i] = min(mnNeg[dep][i + 1], A[i] < 0 ? A[i] : INT_MAX),
            mxPos[dep][i] = max(mxPos[dep][i + 1], A[i] > 0 ? A[i] : INT_MIN),
            mnPos[dep][i] = min(mnPos[dep][i + 1], A[i] > 0 ? A[i] : INT_MAX),
            exist0[dep][i] = exist0[dep][i + 1] || !A[i];
        for(int i = MID + 2; i <= gr; ++i)
            mxNeg[dep][i] = max(mxNeg[dep][i - 1], A[i] < 0 ? A[i] : INT_MIN),
            mnNeg[dep][i] = min(mnNeg[dep][i - 1], A[i] < 0 ? A[i] : INT_MAX),
            mxPos[dep][i] = max(mxPos[dep][i - 1], A[i] > 0 ? A[i] : INT_MIN),
            mnPos[dep][i] = min(mnPos[dep][i - 1], A[i] > 0 ? A[i] : INT_MAX),
            exist0[dep][i] = exist0[dep][i - 1] || !A[i];
        Build(LS, dep + 1, gl, MID);
        Build(RS, dep + 1, MID + 1, gr);
    }
    tuple < int, int, int, int, bool > Query(int l, int r){
        int dep = lg[posA[l]] - lg[posA[l] ^ posA[r]];
        return {
            max(mxNeg[dep][l], mxNeg[dep][r]),
            min(mnNeg[dep][l], mnNeg[dep][r]),
            max(mxPos[dep][l], mxPos[dep][r]),
            min(mnPos[dep][l], mnPos[dep][r]),
            exist0[dep][l] || exist0[dep][r]
        };
    }
}cta;

class CatTreeB{
private:
    int mxNeg[20][MAXNM], mnNeg[20][MAXNM];
    int mxPos[20][MAXNM], mnPos[20][MAXNM];
    bool exist0[20][MAXNM];
    #define MID ((gl + gr) >> 1)
    #define LS (p << 1)
    #define RS (LS | 1)
public:
    void Build(int p = 1, int dep = 1, int gl = 1, int gr = M){
        if(gl == gr)return posB[gl = gr] = p, void();
        mxNeg[dep][MID] = B[MID] < 0 ? B[MID] : INT_MIN,
        mnNeg[dep][MID] = B[MID] < 0 ? B[MID] : INT_MAX;
        mxNeg[dep][MID + 1] = B[MID + 1] < 0 ? B[MID + 1] : INT_MIN,
        mnNeg[dep][MID + 1] = B[MID + 1] < 0 ? B[MID + 1] : INT_MAX;
        mxPos[dep][MID] = B[MID] > 0 ? B[MID] : INT_MIN,
        mnPos[dep][MID] = B[MID] > 0 ? B[MID] : INT_MAX;
        mxPos[dep][MID + 1] = B[MID + 1] > 0 ? B[MID + 1] : INT_MIN,
        mnPos[dep][MID + 1] = B[MID + 1] > 0 ? B[MID + 1] : INT_MAX,
        exist0[dep][MID] = !B[MID], exist0[dep][MID + 1] = !B[MID + 1];
        for(int i = MID - 1; i >= gl; --i)
            mxNeg[dep][i] = max(mxNeg[dep][i + 1], B[i] < 0 ? B[i] : INT_MIN),
            mnNeg[dep][i] = min(mnNeg[dep][i + 1], B[i] < 0 ? B[i] : INT_MAX),
            mxPos[dep][i] = max(mxPos[dep][i + 1], B[i] > 0 ? B[i] : INT_MIN),
            mnPos[dep][i] = min(mnPos[dep][i + 1], B[i] > 0 ? B[i] : INT_MAX),
            exist0[dep][i] = exist0[dep][i + 1] || !B[i];
        for(int i = MID + 2; i <= gr; ++i)
            mxNeg[dep][i] = max(mxNeg[dep][i - 1], B[i] < 0 ? B[i] : INT_MIN),
            mnNeg[dep][i] = min(mnNeg[dep][i - 1], B[i] < 0 ? B[i] : INT_MAX),
            mxPos[dep][i] = max(mxPos[dep][i - 1], B[i] > 0 ? B[i] : INT_MIN),
            mnPos[dep][i] = min(mnPos[dep][i - 1], B[i] > 0 ? B[i] : INT_MAX),
            exist0[dep][i] = exist0[dep][i - 1] || !B[i];
        Build(LS, dep + 1, gl, MID);
        Build(RS, dep + 1, MID + 1, gr);
    }
    tuple < int, int, int, int, bool > Query(int l, int r){
        int dep = lg[posB[l]] - lg[posB[l] ^ posB[r]];
        return {
            max(mxNeg[dep][l], mxNeg[dep][r]),
            min(mnNeg[dep][l], mnNeg[dep][r]),
            max(mxPos[dep][l], mxPos[dep][r]),
            min(mnPos[dep][l], mnPos[dep][r]),
            exist0[dep][l] || exist0[dep][r]
        };
    }
}ctb;

ll Ask(void){
    int l1 = read(), r1 = read(), l2 = read(), r2 = read();
    int mxNA, mnNA, mxPA, mnPA, mxNB, mnNB, mxPB, mnPB; bool ext0A, ext0B;
    tie(mxNA, mnNA, mxPA, mnPA, ext0A) = cta.Query(l1, r1);
    tie(mxNB, mnNB, mxPB, mnPB, ext0B) = ctb.Query(l2, r2);
    if(UNEXIST(mxNB))
        return UNEXIST(mxPA)
            ? (ext0A ? 0 : (UNEXIST(mxPB) ? 0 : (ll)mxNA * mxPB))
            : (ext0B ? 0 : (UNEXIST(mnPB) ? 0 : (ll)mxPA * mnPB));
    if(UNEXIST(mxPB))
        return UNEXIST(mnNA)
            ? (ext0A ? 0 : (UNEXIST(mnNB) ? 0 : (ll)mnPA * mnNB))
            : (ext0B ? 0 : (UNEXIST(mxNB) ? 0 : (ll)mnNA * mxNB));
    if(ext0A)return 0;
    if(UNEXIST(mnPA))return (ll)mxNA * mxPB;
    if(UNEXIST(mxNA))return (ll)mnPA * mnNB;
    return max((ll)mnPA * mnNB, (ll)mxNA * mxPB);
}

int main(){
    N = read(), M = read(), Q = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= M; ++i)B[i] = read();
    int rn(1), rm(1);
    while(rn < N)rn <<= 1;
    while(rm < M)rm <<= 1;
    N = rn, M = rm;
    lg[0] = lg[1] = 1;
    for(int i = 2; i <= 101000 << 3; ++i)lg[i] = lg[i >> 1] + 1;
    cta.Build(), ctb.Build();
    while(Q--)printf("%lld\n", Ask());
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