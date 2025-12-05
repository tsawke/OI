#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


#define D1(x) (x / 1000)
#define D2(x) (x / 100 % 10)
#define D3(x) (x / 10 % 10)
#define D4(x) (x % 10)


template<typename T = int>
inline T read(void);

// auto Encode = [](int x) -> tuple < int, int, int, int >{
//     return {x / 1000, x  / 100 % 10, x / 10 % 10, x % 10};
// };
auto Encode = [](int x) -> basic_string < int >{
    return {x / 1000, x  / 100 % 10, x / 10 % 10, x % 10};
};
// auto Encode2 = [](int x) -> basic_string < int >{
//     return {x / 1000, x  / 100 % 10, x / 10 % 10, x % 10};
// };
// auto Encode2 = [](basic_string < int> x) -> int{
//     return (x.at(0) + 10) * 1000000 + (x.at(1) + 10) * 10000 + (x.at(2) + 10) * 100 + (x.at(3) + 10);
// };
auto Decode = [](basic_string < int> x) -> int{
    return (x.at(0)) * 1000 + (x.at(1) ) * 100 + (x.at(2) ) * 10 + (x.at(3) );
};
// auto Check = [](basic_string < int> x) -> bool{
//     for(int i = 0; i <= 3; ++i)if(!(-9 <= x.at(i) && x.at(i) <= 9))return false;
//     return true;
// };

// unordered_map < int, int > dis;

// auto BFS = []() -> void{
//     dis[Encode2(Encode(0))] = 0;
//     queue < pair < basic_string < int >, int > > cur; cur.push({Encode(0), 0});
//     while(!cur.empty()){
//         auto [p, d] = cur.front(); cur.pop();
        
//         for(int len = 1; len <= 4; ++len){
//             for(int l = 1; l + len - 1 <= 4; ++l){
//                 auto s = p;
//                 auto s2 = s;
//                 int r = l + len - 1;

//                 for(int i = l; i <= r; ++i)s.at(i - 1) = s.at(i - 1) + 1 >= 10 ? 0 : s.at(i - 1) + 1;
//                 // printf("s1 = %d, d = %d\n", s, d + 1);
//                 // if(!Check(s))continue;
//                 if(Check(s) && !~dis[Encode2(s)])dis[Encode2(s)] = d + 1, cur.push({s, d + 1});

//                 for(int i = l; i <= r; ++i)s2.at(i - 1)--;// = s2.at(i - 1) - 1 < 0 ? 9 : s2.at(i - 1) - 1;
//                 // printf("s2 = %d, d = %d\n", s, d + 1);
//                 // if(!Check(s2))continue;

//                 if(Check(s2) && !~dis[Encode2(s2)])dis[Encode2(s2)] = d + 1, cur.push({s2, d + 1});
//             }
//         }
//     }
// };

int dis[110000];

auto BFS = []() -> void{
    memset(dis, -1, sizeof(dis));
    dis[0] = 0;
    queue < pair < int, int > > cur; cur.push({0, 0});
    while(!cur.empty()){
        auto [p, d] = cur.front(); cur.pop();
        
        for(int len = 1; len <= 4; ++len){
            for(int l = 1; l + len - 1 <= 4; ++l){
                auto s = Encode(p);
                auto s2 = Encode(p);
                int r = l + len - 1;

                for(int i = l; i <= r; ++i)s[i - 1] = (s[i - 1] + 1 + 10) % 10;  //s.at(i - 1) = s.at(i - 1) + 1 >= 10 ? 0 : s.at(i - 1) + 1;
                // printf("s1 = %d, d = %d\n", s, d + 1);
                // if(!Check(s))continue;
                if(!~dis[Decode(s)])dis[Decode(s)] = d + 1, cur.push({Decode(s), d + 1});

                for(int i = l; i <= r; ++i)s2[i - 1] = (s2[i - 1] - 1 + 10) % 10;  //  s2.at(i - 1)--;// = s2.at(i - 1) - 1 < 0 ? 9 : s2.at(i - 1) - 1;
                // printf("s2 = %d, d = %d\n", s, d + 1);
                // if(!Check(s2))continue;

                if(!~dis[Decode(s2)])dis[Decode(s2)] = d + 1, cur.push({Decode(s2), d + 1});
            }
        }
    }
};

// int ans(0);
// basic_string < int > d;

// auto Desc = [](basic_string < int > p)->void{
//     for(int i = 0; i <= 3; ++i)printf("%d%c", p.at(i), i == 3 ? '\n' : ' ');
// };

int main(){
    freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
    // memset(dis, -1, sizeof dis);
    // for(int v1 = -9; v1 <= 9; ++v1){
    //     for(int v2 = -9; v2 <= 9; ++v2){
    //         for(int v3 = -9; v3 <= 9; ++v3){
    //             for(int v4 = -9; v4 <= 9; ++v4){
    //                 basic_string < int > v({v1, v2, v3, v4});
    //                 // v += v1, v += v2, v += v3, v += v4;
    //                 dis.insert({Encode2(v), -1});
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i <= 9999; ++i)dis.insert({Encode2(Encode(i)), -1});
    BFS();
    // printf("dis = %d\n", dis[1234][3421]);
    // freopen("in.txt", "r", stdin);
    int T = read();

    

    // auto dfs = [](auto&& self, auto ss, auto tt, int dep = 1)->void{
    //     if(dep == 5){
    //         // Desc(d);
    //         // for(int i = 0; i <= 3; ++i)if()
    //         if(!Check(d))return;
    //         ans = min(ans, dis[Encode2(d)]);
    //         return;
    //     }
    //     d += tt.at(dep - 1) - ss.at(dep - 1);
    //     self(self, ss, tt, dep + 1);
    //     d.pop_back();
    //     if(tt.at(dep - 1) == ss.at(dep - 1))return;
    //     d += 0 - ss.at(dep - 1) + tt.at(dep - 1) - 9;
    //     self(self, ss, tt, dep + 1);
    //     d.pop_back();
    //     d += 9 - ss.at(dep - 1) + tt.at(dep - 1) - 0;
    //     self(self, ss, tt, dep + 1);
    //     d.pop_back();
    // };

    while(T--){
        int s = read(), t = read();
        // printf("%d\n", dis[s][t]);
        // if(!~dis[s][t] && !~dis[t][s])BFS(s);
        // printf("%d\n", ~dis[s][t] ? dis[s][t] : dis[t][s]);
        auto ss = Encode(s), tt = Encode(t);

        // ans = 114514;
        // dfs(dfs, ss, tt);



        basic_string < int > d;

        for(int i = 0; i <= 3; ++i)
            d += (tt.at(i) - ss.at(i) + 10) % 10;

        printf("%d\n", dis[Decode(d)]);
        
        //     basic_string < int > d2;

        //     for(int i = 0; i <= 3; ++i)
        //         d2 += 0 - ss.at(i) + tt.at(i) - 9;
            



        //         basic_string < int > d3;

        //         for(int i = 0; i <= 3; ++i)
        //             d3 += tt.at(i) - 9;

        //             for(int i = 0; i <= 3; ++i)
        //         d2 += 0 - ss.at(i);
        //         basic_string < int > d3;

        //         for(int i = 0; i <= 3; ++i)
        //             d3 += tt.at(i) - 9;


        // printf("%d\n", ans);
        // printf("s = %d, t = %d\n", dis[s], dis[t]);

        // printf("%d\n", abs(dis[t] - dis[s]));
        

        // int cnt(0);
        // while(s != t){
        //     int f1 = D1(s) < D1(t) ? 1 : (D1(s) == D1(t) ? 0 : -1);
        //     int f2 = D2(s) < D2(t) ? 1 : (D2(s) == D2(t) ? 0 : -1);
        //     int f3 = D3(s) < D3(t) ? 1 : (D3(s) == D3(t) ? 0 : -1);
        //     int f4 = D4(s) < D4(t) ? 1 : (D4(s) == D4(t) ? 0 : -1);
        //     // printf("cnt = %d, s = %d\n", cnt, s);
        //     // printf("f = %d, %d, %d, %d\n", f1, f2, f3, f4);
        //     if(f1 == f2 && f2 == f3 && f3 == f4){
        //         s += f1 * 1111;
        //         ++cnt;
        //     }else if(f1 == f2 && f2 == f3){
        //         if(f1){
        //             s += f1 * 1110;
        //             ++cnt;
        //         }
        //         if(f4){
        //             s += f4 * 1;
        //             ++cnt;
        //         }
        //     }else if(f1 == f2 && f2 == f4){
        //         if(f1){
        //             s += f1 * 1101;
        //             ++cnt;
        //         }
        //         if(f3){
        //             s += f3 * 10;
        //             ++cnt;
        //         }
        //     }else if(f1 == f3 && f4 == f3){
        //         if(f1){
        //             s += f1 * 1011;
        //             ++cnt;
        //         }
        //         if(f4){
        //             s += f2 * 100;
        //             ++cnt;
        //         }
        //     }else if(f4 == f2 && f2 == f3){
        //         if(f2){
        //             // printf("find, f2 = %d, spre = %d\n", f2, s);
        //             s += f2 * 111;
        //             // printf("plus = %d\n", f2 * 0111);
        //             ++cnt;
        //             // printf("find, f2 = %d, s = %d\n", f2, s);
        //         }
        //         if(f1){
        //             s += f1 * 1000;
        //             ++cnt;
        //         }
        //     }else if(f1 == f2){
        //         if(f1){
        //             s += f1 * 1100;
        //             ++cnt;
        //         }
        //         if(f3 == f4){
        //             if(f3){
        //                 s += f3 * 11;
        //                 ++cnt;
        //             }
        //         }else{
        //             if(f3){
        //                 s += f3 * 10;
        //                 ++cnt;
        //             }
        //             if(f4){
        //                 s += f4 * 1;
        //                 ++cnt;
        //             }
        //         }
        //     }else if(f1 == f3){
        //         if(f1){
        //             s += f1 * 1010;
        //             ++cnt;
        //         }
        //         if(f2 == f4){
        //             if(f2){
        //                 s += f2 * 101;
        //                 ++cnt;
        //             }
        //         }else{
        //             if(f2){
        //                 s += f2 * 100;
        //                 ++cnt;
        //             }
        //             if(f4){
        //                 s += f4 * 1;
        //                 ++cnt;
        //             }
        //         }
        //     }else if(f1 == f4){
        //         if(f1){
        //             s += f1 * 1001;
        //             ++cnt;
        //         }
        //         if(f2 == f3){
        //             if(f3){
        //                 s += f3 * 110;
        //                 ++cnt;
        //             }
        //         }else{
        //             if(f3){
        //                 s += f3 * 10;
        //                 ++cnt;
        //             }
        //             if(f2){
        //                 s += f2 * 100;
        //                 ++cnt;
        //             }
        //         }
        //     }else{
        //         if(f3){
        //             s += f3 * 10;
        //             ++cnt;
        //         }
        //         if(f2){
        //             s += f2 * 100;
        //             ++cnt;
        //         }
        //         if(f1){
        //             s += f1 * 1000;
        //             ++cnt;
        //         }
        //         if(f4){
        //             s += f4 * 1;
        //             ++cnt;
        //         }
        //     }
        // }
        // printf("%d\n", cnt);
    
    
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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