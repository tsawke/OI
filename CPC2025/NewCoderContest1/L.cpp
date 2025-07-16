#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

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

int N, Q;
ll A[210000];
// vector < pair < int, int > > vals;
__gnu_pbds::tree <
    pair < ll, ll >,
    __gnu_pbds::null_type,
    greater < pair < ll, ll > >,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
> vals;

unordered_map < ll, ll > cnt;

int main(){
    int T = read();
    while(T--){
        N = read(), Q = read();
        vals.clear();
        cnt.clear();
        int lim = ((N - 1) >> 1) + ((N - 1) & 1);
        for(int i = 1; i <= N; ++i)A[i] = read < ll >(), vals.insert({A[i], i}), ++cnt[A[i]];
        while(Q--){
            int idx = read(), val = read < ll >();
            --cnt[A[idx]];
            vals.erase(vals.lower_bound({A[idx], idx}));
            vals.insert({A[idx] += val, idx});
            ++cnt[A[idx]];
            ll mid = vals.find_by_order(lim - 1)->first;
            int les = vals.order_of_key(*vals.lower_bound({mid - 1, INT_MAX}));
            // printf("val = %d, mid = %d, les = %d\n", vals.lower_bound({mid - 1, INT_MAX})->first, mid, les);
            printf("%d\n", N - les);
        }
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