#include "BigInteger.h"


BigInteger::BigInteger(const std::string& numberString) {
    for (char c : numberString) {
        if ((c)) {
            digits.push_back(c - '0');
        }
    }
}

BigInteger::BigInteger(const BigInteger& other) {
    digits = other.digits;
}

// aun me falta implementar mas detalles
