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

#define LIM (110000)
#define LEFT (false)
#define RIGHT (true)
#define opt(i) (opt.at(i - 1))
#define spl(i) (spl.at(i - 1))

template < typename T = int >
inline T read(void);

int len[LIM]; //max len???

class Square{
private:
public:
    int width, height;
    int lenl, lenr;
    int idxl, idxr;
    int posl, posr;
    Square Rotate(bool dire){//Rotate the hole square.
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
        return *this;
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
    void Print(void){
        printf("Square : %d %d %d %d %d %d %d %d\n", width, height, lenl, lenr, idxl, idxr, posl, posr);
    }
}sq[LIM];

string S;
int N;
int cntL, cntP;
basic_string < bool > opt;
basic_string < int > spl;
int dx[10] = {0,  -1, 0, 1, 0};
int dy[10] = {0,  0, 1, 0, -1};
pair < int, int > pos[LIM];

int main(){
    cin >> S; N = S.length();
    for(auto c : S)c == 'L' ? ++cntL : ++cntP;
    if(cntL - cntP != 4)printf("NIE\n"), exit(0);
    int ccnt(0); bool allP(true);
    for(auto c : S)if(allP && c == 'P')++ccnt; else allP = false, opt += c == 'P';
    for(int i = 1; i <= ccnt; ++i)opt += RIGHT;
    // int d(1); spl += 1;
    // for(int i = 2; i <= (int)opt.size(); ++i){
    //     d += opt(i - 1) ^ opt(i) ? 1 : -1;
    //     if(!d)spl += i;
    //     printf("i = %d, d = %d\n", i, d);
    // }
    int d(0);
    for(int i = 1; i <= (int)opt.size() && (int)spl.size() < 4; ++i){
        if(!d && !opt(i))spl += i;
        else d += opt(i) ? -1 : 1;
        // printf("i = %d,  d = %d\n", i, d);
    }
    auto GenerateSquare = [](int l, int r)->Square{
        printf("generating l = %d, r = %d\n", l, r);
        if(l > r)return Square{0, 1, 0, 0, 0, 0, 0, 0};
        stack < bool > cur;
        sq[0] = Square();
        while(l <= r){
            if(!cur.empty() && opt(l) != cur.top()){
                // auto tp = cur.top();
                cur.pop();
                if(!sq[cur.size() + 1].width)
                    sq[cur.size() + 1] = Square{1, 2, 1, 1, l - 1, l + 1, opt[l] ? 1 : 2, opt[l] ? 2 : 1},
                    len[l] = len[l] ? len[l] : 1;
                    // len[l] = 1;
                else
                    sq[cur.size() + 1].Rotate(opt(l));
                if(!sq[cur.size()].width)sq[cur.size()] = sq[cur.size() + 1];
                else sq[cur.size()].Merge(sq[cur.size() + 1]);
                sq[cur.size() + 1] = Square();
            }else
                cur.push(opt(l)), sq[cur.size()] = Square(); 
            ++l; 
            printf("$$$ size = %d\n", (int)cur.size());
        }
        // printf("Generating l = %d, r = %d:\n", l, r);
        sq[0].Print();
        return sq[0];

    };
    auto InstantiateSquare = [](void)->void{
        pos[1] = {0, 0};
        int cdire(1);
        for(int i = 2; i <= N + 1; ++i){
            pos[i] = {pos[i - 1].first + dx[cdire] * len[i - 1], pos[i - 1].second + dy[cdire] * len[i - 1]};
            printf("# i = %d, (%d, %d)\n", i, pos[i + 1].first, pos[i + 1].second);
            cdire += opt(i - 1); cdire = cdire > 4 ? 1 : (cdire < 1 ? 4 : cdire);
        }
    };
    auto SetLen = [GenerateSquare](int idx, int l, int r)->void{len[idx] = GenerateSquare(l, r).Rotate(LEFT).lenl + LIM;};
    SetLen(spl(1), spl(1) + 1, spl(2) - 1), printf("len %d = %d\n", 1, len[spl(1)]);SetLen(spl(2), spl(2) + 1, spl(3) - 1),
    SetLen(spl(3), spl(3) + 1, spl(4) - 1), SetLen(spl(4), spl(4) + 1, N);
    
    printf("\n\n LEN : \n");
    for(int i = 1; i <= N; ++i)printf("%d ", len[i]);
    printf("\n\n\n");

    InstantiateSquare();
    pos[N + 1].first > 0 ? len[spl(1)] += pos[N + 1].first : len[spl(3)] -= pos[N + 1].first;
    pos[N + 1].second > 0 ? len[spl(2)] += pos[N + 1].second : len[spl(4)] -= pos[N + 1].second;
    InstantiateSquare();
    for(int i = N - ccnt + 1; i <= N; ++i)printf("%d %d\n", pos[i].first, pos[i].second);
    for(int i = 1; i <= N - ccnt; ++i)printf("%d %d\n", pos[i].first, pos[i].second);
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