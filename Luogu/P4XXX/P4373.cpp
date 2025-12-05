// #include "grader.h"
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

extern int get(int);
extern void set(int,int);
extern void shoutMinimum(int);
extern int getTrainLength(void);
extern int getWindowLength(void);
extern int getCurrentCarIndex(void);
extern int getCurrentPassIndex(void);

/*
5499 => cur
5498 => blockLen
5497 => blockCnt
1 => curMin
4000 + i => blockMin
*/

#define BASE1 (4000)

void helpBessie(int val){
    int N = getTrainLength(), K = getWindowLength();
    int idx = getCurrentCarIndex() + 1;
    if(!getCurrentPassIndex()){
        if(idx == 1)set(5498, sqrt(N)), set(5497, 1), set(1, INT_MAX);
        int B = get(5498);
        set(1, min(get(1), val));
        set(5499, get(5499) + 1);
        if(get(5499) == B || idx == N){
            set(BASE1 + get(5497), get(1)), set(5499, 0);
            set(1, INT_MAX), set(5497, get(5497) + 1);
        }
    }else{

    }
}