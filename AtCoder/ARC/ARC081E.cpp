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



template< typename T = int >
inline T read(void);

int N, nxt[210000][30], dp[210000];
int c2d(char c){return c - 'a' + 1;}

int main(){
    memset(dp, 0x3f, sizeof dp);
    string s; cin >> s;
    N = (int)s.size();
    for(int i = N; i >= 1; --i)for(int j = 1; j <= 26; ++j)
        nxt[i][j] = c2d(s.at(i - 1)) == j ? i : nxt[i + 1][j];
    for(int i = N; i >= 1; --i)for(int j = 1; j <= 26; ++j)
        dp[i] = min(dp[i], !nxt[i][j] ? 1 : dp[nxt[i][j] + 1] + 1);
    int siz = dp[1], cur(1);
    while(siz--)for(int i = 1; i <= 26; ++i)
        if(dp[cur] == dp[nxt[cur][i] + 1] + 1)
            {printf("%c", 'a' + i - 1), cur = nxt[cur][i] + 1; break;}
    for(int i = 1; i <= 26; ++i)if(!nxt[cur][i])return printf("%c\n", 'a' + i - 1), 0;
    printf("\n");


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