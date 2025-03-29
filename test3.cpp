// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    // string label[20] = {"ignore", "圆神", "十位", "百位", "千位", "万位", "十万位", "百万位", "千万位", "亿位", "十亿位"};
    // string dem1 = "角", dem2 = "分";

    cout << "tips" << endl;

    double frac;
    cin >> frac;
    double intPart, fracPart;
    fracPart = modf(frac, &intPart); //Separate integer part and fraction part. 
    // for(int i = 10; i >= 1; --i)
    
    int i = 10;
    cout << "十亿位" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;  //Find i-th digit of integer part.
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1); //Remove i-th digit of integer part to avoid exceeding range of int.

    i = 9;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 8;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 7;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 6;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 5;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 4;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 3;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 2;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    i = 1;
    cout << "" << "\t: " << int(intPart / pow(10, i - 1)) % 10 << endl;
    intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1);

    // printf("%s \t: %d\n", "".c_str(), int(intPart / pow(10, i - 1)) % 10), //Find i-th digit of integer part.
    // intPart -= (double)(int(intPart / pow(10, i - 1)) % 10) * pow(10, i - 1); //Remove i-th digit of integer part to avoid exceeding range of int.

    fracPart = round(fracPart * 100);


    cout << "角" << "\t: " << int(fracPart) / 10 << endl << "分" << "\t: " << int(fracPart) % 10 << endl;

    // printf("%s\t: %d\n%s\t: %d\n", dem1.c_str(), int(fracPart) / 10, dem2.c_str(), int(fracPart) % 10);

    return 0;
}