#ifndef PRIMES_PRIMES_H
#define PRIMES_PRIMES_H
#include <bitset>
#include <vector>

class Primes {
private:
    const uint32_t BITSET_SIZE = 1024 * 1024;
    std::vector<uint32_t> primes;
public:
    //if you wan't to find primes to max Primes(max, 1), if cnt primes thew Primes(cnt, 0)
    Primes(uint32_t max, bool is_max);
    uint32_t size();
    uint32_t operator[](uint32_t index);
};

#endif //PRIMES_PRIMES_H
