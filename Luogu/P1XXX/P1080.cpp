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

int N;
pair < int, int > a[1100];
basic_string < int > ans;

auto Divide(basic_string < int > A, int val){
    basic_string < int > ans;
    ll cur(0);
    for(int i = 1; i <= (int)A.size(); ++i){
        cur *= 10, cur += A.at(i - 1);
        ans += cur / val, cur %= val;
    }
    auto itS = ans.begin();
    while(*itS == 0 && itS != prev(ans.end()))advance(itS, 1);
    A.clear();
    for(auto it = itS; it != ans.end(); ++it)A += *it;
    return A;
}
void Multiply(basic_string < int > &A, int val){
    reverse(A.begin(), A.end());
    ll lst(0);
    for(auto &v : A){
        ll tmp = (ll)v * val + lst;
        v = tmp % 10;
        lst = tmp / 10;
    }
    while(lst)A += lst % 10, lst /= 10;
    reverse(A.begin(), A.end());
}
auto Max(basic_string < int > A, basic_string < int > B){
    if(A.size() > B.size())return A;
    if(A.size() < B.size())return B;
    for(auto i = 1; i <= (int)A.size(); ++i){
        if(A.at(i - 1) > B.at(i - 1))return A;
        if(A.at(i - 1) < B.at(i - 1))return B;
    }return A;
}

int main(){
    N = read();
    int L = read(); (void)read();
    for(int i = 1; i <= N; ++i)a[i].first = read(), a[i].second = read();
    sort(a + 1, a + N + 1, [](const pair < int, int > &a, const pair < int, int > &b)->bool{return a.first * a.second < b.first * b.second;});
    basic_string < int > sum; sum += 1;
    Multiply(sum, L);
    for(int i = 1; i <= N; ++i){
        ans = Max(ans, Divide(sum, a[i].second));
        Multiply(sum, a[i].first);
    }for(auto v : ans)printf("%d", v);
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