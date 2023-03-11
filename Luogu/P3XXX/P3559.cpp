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

#define LEFT (false)
#define RIGHT (true)
#define opt(i) (opt.at(i - 1))
#define spl(i) (spl.at(i - 1))

template < typename T = int >
inline T read(void);

int len[1100000]; //max len???

class Square{
private:
public:
    int width, height;
    int lenl, lenr;
    int idxl, idxr;
    int posl, posr;
    void Rotate(bool dire){//Rotate the hole square.
        len[idxl] = len[idxl] ? len[idxl] : lenl;
        len[idxr] = len[idxr] ? len[idxr] : lenr;
        *this = Square{
            height,
            width + 2,
            dire == LEFT ? posl : height - posl + 1,
            dire == RIGHT ? posr : height - posr + 1,
            idxl - 1,
            idxr + 1,
            dire == LEFT ? width + 2 : 1,
            dire == RIGHT ? width + 2 : 1
        };
    }
    void Merge(Square S){
        len[idxr] = len[idxr] ? len[idxr] : lenr + S.lenl - 1;///////
        *this = Square{
            width + S.width,
            max(height - posr, S.height - S.posl) + max(posr, S.posl),
            lenl,
            S.lenr,
            idxl,
            S.idxr,
            posl + max(S.posl - posr, 0),
            posr + max(posr - S.posl, 0)
        };
    }
}sq[1100000];

string S;
int cntL, cntP;
basic_string < bool > opt;
basic_string < int > spl;

int main(){
    cin >> S;
    for(auto c : S)c == 'L' ? ++cntL : ++cntP;
    if(cntL - cntP != 4)printf("NIE\n"), exit(0);
    int ccnt(0); bool allP(true);
    for(auto c : S)if(allP && c == 'P')++ccnt; else allP = false, opt += c == 'P';
    while(ccnt--)opt += RIGHT;
    int d(0); spl += 1;
    for(int i = 2; i <= (int)opt.size(); ++i){
        d += opt(i - 1) ^ opt(i) ? 1 : -1;
        if(!d)spl += i;
    }
    struct Node{int idx; bool dire;};
    auto GenerateSquare = [](int l, int r)->Square{
        stack < Node > cur;
        while(l <= r){
            if(!cur.empty() && opt(l) != cur.top().dire){
                auto tp = cur.top(); cur.pop();
                if(cur.empty() || !sq[cur.size() + 1].width)
                    sq[cur.size() + 1] = Square{1, 2, 1, 1, l - 1, l + 1, opt[l] ? 1 : 2, opt[l] ? 2 : 1};
                else
                    sq[cur.size() + 1]
            }else
                cur.push({l, opt(l)}), sq[cur.size()] = Square();
        }
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