/**
\file
\brief Test for Primes
 */

#include "../Primes.h"
#include <gtest/gtest.h>

TEST(Primes, begin_test) {
    Primes &primes = *new Primes(1000, true);
    Iterator &it = primes.begin();
    ASSERT_TRUE(*it == 2);
}

TEST(Primes, end_test) {
    Primes &primes = *new Primes(1, false);
    Iterator &it = primes.end();
    it--;
    ASSERT_TRUE(*it == 2);
}

TEST(Primes, contains_all_primes_iterator) {
    Primes &primes = *new Primes(1000, true);
    Iterator &it = primes.begin();
    for(int i = 2; i <= 1000; i++) {
        bool is_prime = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                is_prime = false;
            }
        }
        if(is_prime) {
            ASSERT_TRUE(i == *it);
            it++;
        }
    }
}

TEST(Primes, contains_all_primes_iterator_cnt) {
    Primes &primes = *new Primes(1000, false);
    Iterator &it = primes.begin();
    int cnt = 0;
    for(int i = 2; i <= 10000; i++) {
        bool is_prime = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                is_prime = false;
            }
        }
        if(is_prime) {
            cnt++;
            ASSERT_TRUE(i == *it);
            it++;
            if(cnt == 1000) {
                break;
            }
        }
    }
}

TEST(Primes, contains_all_primes) {
    Primes &primes = *new Primes(1000, true);
    int index = 0;
    for(int i = 2; i <= 1000; i++) {
        bool is_prime = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                is_prime = false;
            }
        }
        if(is_prime) {
            ASSERT_TRUE(i == primes[index]);
            index++;
        }
    }
}

TEST(Primes, contains_all_primes_cnt) {
    Primes &primes = *new Primes(1000, false);
    int cnt = 0;
    for(int i = 2; i <= 10000; i++) {
        bool is_prime = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                is_prime = false;
            }
        }
        if(is_prime) {
            ASSERT_TRUE(i == primes[cnt]);
            cnt++;
            if(cnt == 1000) {
                break;
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}