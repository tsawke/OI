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

int N, Q;
int H, W;
int curx, cury;
unordered_map < int, basic_string < int > > line, row, rline, rrow;


int main(){
    H = read(), W = read(), curx = read(), cury = read();
    N = read();
    for(int i = 1; i <= N; ++i){
        int X = read(), Y = read();
        line[X] += Y, row[Y] += X;
    }
    for(auto &mp : line)sort(mp.second.begin(), mp.second.end(), less < int >());
    for(auto &mp : row)sort(mp.second.begin(), mp.second.end(), less < int >());
    // for(auto &mp : rline)sort(mp.second.begin(), mp.second.end(), greater < int >());
    // for(auto &mp : rrow)sort(mp.second.begin(), mp.second.end(), greater < int >());
    Q = read();
    while(Q--){
        char c = getchar(); while(!isalpha(c))c = getchar();
        int D = read();
        switch(c){
            case 'L':{
                auto it = lower_bound(line[curx].begin(), line[curx].end(), cury);
                if(!line[curx].empty() && it != line[curx].begin())advance(it, -1), cury = max(*it + 1, cury - D);
                else cury = max(1, cury - D);
                break;
            }
            case 'R':{
                auto it = lower_bound(line[curx].begin(), line[curx].end(), cury);
                if(it != line[curx].end())cury = min(*it - 1, cury + D);
                else cury = min(W, cury + D);
                break;
            }
            case 'U':{
                auto it = lower_bound(row[cury].begin(), row[cury].end(), curx);
                if(!row[cury].empty() && it != row[cury].begin())advance(it, -1), curx =  max(*it + 1, curx - D);
                else curx = max(1, curx - D);
                break;
            }
            case 'D':{
                auto it = lower_bound(row[cury].begin(), row[cury].end(), curx);
                if(it != row[cury].end())curx = min(*it - 1, curx + D);
                else curx = min(H, curx + D);
                break;
            }
        }printf("%d %d\n", curx, cury);
    }

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