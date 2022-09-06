#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

#define MAXN 510000
#define MAXQ 510000
#define MAXNQ 1100000


/******************************
abbr
ord -> order
buc -> bucket
dbuc -> deleted bucket
******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

__gnu_pbds::priority_queue < pair < int, int >/*cnt, idx*/, less < pair < int, int> >, pairing_heap_tag > buc[MAXNQ];
// __gnu_pbds::priority_queue < pair < int, int >/*cnt, idx*/, less < pair < int, int> >, pairing_heap_tag > tbuc[];
// __gnu_pbds::priority_queue < pair < int, int >/*cnt, idx*/, less < pair < int, int> >, pairing_heap_tag > dbuc[MAXN];
vector < int > ord[MAXNQ];


template<typename T = int>
inline T read(void);


int N, Q;

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i){
        int len = read();
        int tbuc[MAXNQ];
        memset(tbuc, 0, sizeof(tbuc));
        int maxp(0);
        for(int j = 1; j <= len; j++){
            int t = read();
            ord[i].push_back(t);
            tbuc[t]++;
            maxp = max(maxp, t);
        }
        for(int j = 0; j <= maxp; ++j){
            if(tbuc[j])buc[i].push(make_pair(tbuc[j], j));
        }
    }
    while(Q--){
        int ask = read();
        switch(ask){
            case 1:{
                int x = read(), y = read();
                bool exist(false);
                for(auto itea = buc[x].begin(); itea != buc[x].end(); ++itea){
                    if(itea->second == y){
                        exist = true;
                        buc[x].modify(itea, make_pair(itea->first + 1, itea->second));
                        break;
                    }
                }
                if(!exist){
                    buc[x].push(make_pair(1, y));
                }
                ord[x].push_back(y);
                break;
            }
            case 2:{
                // printf("In case2:\n");
                int x = read();
                // printf("siz:%d\n", ord[x].size());
                // printf("%d\n", ord[x].back());
                int back = ord[x].back();
                ord[x].pop_back();
                for(auto itea = buc[x].begin(); itea != buc[x].end(); ++itea){
                    printf("Deleting fir = %d, sec = %d\n", itea->first, itea->second);
                    if(itea->second == back){
                        buc[x].erase(itea);
                        break;
                    }
                }
                break;
            }
            case 3:{
                int M = read();
                int tbuc[MAXNQ];
                memset(tbuc, 0, sizeof(tbuc));
                pair < int, int > maxx = make_pair(0, 0);
                int siz(0);
                for(int i = 1; i <= M; ++i){
                    int tmp = read();
                    for(auto itea = buc[tmp].begin(); itea != buc[tmp].end(); ++itea){
                        tbuc[itea->second] += itea->first;
                        maxx = max(maxx, make_pair(tbuc[itea->second], itea->second));
                    }
                    siz += ord[tmp].size();
                }
                if(maxx.first > siz / 2)printf("%d\n", maxx.second);
                else printf("-1\n");
                break;
            }
            case 4:{
                int a = read(), b = read(), c = read();
                int tbuc[MAXNQ];
                memset(tbuc, 0, sizeof(tbuc));
                int maxp(0);
                for(auto itea = buc[a].begin(); itea != buc[a].end(); ++itea){
                    tbuc[itea->second] += itea->first;
                    maxp = max(maxp, itea->second);
                }
                for(auto itea = buc[b].begin(); itea != buc[b].end(); ++itea){
                    tbuc[itea->second] += itea->first;
                    maxp = max(maxp, itea->second);
                }
                for(int i = 0; i <= maxp; ++i){
                    if(tbuc[i])buc[c].push(make_pair(tbuc[i], i));
                }
                // copy(ord[a].begin(), ord[a].end(), ord[c].begin());
                for(auto i : ord[a])ord[c].push_back(i);
                for(auto i : ord[b])ord[c].push_back(i);
                buc[a].clear(), buc[b].clear();
                ord[a].clear(), ord[b].clear();
            }
        }
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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