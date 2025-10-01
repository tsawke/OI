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

template < typename T = int >
inline T read(void);


int main(){
    int N = read(), R = read(), Q = read();
    N <<= 1;
    vector < tuple < int, int, int > > players;
    for(int i = 1; i <= N; ++i)players.push_back({read(), 0, i});
    for(int i = 1; i <= N; ++i)get < 1 >(players[i - 1]) = read();
    sort(players.begin(), players.end(), [](const tuple < int, int, int > &a, const tuple < int, int, int > &b)->bool{
        return get < 0 >(a) == get < 0 >(b) ? get < 2 >(a) < get < 2 >(b) : get < 0 >(a) > get < 0 >(b);
    });
    while(R--){
        vector < tuple < int, int, int > > winner, loser;
        for(auto it = players.begin(); it < prev(players.end()); advance(it, 2))
            get < 1 >(*it) > get < 1 >(*next(it)) ? (++get < 0 >(*it), winner.push_back(*it), loser.push_back(*next(it))) : (++get < 0 >(*next(it)), winner.push_back(*next(it)), loser.push_back(*it));
        if(players.size() & 1)loser.push_back(*prev(players.end()));

        players.clear();
        for(auto it1 = winner.begin(), it2 = loser.begin(); it1 != winner.end() || it2 != loser.end();){
            if(it1 == winner.end())players.push_back(*it2), ++it2;
            else if(it2 == loser.end())players.push_back(*it1), ++it1;
            else 
                get < 0 >(*it1) == get < 0 >(*it2) ? (get < 2 >(*it1) < get < 2 >(*it2) ? (players.push_back(*it1), ++it1) : (players.push_back(*it2), ++it2)) : get < 0 >(*it1) > get < 0 >(*it2) ? (players.push_back(*it1), ++it1) : (players.push_back(*it2), ++it2);
        }
    }
    // sort(players.begin(), players.end(), [](const tuple < int, int, int > &a, const tuple < int, int, int > &b)->bool{
    //     return get < 0 >(a) == get < 0 >(b) ? get < 2 >(a) < get < 2 >(b) : get < 0 >(a) > get < 0 >(b);
    // });
    printf("%d\n", get < 2 >(players[Q - 1]));


    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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