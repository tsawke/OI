g++ $1.cpp -o 1 -fsanitize=undefined,signed-integer-overflow,address -Wall -std=c++14 -O2 -fdiagnostics-color=always
#g++ $1.cpp -o 1 -fdiagnostics-color=always -std=c++14