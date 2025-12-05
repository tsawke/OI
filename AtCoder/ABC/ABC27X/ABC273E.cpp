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

struct Node{
    Node* pre;
    Node* nxt;
    int val;
    OPNEW;
}nd[2100000];
ROPNEW_NODE;

int Q;
// Node* S[510000];
// Node* T[510000];
Node *S, *T;
unordered_map < int, pair < Node*, Node* > > note;
unordered_map < string, int > hashStr;

int main(){
    T = new Node{npt, npt, -1};
    Q = read();
    hashStr["ADD"] = 1, hashStr["DELETE"] = 2, hashStr["SAVE"] = 3, hashStr["LOAD"] = 4;
    while(Q--){
        string Str; cin >> Str; int opt = hashStr[Str];
        switch(opt){
            case 1:{
                int val = read();

                // if(!S)S = new Node{npt, npt, val}, T = new Node{S, npt, -1}, S->nxt = T;
                // auto np = new Node{T, npt, val};
                // T->
                if(!S)S = T = new Node{npt, npt, val};
                else{
                    auto lstT = T;
                    T = new Node{lstT, npt, val};
                    lstT->nxt = T;
                }
                break;
            }
            case 2:{
                if(T)T = T->pre;
                if(!T)S = npt;
                break;
            }
            case 3:{
                int idx = read();
                note[idx] = {S, T};
                break;
            }
            case 4:{
                int idx = read();
                tie(S, T) = note[idx];
                break;
            }
            default: break;
        }printf("%d ", !T ? -1 : T->val);
    }printf("\n");
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