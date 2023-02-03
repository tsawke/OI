#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

string A, B;

int main(){
    cin >> A >> B;
    if(A.size() < B.size() || (A.size() == B.size() && A < B))printf("-"), swap(A, B);
    reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
    while(B.size() < A.size())B += '0';
    bool minus(0);
    for(int i = 1; i <= (int)A.size(); ++i){
        if(minus){
            if(A.at(i - 1) != '0')--A.at(i - 1), minus = 0;
            else A.at(i - 1) = '9';
        }
        if(A.at(i - 1) < B.at(i - 1))A.at(i - 1) += 10, minus = 1;
        A.at(i - 1) -= (B.at(i - 1) - '0');
    }
    auto stp = prev(A.end());
    while(*stp == '0' && stp != A.begin())advance(stp, -1);
    for(auto it = prev(decltype(A.rend())(stp)); it != A.rend(); ++it)printf("%c", *it);
    printf("\n");
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