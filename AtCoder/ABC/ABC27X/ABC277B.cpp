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

int N;
unordered_set < string > ex;

int main(){
    N = read();
    while(N--){
        string S; cin >> S;
        if(S.at(0) != 'S' && S.at(0) != 'H' && S.at(0) != 'D' && S.at(0) != 'C')printf("No\n"), exit(0);
        if(S.at(1) != 'T' && S.at(1) != 'J' && S.at(1) != 'Q' && S.at(1) != 'K' && S.at(1) != 'A' && (S.at(1) == '1' || S.at(1) == '0' || !isdigit(S.at(1))))printf("No\n"), exit(0);
        if(ex.find(S) != ex.end())printf("No\n"), exit(0);
        ex.insert(S);
    }printf("Yes\n");

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