#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>

class BigInteger {
private:
    std::vector<int> digits;

public:
    BigInteger(const std::string& numberString);
    BigInteger(const BigInteger& other);

};

#endif
