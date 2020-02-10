/**
\file
\brief Realization of Primes and his Iterator

    Finding primes writing with Eratosthenes algorithm using bitset.
 */

#include <iostream>
#include "Primes.h"
#include <bitset>
#include <algorithm>
#include <cmath>

Primes::Primes(uint32_t max, bool is_max) {
    std::bitset<1024 * 1024> is_prime; ///  bitset to Eratosthenes algorithm
    is_prime.set();

    ///  find first 1024 * 1024 primes
    for(uint32_t i = 2; i <= 1024; i++) {
        if(is_prime.test(i)) {
            for (uint32_t j = i * i; j < BITSET_SIZE; j += i) {
                is_prime.reset(j);
            }
        }
    }
    std::cout << "Find all primes in range 1 to " << BITSET_SIZE << std::endl;

    /**
     * prime_minus is distance between 0 and the first bit in is_prime
     * cnt is cnt of primes that should be found, if !is_max
     */
    uint32_t prime_minus = 0;
    uint32_t cnt = 0;
    if(!is_max) {
        cnt = max;
        max = UINT32_MAX;
    }

    for(uint32_t i = 2; i <= max; i++) {
        /// check is the end of current block of primes
        if(i % BITSET_SIZE == 0) {
            is_prime.set();
            prime_minus += BITSET_SIZE;
            ///calculate the next block of primes, using already counted primes to sift primes
            for(auto i = data.begin(); i != data.end() && sqrt(prime_minus + BITSET_SIZE) + 1 > *i; i++)
                for(uint32_t j = (*i) * (*i); j - prime_minus < BITSET_SIZE; j += *i)
                    if(j - prime_minus >= 0)
                        is_prime.reset(j - prime_minus);
            std::cout << "Find all primes in range " << prime_minus << " to " << prime_minus + BITSET_SIZE << std::endl;
        }
        /// check is i prime and save it
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
    /// check is index correct
    if(index >= data.size()) {
        std::cout << "Error.Out of array";
    }
    return data[index];
}

Iterator Primes::begin() {
    return {this, 0};
}

Iterator Primes::end() {
    return {this, static_cast<uint32_t>(data.size())};
}

Iterator::Iterator(Primes *primes, uint32_t index) : primes(primes), index(index){}

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
