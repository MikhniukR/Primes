#include <iostream>
#include "Primes.h"
#include <bitset>
#include <algorithm>
#include <cmath>


Primes::Primes(uint32_t max, bool is_max) {
    //bitset to Eratosthenes algorithm
    std::bitset<1024 * 1024> is_prime;
    is_prime.set();

    //find first 1024 * 1024 primes
    for(uint32_t i = 2; i <= 1024; i++) {
        if(is_prime.test(i)) {
            for (uint32_t j = i * i; j < BITSET_SIZE; j += i) {
                is_prime.reset(j);
            }
        }
    }
    std::cout << "Find all primes in range 1 to " << BITSET_SIZE << std::endl;

    uint32_t prime_minus = 0;
    uint32_t cnt = 0;
    if(!is_max) {
        cnt = max;
        max = UINT32_MAX;
    }

    for(uint32_t i = 2; i <= max; i++) {
        if(i % BITSET_SIZE == 0) {
            is_prime.set();
            prime_minus += BITSET_SIZE;
            for(auto i = data.begin(); i != data.end() && sqrt(prime_minus + BITSET_SIZE) + 1 > *i; i++)
                for(uint32_t j = (*i) * (*i); j - prime_minus < BITSET_SIZE; j += *i)
                    if(j - prime_minus >= 0)
                        is_prime.reset(j - prime_minus);
            std::cout << "Find all primes in range " << prime_minus << " to " << prime_minus + BITSET_SIZE << std::endl;
        }

        if(is_prime.test(i - prime_minus)) {
            this -> data.push_back(i);
            if(!is_max && cnt == data.size()) {
                break;
            }
        }

        if(i == UINT32_MAX) {
            std::cout << "Can't find all primes in range 0 to " << UINT32_MAX << std::endl;
        }
    }
}


uint32_t Primes::size() {
    return static_cast<uint32_t>(data.size());
}

uint32_t Primes::operator[](uint32_t index) {
    if(index >= data.size()) {
        std::cout << "Error.Out of array";
    }
    return data[index];
}

Iterator Primes::begin() {
    return Iterator(this, 0);
}

Iterator Primes::end() {
    return Iterator(this, size());
}

Iterator::Iterator(Primes *primes, int index) : primes(primes), index(index){}

bool Iterator::operator!=(Iterator const &other) const {
    return index != other.index || primes != other.primes;
}
bool Iterator::operator==(Iterator const &other) const {
    return index == other.index && primes == other.primes;
}

Iterator::reference Iterator::operator*() const {
    return primes -> data[index];
}

Iterator &Iterator::operator++() {
    index++;
    return * this;
}

Iterator &Iterator::operator--() {
    index--;
    return  * this;
}
