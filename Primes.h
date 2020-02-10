/**
\file
\brief Header with description of Primes and his Iterator

Description of Primes and his Iterator
*/

#ifndef PRIMES_PRIMES_H
#define PRIMES_PRIMES_H

#include <bitset>
#include <vector>

class Iterator;

/// Container of primes
class Primes {
private:
    /// size of bitset to Eratosthenes algorithm
    const uint32_t BITSET_SIZE = 1024 * 1024;
    std::vector<uint32_t> data;
public:
    /** if you wan't to find primes to max Primes(max, 1), if cnt primes then  Primes(cnt, 0)
     * \param[in] max it's max of primes in container, if \param[in] is_max
     * else it's cnt of primes in container
     */
    Primes(uint32_t max, bool is_max);
    ///  Get cnt of all primes
    uint32_t size();
    /// Get Iterator to the first prime
    Iterator begin();
    /// Get Iterator to the end of primes
    Iterator end();
    /// Get \param index prime in container
    uint32_t operator[](uint32_t index);

    friend class Iterator;
};

/// Iterator for Primes
class Iterator : public std::iterator<std::input_iterator_tag, uint32_t> {
    private:
    uint32_t index;
    Primes *primes;
public:
    /**
     * Constructor to Iterator
     * @param primes primes of this Iterator
     * @param index index in data of Iterator
     */
    Iterator(Primes *primes, uint32_t index);

    ///Compare two Iterator
    bool operator!=(Iterator const& other) const;
    ///Compare two Iterator
    bool operator==(Iterator const& other) const;
    ///Iterator extraction
    Iterator::reference operator*() const;
    ///Next Iterator
    Iterator& operator++();
    ///Previous Iterator
    Iterator& operator--();
};

#endif //PRIMES_PRIMES_H
