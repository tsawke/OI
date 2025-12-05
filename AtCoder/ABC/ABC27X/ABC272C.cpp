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
int mxEven(-1), mx2Even(-1), mxOdd(-1), mx2Odd(-1);

int main(){
    N = read();
    while(N--){
        int val = read();
        if(val & 1){
            if(val > mxOdd)mx2Odd = mxOdd, mxOdd = val;
            else if(val > mx2Odd)mx2Odd = val;
        }else{
            if(val > mxEven)mx2Even = mxEven, mxEven = val;
            else if(val > mx2Even)mx2Even = val;
        }
    }
    if((!~mxEven || !~mx2Even) && (!~mxOdd || !~mx2Odd))printf("-1\n"), exit(0);
    if(!~mxEven || !~mx2Even)printf("%d\n", mxOdd + mx2Odd), exit(0);
    if(!~mxOdd || !~mx2Odd)printf("%d\n", mxEven + mx2Even), exit(0);
    printf("%d\n", max(mxEven + mx2Even, mxOdd + mx2Odd));

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