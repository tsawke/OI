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

int B;
int N, Q;
// struct Query{
//     int l, r;
//     int idx;
//     friend const bool operator < (const Query &a, const Query &b){
//         int BA = a.l / B, BB = b.l / B;
//         return BA != BB ? BA < BB : (BA & 1 ? a.r < b.r : a.r > b.r);
//     };
// }; basic_string < Query > qs;
// basic_string < int > pos[51000];
int A[51000];
int ans[51000];
// int curp[51000];

struct Query{int l, idx;};

basic_string < Query > qs[51000];
queue < int > pos[51000];
queue < int > cid;
int cpos[51000];
int mxp[51000];
queue < int > del;

int main(){
    freopen("sun.in", "r", stdin);
    freopen("sun.out", "w", stdout);
    N = read(), B = sqrt(N);
    for(int i = 1; i <= N; ++i)A[i] = read(); //pos[A[i] = read()] += i;
    Q = read();
    // for(int i = 1; i <= Q; ++i){
    //     int l = read(), r = read();
    //     // qs += {l, r, i};
    //     qs[r] += Query{l, i};
    // }
    for(int i = N; i >= 1; --i){
        if(cpos[A[i]])mxp[i] = cpos[A[i]] - 1;
        else mxp[i] = N;
        cpos[A[i]] = i;
    }

    while(Q--){
        for(int i = 1; i <= N; ++i)while(!pos[i].empty())pos[i].pop();
        int l = read(), R = read();
        int curl(-1);
        int r = l;
        for(; r <= R; ++r){
            if(!~curl)curl = r, pos[A[r]].push(r);
                else{
                    pos[A[r]].push(r);
                    // printf("A[r] = %d, A[curl] = %d\n", A[r], A[curl]);
                    while(curl <= r && (int)pos[A[curl]].size() >= 2)++curl, pos[A[curl]].pop();
                    //curl > r
                }
        }while(R >= curl && (int)pos[A[r]].size() >= 2)--R;
        // printf("curl = %d\n", curl);
        printf("%d\n", R - curl + 1);
    }


    // int curl(-1);
    // for(int r = 1; r <= N; ++r){
       

    //     // if(cid.empty())cid.push(r), curl = 
    //     // else{
    //     //     if()
    //     // }
    // }
    
    
    // sort(qs.begin(), qs.end());
    // int curl(-1), curr(-1);
    // int l = 1, r = 0;
    // auto dis = [=](int p)->int{return min(abs(p - curl), abs(p - curr));};
    // auto add = [&](int p)->void{
    //     if(!~curl || !~curr)return curl = curr = p, curp[A[p]] = p, void();
    //     if(curp[A[p]]){

    //     }
    // }
    // for(auto q : qs){

    // }

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

/*
5
1 3 2 3 4
3
2 4
1 3
2 5
*/