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

int N;
basic_string < int > loop[210];
int belong[210], pos[210];
int cnt(0);
int nxt[210];
bitset < 210 > vis;

int main(){
    while(true){
        for(int i = 0; i <= N; ++i)loop[i].clear();
        cnt = 0; vis.reset();
        N = read();
        if(!N)exit(0);
        for(int i = 1; i <= N; ++i)nxt[i] = read();
        for(int i = 1; i <= N; ++i){
            if(vis[i])continue;
            loop[++cnt] += i, belong[i] = cnt, pos[i] = 0, vis[i] = true;
            int cpos(0);
            int cur = nxt[i];
            while(cur != i)loop[cnt] += cur, belong[cur] = cnt, pos[cur] = ++cpos, vis[cur] = true, cur = nxt[cur];
        }
        while(true){
            int M = read();
            if(!M)break;
            string S;
            getline(cin, S);
            if(S.back() == '\r')S.pop_back();
            while((int)S.length() < N)S += ' ';
            // char c = getchar();
            // while(c != '\n'){if(c != '\r')S += c; c = getchar();}
            // while((int)S.length() < N)S += ' ';
            char ans[210];
            for(int i = 1; i <= N; ++i)
                ans[loop[belong[i]].at((pos[i] + M) % (int)loop[belong[i]].size())] = S.at(i - 1);
            for(int i = 1; i <= N; ++i)printf("%c", ans[i]);
            printf("\n");
            // char ct = getchar(); while(ct != '\n')ct = getchar();
        }printf("\n");
    }
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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