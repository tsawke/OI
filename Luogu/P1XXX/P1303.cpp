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

#define V(index, p) (index.at(p - 1))

template < typename T = int >
inline T read(void);

string sA, sB;
basic_string < int > A, B, ans;

int main(){
    cin >> sA >> sB;
    reverse(sA.begin(), sA.end()), reverse(sB.begin(), sB.end());
    for(auto c : sA)A += c - '0';
    for(auto c : sB)B += c - '0';
    int lenA = A.size(), lenB = B.size(), len = lenA + lenB;
    for(int i = 1; i <= len + 1; ++i)ans += 0;
    for(int i = 1; i <= lenA; ++i)
        for(int j = 1; j <= lenB; ++j)
            V(ans, i + j - 1) += V(A, i) * V(B, j);
    for(int i = 1; i <= len; ++i)V(ans, i + 1) += V(ans, i) / 10, V(ans, i) %= 10;
    while(V(ans, len) == 0 && len > 1)--len;
    for(int i = len; i >= 1; --i)printf("%d", V(ans, i));
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