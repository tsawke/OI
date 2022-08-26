#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define PI M_PI
#define E M_E
#define npt nullptr

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef long long ll;
typedef unsigned long long unll;

template <typename T = int>
inline T read(void);

int N, M;
// priority_queue < pair< int, int >, vector < pair < int, int > >, greater < pair < int, int > > >a;
vector < pair < int, int > > a;

int main(){
    freopen("dog.in", "r", stdin);
    freopen("dog.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)a.push_back(make_pair(read(), i)); //a.push(make_pair(read(), i));
    sort(a.begin(), a.end());
    while(M--){
        int f = read(), t = read(), k = read();
        int cnt(0);
        for(auto i : a){
            if(f <= i.second && i.second <= t)++cnt;
            if(cnt == k){printf("%d\n", i.first); break;}
        }
    }


    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = 1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

/* Examples:
7 2
1 5 2 6 3 7 4
1 5 3
2 7 1


*/