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

int N, K, type;
int lst(0);
int Q;
int H[610000];
int pos[610000];
int X, Y;
int ans(-1);

int Check(void){
    int id = pos[X];
    switch(id){
        case 1:{
            if(H[1] < H[2])return 0;
            else{
                if(H[1] < max(H[3], H[4]))return 1;
                return 2;
            }
            break;
        }
        case 2:{
            if(H[1] > H[2])return 0;
            else{
                if(H[2] < max(H[3], H[4]))return 1;
                return 2;
            }
            break;
        }
        case 3:{
            if(H[3] < H[4])return 0;
            else{
                if(H[3] < max(H[1], H[2]))return 1;
                return 2;
            }
            break;
        }
        case 4:{
            if(H[4] < H[3])return 0;
            else{
                if(H[4] < max(H[1], H[2]))return 1;
                return 2;
            }
            break;
        }
        default: break;
    }return -1;
}

void dfs(int dep = 1){
    ans = max(ans, Check());
    if(dep > Y)return;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i != j){
                swap(pos[H[i]], pos[H[j]]), swap(H[i], H[j]);
                dfs(dep + 1);
                swap(pos[H[i]], pos[H[j]]), swap(H[i], H[j]);
            }
        }
    }
}

int main(){
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    N = read(), K = read(), type = read();
    for(int i = 1; i <= N; ++i)pos[H[i] = read()] = i;
    if(K == 1){
        Q = read();
        while(Q--){
            X = read() ^ (lst * type), Y = read() ^ (lst * type);
            ans = X == 2;
            printf("%d\n", ans);
            lst = ans;
        }
    }else if(K == 2){
        Q = read();
        while(Q--){
            ans = 0;
            X = read() ^ (lst * type), Y = read() ^ (lst * type);
            dfs();
            printf("%d\n", ans);
            lst = ans;
        }
    }else printf("%d\n", rndd(0, K));
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

/*
4 2 0
1 4 2 3
2
2 1
1 4

4 2 1
1 4 2 3
2
2 1
0 5
*/

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