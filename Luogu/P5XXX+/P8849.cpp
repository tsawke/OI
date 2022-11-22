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

int N;
int lim;
bool vis[1100];
int a[1100], b[1100], cnt(0);
vector < int > qs;

int main(){
    // int T = read();
    int T;
    cin >> T;
    while(T--){
        // N = read();
        cin >> N;
        lim = 0;
        int oplus(0);
        while((1 << lim) <= N)++lim;
        // printf("lim %d\n", lim);
        for(int i = 0; i < lim; ++i){
            // dfs(i);
            for(int v = 1; v <= N; ++v)
                if(v & (1 << i))qs.emplace_back(v);
            if(qs.empty())continue;
            printf("? %d ", (int)qs.size());
            for(auto v : qs)printf("%d ", v);
            cout << endl;
            qs.clear();
            // int ret = read();
            int ret;
            cin >> ret;
            // oplus <<= 1;
            if(ret == 1)oplus |= (1 << i);
        }
        // printf("%d\n", oplus);
        memset(vis, false, sizeof vis);
        cnt = 0;
        for(int i = 1; i <= N; ++i){
            // if((i ^ oplus) > N)continue;
            if(!vis[i]){
                vis[i] = vis[i ^ oplus] = true;
                a[++cnt] = i, b[cnt] = i ^ oplus;
            }
        }
        int l = 1, r = cnt, ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            printf("? %d ", mid - l + 1);
            for(int i = l; i <= mid; ++i)printf("%d ", a[i]);
            cout << endl;
            // int ret = read();
            int ret;
            cin >> ret;
            if(ret == 0)l = mid + 1;
            else r = mid - 1, ans = a[mid];
        }
        printf("! %d %d\n", ans, ans ^ oplus);
        fflush(stdout);
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