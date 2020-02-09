#include <iostream>
#include "Primes.h"
#include <string>
#include <fstream>
#include <algorithm>

bool is_equals(const char *s1, std::string &s2) {
    int i = 0;
    while(i < s2.length()) {
        if(s1[i] != s2[i]) {
            return false;
        }
        i++;
    }
    return !(i == s2.length() && s1[i] != 0);
}

bool check_is_uint(const char *s) {
    int i = 0;
    while(s[i] != 0) {
        if(!isdigit(s[i])) {
            return false;
        }
        i++;
    }
    return true;
}

uint32_t stoui(const char *s) {
    uint32_t result = 0;
    int i = 0;
    while(s[i] != 0) {
        if((result * 10 + (s[i] - '0'))/10 != result) {
            std::cout << "Too big argument, should be in range 1 to " << UINT32_MAX << std::endl;
            exit(0);
        }
        result *= 10;
        result += (s[i] - '0');
        i++;
    }
    return result;
}

int main(int argc, char *argv[]) {
    bool is_max = true;
    int use_file = 0;
    uint32_t max = 100, cnt = 1;
    if (argc > 1 && is_equals(argv[1], "-i")) {
        std::cout << "-i info message\n"
                  << "-file Filename print primes to file\n"
                  << "-max MAX set max value of primes\n"
                  << "-cnt CNT set cnt of primes\n"
                  << "CNT and MAX should be in range [1; " << UINT32_MAX << "]" << std::endl;
        return 0;
    }
    for(int i = 1; i < 4; i++) {
        if(argc > i && is_equals(argv[i], "-max")) {
            is_max = true;
            if (argc > i + 1 && check_is_uint(argv[i + 1])) {
                max = stoui(argv[i + 1]);
            }
            else {
                std::cout << "Incorrect arguments. after -max should be number" << std::endl;
                return 0;
            }
            i++;
        }
        else if(argc > i && is_equals(argv[i], "-cnt")) {
            is_max = false;
            if (argc > i + 1 && check_is_uint(argv[i + 1])) {
                cnt = stoui(argv[i + 1]);
            }
            else {
                std::cout << "Incorrect arguments. after -cnt should be number" << std::endl;
                return 0;
            }
            i++;
        }
        else if(argc > i && is_equals(argv[i], "-file")) {
            use_file = i + 1;
            if(argc == i + 1) {
                std::cout << "After -file should be file name" << std::endl;
                return 0;
            }
            i++;
        }
        else if(argc > i) {
            std::cout << "Invalid argument " << argv[i] << std::endl;
            return 0;
        }
    }
    Primes &primes = *new Primes(is_max ? max : cnt, is_max);
    if(!use_file) {
        std::for_each(primes.begin(), primes.end(), [](uint32_t _p) {
            std::cout << _p << " ";
        });
    }
    else {
        std::cout << "Start print primes to file" << std::endl;
        std::ofstream fout(argv[use_file]);
        for (int i = 0; i < primes.size(); i++) {
            fout << primes[i] << "\n";
            if (i % 100000 == 0 && i != 0) {
                std::cout << "Print first " << i << " primes to file" << std::endl;
            }
        }
    }
    return 0;
}