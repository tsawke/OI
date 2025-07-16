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

int N, M;

bitset < 6100 > mp[1100];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

bool vis[1100][1100];

bitset < 1100 > suc;
// int belong[i]

int cnt(0);

queue < pair < int, int > > toBeCleared;

void bfs(pair < int, int > s){
    auto [sx, sy] = s;
    queue < pair < int, int > > cur; cur.push(s); toBeCleared.push({sx, sy});
    while(!cur.empty()){
        auto [px, py] = cur.front(); cur.pop();
        
        // printf("In bfs, px = %d, py = %d\n", px, py);
// if(px < 0 || py < 0)printf("Occur.\n"), exit(0);
        mp[cnt][(sx - px + N) * 2 * M + (sy - py + M)] = true;
        for(int i = 1; i <= 4; ++i){
            int tx = px + dx[i], ty = py + dy[i];
            if(1 <= tx && tx <= N && 1 <= ty && ty <= M && !vis[tx][ty]){
                vis[tx][ty] = true;
                toBeCleared.push({tx, ty});
                cur.push({tx, ty});
            }
        }
    }
}


int main(){
    // freopen("./in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T = read();
    while(T--){
        N = read(), M = read();

        ///////////////////////
        cnt = 0;
        for(int i = 0; i <= N + 10; ++i)
            for(int j = 0; j <= M + 10; ++j)
                vis[i][j] = false;
        suc.reset();
        ///////////////////////

        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j){
                char c = getchar();
                while(c != '.' && c != 'O')c = getchar();
                if(c == 'O')vis[i][j] = true;
            }
        // puts("Done I");

        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
                if(!vis[i][j]){
                    // printf("Caling i = %d, j = %d\n", i, j);
                    mp[++cnt].reset(), bfs({i, j});
                    // bfs({i, j});
                    while(!toBeCleared.empty()){
                        auto [px, py] = toBeCleared.front(); toBeCleared.pop();
                        vis[px][py] = false;
                    }
                }

            // puts("Done II");
        
        for(int i = 1; i <= cnt; ++i)suc[i] = true;

        for(int i = 1; i <= cnt; ++i)
                for(int j = 1; j <= cnt; ++j)
                    if(i != j && suc[j] && ((mp[i] | mp[j]) == mp[i]))
                        suc[j] = false;

                // puts("Done III");
        int ans(0);
        for(int i = 1; i <= cnt; ++i)
            if(suc[i])ans += 1;//mp[i].count();
        printf("%d\n", ans);

        // for(int i = 1; i <= cnt; ++i){
        //     printf("block[%d]: ", i);
        //     for(int p = 1; p <= 100; ++p)if(mp[i][p])printf("%d ", p);
        //     printf("\n");
        // }
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