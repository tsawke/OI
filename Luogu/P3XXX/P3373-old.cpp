//SegTree Template
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

struct Vertex{
    ll value = 0;
    ll lazymark = 0;
    ll lazymark2 = 1;
    int lRange = 0, rRange = 0;
    int GetVertexN(void){return this->rRange - this->lRange + 1;}
};
int N, operationN;
ll MOD;
Vertex segTree[110000 * 4];
void BuildSegTree_WithInput(int = 1, int = N, int = 1);
void UpdateSegTree_BySection(int, int, int, int = 1);
void UpdateSegTree_BySection_Multiply(int, int, int, int = 1);
ll QuerySegTree_BySection(int, int, int = 1);
void PushDownLazymark(int);
void PushDownLazymark2(int);
void DescSegTree(int);
int main(){
    N = read(), operationN = read(), MOD = read<ll>();
    BuildSegTree_WithInput();
    // DescSegTree(N * 4);
    for(int i = 1; i <= operationN; ++i){
        int mode = read();
        if(mode == 1){
            int lS = read(), rS = read(), value = read();
            UpdateSegTree_BySection_Multiply(lS, rS, value);
        }
        if(mode == 2){
            int lS = read(), rS = read(), value = read();
            UpdateSegTree_BySection(lS, rS, value);
        }
        if(mode == 3){
            int lS = read(), rS = read();
            printf("%lld\n", QuerySegTree_BySection(lS, rS) % MOD);
        }
        // DescSegTree(N * 4);
    }
    return 0;
}
void DescSegTree(int N){
    printf("\nPrintSegTree[]: \n");
    // for(int i = 1; i <= N; ++i){
    //     printf("SegTree[%d] => value=%d,  lazymark=%d\n", i, segTree[i].value, segTree[i].lazymark);
    // }
    int i = 1;
    int base(1), baseN(0);
    while(i <= N){
        printf("[%lld-%lld](%d~%d)  ", segTree[i].value, segTree[i].lazymark, segTree[i].lRange, segTree[i].rRange);
        ++baseN;
        ++i;
        if(baseN == base){
            printf("\n");
            base <<= 1;
            baseN = 0;
        }
    }
}
void PushDownLazymark(int rootVertex){
    segTree[rootVertex * 2].value += segTree[rootVertex].lazymark * segTree[rootVertex * 2].GetVertexN();
    segTree[rootVertex * 2 + 1].value += segTree[rootVertex].lazymark * segTree[rootVertex * 2 + 1].GetVertexN();
    segTree[rootVertex * 2].lazymark += segTree[rootVertex].lazymark;
    segTree[rootVertex * 2 + 1].lazymark += segTree[rootVertex].lazymark;
    segTree[rootVertex].lazymark = 0;
}
void PushDownLazymark2(int rootVertex){
    segTree[rootVertex * 2].value *= segTree[rootVertex].lazymark2;
    segTree[rootVertex * 2 + 1].value *= segTree[rootVertex].lazymark2;
    segTree[rootVertex * 2].lazymark2 *= segTree[rootVertex].lazymark2;
    segTree[rootVertex * 2 + 1].lazymark2 *= segTree[rootVertex].lazymark2;
    segTree[rootVertex * 2].value %= MOD;
    segTree[rootVertex * 2].lazymark2 %= MOD;
    segTree[rootVertex * 2 + 1].value %= MOD;
    segTree[rootVertex * 2 + 1].lazymark2 %= MOD;
    segTree[rootVertex].lazymark2 = 1;
}
void BuildSegTree_WithInput(int lRange, int rRange, int rootVertex){
    if(lRange == rRange){
        segTree[rootVertex].value = read();
        segTree[rootVertex].lRange = segTree[rootVertex].rRange = lRange;    
        return;
    }
    int mid = (rRange + lRange) / 2;
    BuildSegTree_WithInput(lRange, mid, rootVertex * 2);
    BuildSegTree_WithInput(mid + 1, rRange, rootVertex * 2 + 1);
    segTree[rootVertex].lRange = lRange;
    segTree[rootVertex].rRange = rRange;
    segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
    return;
}
ll QuerySegTree_BySection(int lSectionRange, int rSectionRange, int rootVertex){
    // printf("Querying lR = %d  rR = %d  vlr=%d vrr=%d root = %d\n", lSectionRange, rSectionRange, segTree[rootVertex].lRange, segTree[rootVertex].rRange, rootVertex);
    if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange)
        return segTree[rootVertex].value;
    if(segTree[rootVertex].rRange < lSectionRange || rSectionRange < segTree[rootVertex].lRange)
        return 0;
    if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
        PushDownLazymark(rootVertex);
    if(segTree[rootVertex].lazymark2 != 1 && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
        PushDownLazymark2(rootVertex);
    return 
        QuerySegTree_BySection(lSectionRange, rSectionRange, rootVertex * 2) % MOD +
        QuerySegTree_BySection(lSectionRange, rSectionRange, rootVertex * 2 + 1) % MOD;
}
void UpdateSegTree_BySection(int lSectionRange, int rSectionRange, int updValue, int rootVertex){
    if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange){
        segTree[rootVertex].value += segTree[rootVertex].GetVertexN() * updValue;
        segTree[rootVertex].lazymark += updValue;
        return;
    }
    if(segTree[rootVertex].rRange < lSectionRange || rSectionRange < segTree[rootVertex].lRange)
        return;
    if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
        PushDownLazymark(rootVertex);
    if(segTree[rootVertex * 2].GetVertexN())
        UpdateSegTree_BySection(lSectionRange, rSectionRange, updValue, rootVertex * 2);
    if(segTree[rootVertex * 2 + 1].GetVertexN())
        UpdateSegTree_BySection(lSectionRange, rSectionRange, updValue, rootVertex * 2 + 1);
    segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
    // if(segTree[rootVertex * 2].GetVertexN())UpdateSegTree_BySection(segTree[rootVertex * 2].lRange, segTree[rootVertex * 2].rRange, updValue, rootVertex * 2);
    // if(segTree[rootVertex * 2 + 1].GetVertexN())UpdateSegTree_BySection(segTree[rootVertex * 2 + 1].lRange, segTree[rootVertex * 2 + 1].rRange, updValue, rootVertex * 2 + 1);
}
void UpdateSegTree_BySection_Multiply(int lSectionRange, int rSectionRange, int updValue, int rootVertex){
    if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange){
        segTree[rootVertex].value *= updValue;
        segTree[rootVertex].lazymark2 *= updValue;
        segTree[rootVertex].value %= MOD;
        segTree[rootVertex].lazymark2 %= MOD;
        return;
    }
    if(segTree[rootVertex].rRange < lSectionRange || rSectionRange < segTree[rootVertex].lRange)
        return;
    if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
        PushDownLazymark2(rootVertex);
    if(segTree[rootVertex * 2].GetVertexN())
        UpdateSegTree_BySection_Multiply(lSectionRange, rSectionRange, updValue, rootVertex * 2);
    if(segTree[rootVertex * 2 + 1].GetVertexN())
        UpdateSegTree_BySection_Multiply(lSectionRange, rSectionRange, updValue, rootVertex * 2 + 1);
    segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
}
template <typename T = int>
inline T read(void)
{
    T ret(0);
    short flag(1);
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        ret *= 10, ret += (c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}
// //SegTree Template
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #include <cstdlib>
// #include <cmath>
// #include <vector>
// #include <climits>
// #include <iostream>
// #include <string>
// #include <map>
// #include <queue>
// #include <stack>
// #include <functional>
// #include <unistd.h>

// using namespace std;
// typedef unsigned int uint;
// typedef unsigned long long unll;
// typedef long long ll;
// template <typename T = int>
// inline T read(void);

// struct Vertex{
//     // ll value = 0;
//     // ll lazymark = 0;
//     // ll lazymark2 = 1;
//     // int lRange = 0, rRange = 0;
//     ll value;
//     ll lazymark;
//     ll lazymark2;
//     int lRange, rRange;
//     void init(void){
//         this->lazymark2 = 1;
//         this->lazymark = 0;
//         this->lRange = this->rRange = 0;
//         this->value = 0;
//     }
//     int GetVertexN(void){return this->rRange - this->lRange + 1;}
// };
// int N, operationN;
// ll MOD;
// Vertex segTree[110000 * 4];
// void BuildSegTree_WithInput(int = 1, int = N, int = 1);
// void UpdateSegTree_BySection(int, int, int, int = 1);
// void UpdateSegTree_BySection_Multiply(int, int, int, int = 1);
// ll QuerySegTree_BySection(int, int, int = 1);
// void PushDownLazymark(int);
// void PushDownLazymark2(int);
// void DescSegTree(int);
// int main(){
// 	N = read(), operationN = read(), MOD = read<ll>();
//     for(int i = 1; i <= N * 4; ++i)segTree[i].init();
//     BuildSegTree_WithInput();
//     // DescSegTree(N * 4);
//     for(int i = 1; i <= operationN; ++i){
//         int mode = read();
//         if(mode == 1){
//             int lS = read(), rS = read(), value = read();
//             UpdateSegTree_BySection_Multiply(lS, rS, value);
//         }
//         if(mode == 2){
//             int lS = read(), rS = read(), value = read();
//             UpdateSegTree_BySection(lS, rS, value);
//         }
//         if(mode == 3){
//             int lS = read(), rS = read();
//             printf("%lld\n", QuerySegTree_BySection(lS, rS) % MOD);
//         }
//         // DescSegTree(N * 4);
//     }
//     return 0;
// }
// void DescSegTree(int N){
//     printf("\nPrintSegTree[]: \n");
//     // for(int i = 1; i <= N; ++i){
//     //     printf("SegTree[%d] => value=%d,  lazymark=%d\n", i, segTree[i].value, segTree[i].lazymark);
//     // }
//     int i = 1;
//     int base(1), baseN(0);
//     while(i <= N){
//         printf("[%lld-%lld](%d~%d)  ", segTree[i].value, segTree[i].lazymark, segTree[i].lRange, segTree[i].rRange);
//         ++baseN;
//         ++i;
//         if(baseN == base){
//             printf("\n");
//             base <<= 1;
//             baseN = 0;
//         }
//     }
// }
// void PushDownLazymark(int rootVertex){
//     if(segTree[rootVertex * 2].lazymark2 != 1)PushDownLazymark2(rootVertex * 2);
//     if(segTree[rootVertex * 2 + 1].lazymark2 != 1)PushDownLazymark2(rootVertex * 2 + 1);
//     segTree[rootVertex * 2].value += segTree[rootVertex].lazymark * segTree[rootVertex * 2].GetVertexN();
//     segTree[rootVertex * 2 + 1].value += segTree[rootVertex].lazymark * segTree[rootVertex * 2 + 1].GetVertexN();
//     segTree[rootVertex * 2].lazymark += segTree[rootVertex].lazymark;
//     segTree[rootVertex * 2 + 1].lazymark += segTree[rootVertex].lazymark;
//     segTree[rootVertex].lazymark = 0;
// }
// void PushDownLazymark2(int rootVertex){
//     if(segTree[rootVertex * 2].lazymark)PushDownLazymark(rootVertex * 2);
//     if(segTree[rootVertex * 2 + 1].lazymark)PushDownLazymark(rootVertex * 2 + 1);
//     segTree[rootVertex * 2].value *= segTree[rootVertex].lazymark2;
//     segTree[rootVertex * 2 + 1].value *= segTree[rootVertex].lazymark2;
//     segTree[rootVertex * 2].lazymark2 *= segTree[rootVertex].lazymark2;
//     segTree[rootVertex * 2 + 1].lazymark2 *= segTree[rootVertex].lazymark2;
//     segTree[rootVertex * 2].value %= MOD;
//     segTree[rootVertex * 2].lazymark2 %= MOD;
//     segTree[rootVertex * 2 + 1].value %= MOD;
//     segTree[rootVertex * 2 + 1].lazymark2 %= MOD;
//     segTree[rootVertex].lazymark2 = 1;
// }
// void BuildSegTree_WithInput(int lRange, int rRange, int rootVertex){
//     if(lRange == rRange){
//         segTree[rootVertex].value = read();
//         segTree[rootVertex].lRange = segTree[rootVertex].rRange = lRange;    
//         return;
//     }
//     int mid = (rRange + lRange) / 2;
//     BuildSegTree_WithInput(lRange, mid, rootVertex * 2);
//     BuildSegTree_WithInput(mid + 1, rRange, rootVertex * 2 + 1);
//     segTree[rootVertex].lRange = lRange;
//     segTree[rootVertex].rRange = rRange;
//     segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
//     return;
// }
// ll QuerySegTree_BySection(int lSectionRange, int rSectionRange, int rootVertex){
//     // printf("Querying lR = %d  rR = %d  vlr=%d vrr=%d root = %d\n", lSectionRange, rSectionRange, segTree[rootVertex].lRange, segTree[rootVertex].rRange, rootVertex);
//     if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange)
//         return segTree[rootVertex].value;
//     if(segTree[rootVertex].rRange < lSectionRange || rSectionRange < segTree[rootVertex].lRange)
//         return 0;
//     if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
//         PushDownLazymark(rootVertex);
//     if(segTree[rootVertex].lazymark2 != 1 && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
//         PushDownLazymark2(rootVertex);
//     return 
//         QuerySegTree_BySection(lSectionRange, rSectionRange, rootVertex * 2) % MOD +
//         QuerySegTree_BySection(lSectionRange, rSectionRange, rootVertex * 2 + 1) % MOD;
// }
// void UpdateSegTree_BySection(int lSectionRange, int rSectionRange, int updValue, int rootVertex){
//     if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange){
//         segTree[rootVertex].value += segTree[rootVertex].GetVertexN() * updValue;
//         segTree[rootVertex].lazymark += updValue;
//         return;
//     }
//     if(segTree[rootVertex].rRange < lSectionRange || rSectionRange < segTree[rootVertex].lRange)
//         return;
//     if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
//         PushDownLazymark(rootVertex);
//     if(segTree[rootVertex * 2].GetVertexN())
//         UpdateSegTree_BySection(lSectionRange, rSectionRange, updValue, rootVertex * 2);
//     if(segTree[rootVertex * 2 + 1].GetVertexN())
//         UpdateSegTree_BySection(lSectionRange, rSectionRange, updValue, rootVertex * 2 + 1);
//     segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
//     // if(segTree[rootVertex * 2].GetVertexN())UpdateSegTree_BySection(segTree[rootVertex * 2].lRange, segTree[rootVertex * 2].rRange, updValue, rootVertex * 2);
//     // if(segTree[rootVertex * 2 + 1].GetVertexN())UpdateSegTree_BySection(segTree[rootVertex * 2 + 1].lRange, segTree[rootVertex * 2 + 1].rRange, updValue, rootVertex * 2 + 1);
// }
// void UpdateSegTree_BySection_Multiply(int lSectionRange, int rSectionRange, int updValue, int rootVertex){
//     if(lSectionRange <= segTree[rootVertex].lRange && segTree[rootVertex].rRange <= rSectionRange){
//         segTree[rootVertex].value *= updValue;
//         segTree[rootVertex].lazymark2 *= updValue;
//         segTree[rootVertex].value %= MOD;
//         segTree[rootVertex].lazymark2 %= MOD;
//         return;
//     }
//     if(segTree[rootVertex].rRange < lSectionRange || rSectionRange < segTree[rootVertex].lRange)
//         return;
//     if(segTree[rootVertex].lazymark && segTree[rootVertex].lRange != segTree[rootVertex].rRange)
//         PushDownLazymark2(rootVertex);
//     if(segTree[rootVertex * 2].GetVertexN())
//         UpdateSegTree_BySection_Multiply(lSectionRange, rSectionRange, updValue, rootVertex * 2);
//     if(segTree[rootVertex * 2 + 1].GetVertexN())
//         UpdateSegTree_BySection_Multiply(lSectionRange, rSectionRange, updValue, rootVertex * 2 + 1);
//     segTree[rootVertex].value = segTree[rootVertex * 2].value + segTree[rootVertex * 2 + 1].value;
// }
// template <typename T = int>
// inline T read(void)
// {
// 	T ret(0);
// 	short flag(1);
// 	char c = getchar();
// 	while (c < '0' || c > '9') {
// 		if (c == '-')flag = -1;
// 		c = getchar();
// 	}
// 	while (c >= '0' && c <= '9') {
// 		ret *= 10, ret += (c - '0');
// 		c = getchar();
//     }
//     ret *= flag;
// 	return ret;
// }