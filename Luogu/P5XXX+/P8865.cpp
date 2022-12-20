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

#define MOD (ll)(998244353)

template < typename T = int >
inline T read(void);

int N, M, C, F;
bool mp[1100][1100];
int cline[1100][1100];
int srow[1100][1100];
int crow[1100][1100];
int line_x_row[1100][1100];
ll srowF[1100][1100];
ll cntC(0), cntF(0);

int main(){
    int T = read(); (void)read();
    while(T--){
        memset(mp, 0, sizeof mp);
        memset(cline, 0, sizeof cline);
        memset(srow, 0, sizeof srow);
        memset(crow, 0, sizeof crow);
        memset(line_x_row, 0, sizeof line_x_row);
        memset(srowF, 0, sizeof srowF);
        cntC = cntF = 0;
        N = read(), M = read(), C = read(), F = read();
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j){
                char c = getchar();
                while(c != '1' && c != '0')c = getchar();
                mp[i][j] = c - '0';
            }
        for(int i = 1; i <= N; ++i){//i = line, j - row
            deque < int > cur;
            for(int j = 1; j <= M; ++j)
                if(!mp[i][j])cur.emplace_back(j);
                else while(!cur.empty())cline[i][cur.front()] = cur.size() - 1, cur.pop_front();
            while(!cur.empty())cline[i][cur.front()] = cur.size() - 1, cur.pop_front();
        }
        // for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j)printf("%d%c", cline[i][j], j == M ? '\n' : ' ');
        for(int i = 1; i <= M; ++i){//i - row, j - line
            deque < int > cur;
            for(int j = 1; j <= N; ++j)
                if(!mp[j][i])cur.emplace_back(j);
                else while(!cur.empty())crow[i][cur.front()] = cur.size() - 1, cur.pop_front();
            while(!cur.empty())crow[i][cur.front()] = cur.size() - 1, cur.pop_front();
        }
        // for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j)printf("%d%c", crow[j][i], j == M ? '\n' : ' ');
        for(int i = 1; i <= M; ++i)//i - row, j - line
            for(int j = 1; j <= N; ++j)
                srow[i][j] = srow[i][j - 1] + cline[j][i];
        for(int i = 1; i <= M; ++i)
            for(int j = 1; j <= N; ++j)
                line_x_row[i][j] = crow[i][j] * cline[j][i] % MOD;
        for(int i = 1; i <= M; ++i)
            for(int j = 1; j <= N; ++j)
                srowF[i][j] = (srowF[i][j - 1] + line_x_row[i][j]) % MOD;
        for(int i = 1; i <= M; ++i)
            for(int j = 1; j <= N - 2; ++j){
                if(crow[i][j] < 2)continue;
                (cntC += (ll)cline[j][i] * (srow[i][j + crow[i][j]] - srow[i][j + 1]) % MOD) %= MOD;
                if(!crow[i][j + 2])continue;
                (cntF += (ll)cline[j][i] * (srowF[i][j + crow[i][j]] - srowF[i][j + 1]) % MOD) %= MOD;
            }
        printf("%lld %lld\n", cntC * C, cntF * F);
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