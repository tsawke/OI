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

int val[11000][11000];

int main(){
    int T = read();
    while(T--){
        int mxX(0), mxY(0);
        int N = read(), K = read();
        // for(int i = 0; i <= N; ++i)for(int j = 0; j <= N; ++j)val[i][j] = 0;
        memset(val, 0, sizeof val);
        for(int i = 1; i <= N; ++i){
            int x = read(), y = read(), v = read();
            mxX = max(mxX, x), mxY = max(mxY, y);
            val[x][y] += v;
        }
        for(int i = 1; i <= mxX; ++i)
            for(int j = 1; j <= mxY; ++j)
                val[i][j] += val[i - 1][j] + val[i][j - 1] - val[i - 1][j - 1];

        int ans(0);

        for(int sx = 1; sx <= mxX; ++sx){
            for(int sy = 1; sy <= mxY; ++sy){
                for(int w = 1; w <= K; ++w){
                    int h = K / w;
                    // for(int x = sx; x <= sx + )
                    int tx = min(sx + h, mxX), ty = min(sy + w, mxY);
                    ans = max(ans, val[tx][ty] - val[sx - 1][ty] - val[tx][sy - 1] + val[sx - 1][sy - 1]); 
                }
            }
        }

        printf("%d\n", ans);
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