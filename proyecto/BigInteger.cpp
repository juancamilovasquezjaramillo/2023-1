#include "BigInteger.h"


BigInteger::BigInteger(std::string& numberString) {
    for (char c : numberString) {
        if ((c)) {
            digits.push_back(c - '0');
        }
    }
}

BigInteger::BigInteger(BigInteger& other) {
    digits = other.digits;
}
