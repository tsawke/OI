#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

int N, S;
int A[110], B[110];
basic_string < char> dp[110][11000];

int main(){
    N = read(), S = read();
    for(int i = 1; i <= N; ++i)A[i] = read(), B[i] = read();
    dp[1][A[1]] += 'H', dp[1][B[1]] += 'T';
    for(int i = 2; i <= N; ++i)
        for(int j = 0; j <= S; ++j){
            if(j - A[i] >= 0 && (int)dp[i - 1][j - A[i]].size() == i - 1)dp[i][j] = dp[i - 1][j - A[i]] + 'H';
            if(j - B[i] >= 0 && (int)dp[i - 1][j - B[i]].size() == i - 1)dp[i][j] = dp[i - 1][j - B[i]] + 'T';
        }
    if((int)dp[N][S].size() != N)printf("No\n"), exit(0);
    printf("Yes\n");
    for(auto v : dp[N][S])printf("%c", v);
    printf("\n");
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