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

int N;
int F[2000];
int G[2000][2000];
unordered_set < int > s[2000];

int main(){
    int T = read();
    while(T--){
        N = read();
        for(int i = 0; i <= N; ++i)for(int j = 0; j <= N; ++j)G[i][j] = 0;
        for(int i = 0; i <= N; ++i)s[i].clear();
        for(int i = 1; i <= N; ++i)F[i] = read();
        for(int i = 2; i <= N; ++i){
            // G[i][i] = F[i] - 1;
            basic_string < int > toBeDone;
            for(int j = F[i] - 1; j >= 1; --j){
                if(s[i].find(j) != s[i].end())continue;
                bool done(false);
                for(int k = i - 1; k >= 1; --k){
                    if(!G[k][i] && F[k] != j){
                        G[k][i] = j; done = true;
                        break;
                    }
                }
                if(!done){
                    for(int k = i + 1; k <= N; ++k){
                        if(!G[k][i] && F[k] != j){
                            G[k][i] = j; done = true;
                            s[k].insert(j);
                            break;
                        }
                    }
                }
                if(!done && !G[i][i])G[i][i] = j, done = true;

                done = false;
                if(!done){
                    for(int k = i - 1; k >= 1; --k){
                        if(!G[i][k] && F[k] != j){
                            G[i][k] = j; done = true;
                            break;
                        }
                    }
                }
                if(!done){
                    for(int k = i + 1; k <= N; ++k){
                        if(!G[i][k] && F[k] != j){
                            G[i][k] = j; done = true;
                            s[k].insert(j);
                            break;
                        }
                    }
                }
                if(!done && !G[i][i])G[i][i] = j, done = true;
                
            }
        }
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                printf("%d%c", G[i][j], j == N ? '\n' : ' ');
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