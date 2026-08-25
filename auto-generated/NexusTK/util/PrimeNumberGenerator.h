// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MQ
// Source by-file doc: by-file/PrimeNumberGenerator.md
// UID:0000AT | by-class/PrimeNumberGenerator.md | Completion:93 | Confidence:92
#ifndef NEXUSTK_UTIL_PRIMENUMBERGENERATOR_H
#define NEXUSTK_UTIL_PRIMENUMBERGENERATOR_H

#include <deque>

class PrimeNumberGenerator
{
public:
    explicit PrimeNumberGenerator(int limit);
    virtual ~PrimeNumberGenerator();

    int GetPrimeAt(int index) const;

private:
    unsigned int *m_sieveBits;
    std::deque<int> m_primes;
};

#endif
