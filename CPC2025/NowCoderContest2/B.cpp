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
basic_string < ll > vals;
vector < bitset < 100 > > bvals;

int main(){
    // printf("%d\n", (int)log2(1000000000000000000ll));
    int T = read();
    while(T--){
        vals.clear();
        bvals.clear();
        N = read();
        for(int i = 1; i <= N; ++i)vals += read < ll >();
        sort(vals.begin(), vals.end(), greater < ll >());
        // for(auto v : vals)printf("%lld ", v); printf("\n\n");
        M = (int)log2(*vals.begin());
        for(auto it = vals.begin(); it != vals.end(); ++it){
            bitset < 100 > val;
            for(int i = 0; i <= M; ++i)val[i] = (*it >> i) & 1;
            bvals.emplace_back(val);
        }
        // for(auto v : bvals)cout << v << endl;
        int cur(M), flag(true);
        auto cor(*bvals.begin());
        for(auto it = next(bvals.begin()); it != bvals.end(); ++it){
            auto &val1 = cor, &val2 = *it;
            while(true){
                // printf("cur = %d, v1 = %d, v2 = %d\n", cur, val1[cur] == 1 ? 1 : 0, val2[cur] == 1 ? 1 : 0);
                if(val1[cur] == 1 && val2[cur] == 1){flag = false; break;}
                if(val1[cur] == 0 && val2[cur] == 1){break;}
                if(--cur < 0)break;
            }
            cor |= *it;
            if(!flag)break;
        }printf("%s\n", flag ? "YES" : "NO");
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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