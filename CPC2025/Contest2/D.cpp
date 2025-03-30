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

#define EPS (1.0e-6)
#define __NAN (1.0e-9)
#define STEP_LENGTH(err) (abs(err) > 1.0e-1 ? 1.0e-2 : 5.0e-4)

template<typename T = int>
inline T read(void);

int N;
double d[20][20];

class Point{
public:
    double x, y, z;
    Point& operator +=(Point b){
        x += b.x, y += b.y, z += b.z;
        return *this;
    }
}p[20];

auto Update = []() -> void{
    Point Delta[20];
    memset(Delta, 0, sizeof Delta);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            double dx = p[i].x - p[j].x;
            double dy = p[i].y - p[j].y;
            double dz = p[i].z - p[j].z;
            double rdis = sqrt(dx * dx + dy * dy + dz * dz);
            double err = rdis - d[i][j];

            if(rdis < __NAN)continue;
            double step = err / rdis;

            if(abs(err) < 1e-2)continue;

            // printf("step = %.6lf\n", step);

            // if(abs(err) < EPS)continue;
            
            // printf("%.6lf\n", err);

            

            // p[i].x += step * dx;
            // p[i].y += step * dy;
            // p[i].z += step * dz;

            // p[j].x -= step * dx;
            // p[j].y -= step * dy;
            // p[j].z -= step * dz;
            Delta[i].x -= step * dx * STEP_LENGTH(err);
            Delta[i].y -= step * dy * STEP_LENGTH(err);
            Delta[i].z -= step * dz * STEP_LENGTH(err);

            Delta[j].x += step * dx * STEP_LENGTH(err);
            Delta[j].y += step * dy * STEP_LENGTH(err);
            Delta[j].z += step * dz * STEP_LENGTH(err);

        //     printf("In update:\n");
        //     for(int i = 1; i <= N; ++i)
        // printf("%.6lf %.6lf %.6lf\n", p[i].x, p[i].y, p[i].z);
        }

    for(int i = 1; i <= N; ++i)
        p[i] += Delta[i];
    // printf("In update:\n");
    // for(int i = 1; i <= N; ++i)
    //     printf("%.6lf %.6lf %.6lf\n", p[i].x, p[i].y, p[i].z);

};
auto UpdateSpecifically = [](int a, int b) -> void{
    Point Delta[20];
    memset(Delta, 0, sizeof Delta);
    // for(int i = 1; i <= N; ++i)
    //     for(int j = 1; j <= N; ++j){
    //         if(i == j)continue;
    {int i = a, j = b;
            double dx = p[i].x - p[j].x;
            double dy = p[i].y - p[j].y;
            double dz = p[i].z - p[j].z;
            double rdis = sqrt(dx * dx + dy * dy + dz * dz);
            double err = rdis - d[i][j];

            if(rdis < __NAN)return;
            double step = err / rdis;

            if(abs(err) < 1e-2)return;

            // printf("step = %.6lf\n", step);

            // if(abs(err) < EPS)continue;
            
            // printf("%.6lf\n", err);

            

            // p[i].x += step * dx;
            // p[i].y += step * dy;
            // p[i].z += step * dz;

            // p[j].x -= step * dx;
            // p[j].y -= step * dy;
            // p[j].z -= step * dz;
            Delta[i].x -= step * dx * STEP_LENGTH(err);
            Delta[i].y -= step * dy * STEP_LENGTH(err);
            Delta[i].z -= step * dz * STEP_LENGTH(err);

            Delta[j].x += step * dx * STEP_LENGTH(err);
            Delta[j].y += step * dy * STEP_LENGTH(err);
            Delta[j].z += step * dz * STEP_LENGTH(err);

        //     printf("In update:\n");
        //     for(int i = 1; i <= N; ++i)
        // printf("%.6lf %.6lf %.6lf\n", p[i].x, p[i].y, p[i].z);
        // }
    }
    for(int i = 1; i <= N; ++i)
        p[i] += Delta[i];
    // printf("In update:\n");
    // for(int i = 1; i <= N; ++i)
    //     printf("%.6lf %.6lf %.6lf\n", p[i].x, p[i].y, p[i].z);

};

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            scanf("%lf", &d[i][j]);
    
    for(int i = 1; i <= N; ++i)
        p[i].x = ((double)rndd(0, (int)10e6) - 5.0e6) / 1.0e7,
        p[i].y = ((double)rndd(0, (int)10e6) - 5.0e6) / 1.0e7,
        p[i].z = ((double)rndd(0, (int)10e6) - 5.0e6) / 1.0e7;
    // for(int i = 1; i <= N; ++i)
    //     printf("%.6lf %.6lf %.6lf\n", p[i].x, p[i].y, p[i].z);
    while((double)clock() / CLOCKS_PER_SEC < 3.20)Update();
    // while((double)clock() / CLOCKS_PER_SEC < 2.70){
    //     // for(int i = 1; i <= N; ++i)
    //     // for(int j = 1; j <= N; ++j)
    //     //     if(abs(sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z)) - d[i][j]) > 1.0e-1)
    //     //         UpdateSpecifically(i, j);
    // }
    // for(int i = 1; i <= 10; ++i)Update();
    for(int i = 1; i <= N; ++i)
        printf("%.6lf %.6lf %.6lf\n", p[i].x, p[i].y, p[i].z);

    // for(int i = 1; i <= N; ++i)
    //     for(int j = 1; j <= N; ++j)
    //         printf("Error between %d & %d -> %.6lf\n", i, j, abs(sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z)) - d[i][j]));
    
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