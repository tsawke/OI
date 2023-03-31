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

int H, W;
// int row1[410000], row2[410000], lne1[410000], lne2[410000];
string row1[410000], row2[410000], lne1[410000], lne2[410000];

int main(){
    H = read(), W = read();
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            char c = getchar(); while(c != '#' && c != '.')c = getchar();
            lne1[i] += c == '#', row1[j] += c == '#';
        }
    }
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            char c = getchar(); while(c != '#' && c != '.')c = getchar();
            lne2[i] += c == '#', row2[j] += c == '#';
        }
    }
    sort(row1 + 1, row1 + W + 1);
    sort(row2 + 1, row2 + W + 1);
    sort(lne1 + 1, lne1 + H + 1);
    sort(lne2 + 1, lne2 + H + 1);
    // for(int i = 1; i <= H; ++i)if(lne1[i] != lne2[i])printf("No\n"), exit(0);
    for(int i = 1; i <= W; ++i)if(row1[i] != row2[i])printf("No\n"), exit(0);
    printf("Yes\n");
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