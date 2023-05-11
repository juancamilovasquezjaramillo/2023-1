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
    
    BigInteger add(const BigInteger& other) const;
    BigInteger product(const BigInteger& other) const;
    BigInteger subtract(const BigInteger& other) const;
    BigInteger quotient(const BigInteger& other) const;
    BigInteger remainder(const BigInteger& other) const;
    BigInteger pow(const BigInteger& exponent) const;

    std::string toString() const;

    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
    BigInteger operator*(const BigInteger& other) const;
    BigInteger operator/(const BigInteger& other) const;
    BigInteger operator%(const BigInteger& other) const;
    bool operator==(const BigInteger& other) const;
    bool operator<(const BigInteger& other) const;
    bool operator<=(const BigInteger& other) const;

    static BigInteger sumarListaValores(const std::vector<BigInteger>& values);
    static BigInteger multiplicarListaValores(const std::vector<BigInteger>& values);

private:
    std::vector<int> digits_;

    void normalize();
};

#endif

};

#endif
