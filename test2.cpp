#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double input;
    cout << "请输入一个两位小数的浮点数（范围不超过1e10）：";
    cin >> input;
    // input += 1.0e-6;

    printf("%.10lf\n", input);
    
    // 记录符号，统一转换为正数处理
    bool isNegative = false;
    if (input < 0) {
        isNegative = true;
        input = -input;
    }
    
    // 分离整数部分和小数部分
    double intPart, fracPart;
    fracPart = modf(input, &intPart);
    fracPart = input - intPart;

    printf("INPUT: %.10lf\nINT: %.10lf\nFRAC: %.10lf\n", input, intPart, fracPart);
    
    // 处理整数部分：找到最高位对应的除数
    double divisor = 1;
    while (divisor * 10 <= intPart) {
        divisor *= 10;
    }
    
    if(isNegative)
        cout << "- ";
    
    cout << "各位数字：";
    
    // 提取整数部分的各位数字
    while (divisor >= 1) {
        int digit = static_cast<int>(intPart / divisor);
        cout << digit << " ";
        intPart = fmod(intPart, divisor);
        divisor /= 10;
    }
    
    // 提取小数部分的两位数字
    // 注意这里只对小数部分进行局部放大，而非整体放大
    fracPart *= 100;
    fracPart = round(fracPart);
    printf("%d %d\n", int(fracPart) / 10, int(fracPart) % 10);
    // for (int i = 0; i < 2; i++) {
    //     fracPart *= 10;
    //     // 由于浮点数运算可能存在微小误差，加上一个极小的偏移量
    //     cout << (int)(i == 1 ? round(fracPart) : floor(fracPart)) << " ";
    //     // int digit = static_cast<int>(floor(fracPart + 1e-8));
    //     // cout << digit << " ";
    //     fracPart -= floor(fracPart);
    // }
    
    // cout << endl;
    return 0;
}
