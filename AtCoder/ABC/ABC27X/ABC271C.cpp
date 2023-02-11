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
deque < int > book;
// basic_string < int > trash;
int trash;
int cur(0);

int main(){
    N = read();
    basic_string < int > tmp;
    for(int i = 1; i <= N; ++i)tmp += read();
    sort(tmp.begin(), tmp.end());
    auto it_unq = unique(tmp.begin(), tmp.end());
    trash = distance(it_unq, tmp.end());
    tmp.erase(it_unq, tmp.end());
    for(auto v : tmp)book.emplace_back(v);
    while(true){
        // while(!book.empty() && book.front() < cur + 1)trash += book.front(), book.pop_front();
        if(!book.empty() && book.front() == cur + 1)++cur, book.pop_front();
        else if((int)book.size() + trash >= 2){
            ++cur;
            if(trash >= 2)trash -= 2;
            else if(trash == 1)--trash, book.pop_back();
            else book.pop_back(), book.pop_back();
            // if(!trash.empty())trash.pop_back();
            // else book.pop_back();
            // if(!trash.empty())trash.pop_back();
            // else book.pop_back();
        }
        else break;
    }printf("%d\n", cur);

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