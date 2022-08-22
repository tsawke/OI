g++ $1.cpp -o 1 -fdiagnostics-color=always -fsanitize=undefined,signed-integer-overflow,address -Wall -std=c++14 -g
#g++ $1.cpp -o 1 -fdiagnostics-color=always -std=c++14