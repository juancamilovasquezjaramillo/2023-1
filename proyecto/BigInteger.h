#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>

class BigInteger {
private:
    std::vector<int> digits;

public:
    BigInteger();
    BigInteger(const std::string& numberString);
    BigInteger(const BigInteger& other);
    
    BigInteger add(BigInteger& other);
    BigInteger product(BigInteger& other);
    BigInteger subtract(BigInteger& other);
    BigInteger quotient(BigInteger& other);
    BigInteger remainder(BigInteger& other);
    BigInteger pow(BigInteger& exponent);

    std::string toString();

    BigInteger operator+(BigInteger& other);
    BigInteger operator-(BigInteger& other);
    BigInteger operator*(BigInteger& other);
    BigInteger operator/(BigInteger& other);
    BigInteger operator%(BigInteger& other);
    bool operator==(BigInteger& other);
    bool operator<(BigInteger& other);
    bool operator<=(BigInteger& other);

    static BigInteger sumarListaValores(std::vector<BigInteger>& values);
    static BigInteger multiplicarListaValores(std::vector<BigInteger>& values);

private:
    std::vector<int> digits_;

    void normalize();
};

#endif


