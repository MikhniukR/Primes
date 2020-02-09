#ifndef PRIMES_PRIMES_H
#define PRIMES_PRIMES_H
#include <bitset>
#include <vector>

class Iterator;

class Primes {
private:
    const uint32_t BITSET_SIZE = 1024 * 1024;
    std::vector<uint32_t> data;
public:
    //if you wan't to find primes to max Primes(max, 1), if cnt primes thew Primes(cnt, 0)
    Primes(uint32_t max, bool is_max);

    uint32_t size();
    Iterator begin();
    Iterator end();
    uint32_t operator[](uint32_t index);

    friend class Iterator;
};

class Iterator : public std::iterator<std::input_iterator_tag, uint32_t> {
    private:
    uint32_t index;
    Primes *primes;
public:
    Iterator(Primes *primes, int index);

    bool operator!=(Iterator const& other) const;
    bool operator==(Iterator const& other) const;
    Iterator::reference operator*() const;
    Iterator& operator++();
    Iterator& operator--();
};

#endif //PRIMES_PRIMES_H
