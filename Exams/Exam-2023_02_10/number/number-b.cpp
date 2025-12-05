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

ll F(ll x){
    if(x == 1)return 1;
    ll ret(0);
    for(ll i = 1; i * i <= x; ++i)
        if(!(x % i) && __gcd(i, x / i) == 1)ret += i + x / i;
    return ret;
    // printf("f(%lld) = %lld%s", x, ret, x % 10 == 0 ? "\n" : "; ");
}
map < ll, ll > cnt;
map < char, int > mp;
map < int, char > rmp;
map < ll, ll > unex;

int main(){
    freopen("out.txt", "w", stdout);
    fprintf(stderr, "Begin to build map...\n");
    mp['#'] = 0, rmp[0] = '#';
    printf("mp['#']=0;");
    for(int i = 1; i <= 26; ++i){
        mp['a' + i - 1] = i, rmp[i] = 'a' + i - 1,
        printf("mp['%c']=%d;", char('a' + i - 1), i);
    }printf("\n");
    for(int i = 1; i <= 26; ++i){
        mp['A' + i - 1] = i + 26, rmp[i + 26] = 'A' + i - 1,
        printf("mp['%c']=%d;", char('A' + i - 1), i + 26);
    }printf("\n\n\n");
    fprintf(stderr, "Begin to cal f(x)...\n");
    for(int i = 1; i <= 11000000; ++i)cnt[F(i)]++;
    fprintf(stderr, "Complete.\n");
    // printf("string ans = \"#");
    string ans; ans += '#';
    for(int i = 1; i <= 100000; ++i){
        if(rmp.find(cnt[i]) == rmp.end())unex[i] = cnt[i], ans += '*';//printf("#");
        else ans += rmp[cnt[i]];//printf("%c", rmp[cnt[i]]);
    }
    // printf("\";\n\n");
    {
        printf("string ans = \"");
        char lst('@'); int cnt(0);
        for(auto it = ans.begin(); it != ans.end(); ++it){
            if(lst == '@' || *it == lst){
                if(cnt == 9)printf("%d%c", cnt, lst), cnt = 0;
                lst = *it, ++cnt;
            }else{
                if(cnt == 1)printf("%c", lst);
                else printf("%d%c", cnt, lst);
                lst = *it, cnt = 1;
            }
        }if(cnt != 1)printf("%d%c", cnt, lst);
        else printf("%c", lst);
        printf("\";\n\n");
    }
    //begin at 9940000
    string bans;
    // printf("string bans = \"");
    for(int i = 9940000; i <= 10000000; ++i){
        if(rmp.find(cnt[i]) == rmp.end())unex[i] = cnt[i], bans += '*';
        // fprintf(stderr, "Find unexist ans ans[%d] = %lld\n", i, cnt[i]), bans += '*';//, printf("#");
        else bans += rmp[cnt[i]];//printf("%c", rmp[cnt[i]]);
    }

    {
        printf("string bans = \"");
        char lst('@'); int cnt(0);
        for(auto it = bans.begin(); it != bans.end(); ++it){
            if(lst == '@' || *it == lst){
                if(cnt == 9)printf("%d%c", cnt, lst), cnt = 0;
                lst = *it, ++cnt;
            }else{
                if(cnt == 1)printf("%c", lst);
                else printf("%d%c", cnt, lst);
                lst = *it, cnt = 1;
            }
        }if(cnt != 1)printf("%d%c", cnt, lst);
        else printf("%c", lst);
        printf("\";\n\n");
    }
    // }printf("\";\n\n");

    // for(auto mp : cnt){printf("Ans[ %lld ] = %lld\n", mp.first, mp.second);}

    for(auto mp : unex){
        printf("u[%lld]=%lld;", mp.first, mp.second);
    }printf("\n\n");

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