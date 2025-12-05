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

template < typename T = int >
inline T read(void);

int N;
ll P, Q, R;
ll a[210000];
ll sum[210000];

int main(){
    N = read(), P = read < ll >(), Q = read < ll >(), R = read < ll >();
    for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + (a[i] = read());
    for(int x = 1; x <= N - 2; ++x){
        int l = x, r = N - 2, ans(-1);
        while(l <= r){
            int mid = (l + r) >> 1;
            if(sum[mid] - sum[x - 1] >= P)ans = mid, r = mid - 1;
            else l = mid + 1;
        }if(!~ans || sum[ans] - sum[x - 1] != P)continue;
        int y = ans + 1;
        // printf("x = %d, y = %d\n", x, y);
        l = y, r = N - 1, ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(sum[mid] - sum[y - 1] >= Q)ans = mid, r = mid - 1;
            else l = mid + 1;
        }if(!~ans || sum[ans] - sum[y - 1] != Q)continue;
        int z = ans + 1;
        // printf("x = %d, y = %d, z = %d\n", x, y, z);
        l = z, r = N, ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(sum[mid] - sum[z - 1] >= R)ans = mid, r = mid - 1;
            else l = mid + 1;
        }if(!~ans || sum[ans] - sum[z - 1] != R)continue;
        // printf("x = %d, y = %d, z = %d, w = %d\n", x, y, z, ans + 1);
        printf("Yes\n"), exit(0);
    }printf("No\n");
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