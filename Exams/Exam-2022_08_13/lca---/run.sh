g++ $1.cpp -o 1 -fdiagnostics-color=always -Wall -fsanitize=undefined,signed-integer-overflow,address -std=c++14 -g
#g++ $1.cpp -o 1 -fdiagnostics-color=always -std=c++14