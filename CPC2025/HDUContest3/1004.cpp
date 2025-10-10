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

int A[114514];

int main(){
    int T = read();
    while(T--){
        int ans(0);
        for(int i = 1; i <= 13; ++i)A[i] = read();
        // priority_queue < pair < int, int >, vector < pair < int, int > >, less < pair < int, int > > > cur;
        bool flag0(false);
        for(int i = 1; i <= 13; ++i){
            int left = A[i] % 3;
            A[i] -= left;
            while(left){
                int mxp(114514), mx(3);
                
                bool flag(false);

                for(int j = 1; j <= 13; ++j){
                    if(i == j)continue;
                    if(A[j] >= mx)mx = A[j], mxp = j, flag = true;
                }

                if(!flag){flag0 = true;break;}

                A[mxp] -= 3, --left, ++ans;
            }
            if(flag0)break;
        }

        if(flag0){printf("%d\n", ans); continue;}

        int x = *max_element(A + 1, A + 13 + 1);//, y = accumulate(A + 1, A + 13 +) - x;
        
        int sum(0);

        for(int i = 1; i <= 13; ++i)sum += A[i];
        sum -= x;

        printf("%d\n", ans + (sum <= x / 3 ? sum : (sum + x) / 4));

        // for(int i = 1; i <= 13; ++i)printf("%d%c", A[i], i == 13 ? '\n' : ' ');
        // printf("%d\n", ans);
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