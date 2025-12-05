#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
inline T read(void);

struct Node{
    int val;
    int idx;
    Node *left;
    Node *right;
};


int main(){
    int N = read();
    vector < pair < int, int > > A(N + 10, {0, 0});
    for(int i = 1; i <= N; ++i)A[i] = {read(), i};
    sort(next(A.begin()), next(A.begin(), N + 1));

    vector < Node* > nd(N + 10, nullptr);
    vector < pair < int, int > > res(N + 10, {INT_MAX, -1});
    vector < int > rnk(N + 10, 0);
    for(int i = 1; i <= N; ++i){
        rnk[A[i].second] = i;
        nd[i] = new Node{
            A[i].first,
            A[i].second,
            i == 1 ? nullptr : nd[i - 1],
            nullptr
        };
        if(i != 1)nd[i - 1]->right = nd[i];
    }
    for(int i = N; i > 1; --i){
        if(nd[rnk[i]]->right){
            int cur = nd[rnk[i]]->right->val - A[rnk[i]].first;
            if(cur < res[i].first)res[i] = {cur, nd[rnk[i]]->right->idx};
        }
        if(nd[rnk[i]]->left){
            int cur = A[rnk[i]].first - nd[rnk[i]]->left->val;
            if(cur <= res[i].first)res[i] = {cur, nd[rnk[i]]->left->idx};
        }
        if(nd[rnk[i]]->left)nd[rnk[i]]->left->right = nd[rnk[i]]->right;
        if(nd[rnk[i]]->right)nd[rnk[i]]->right->left = nd[rnk[i]]->left;
    }
    for(int i = 2; i <= N; ++i)printf("%d %d\n", res[i].first, res[i].second);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
inline T read(void){
    T ret(0);
    short flag(1);
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