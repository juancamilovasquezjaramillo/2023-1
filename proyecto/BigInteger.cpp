#include "BigInteger.h"

//Esta implementación recorre cada carácter de la cadena 'numberString' y
//convierte cada dígito a su valor entero correspondiente, almacenando los dígitos en el vector digits.
BigInteger::BigInteger(std::string numberString) {
    for (size_t i = 0; i < numberString.length(); i++) {
        char digit = numberString[i];
        int value = digit - '0';
        digits.push_back(value);
    }
}



//Esta función constructora toma como parámetro otra instancia de BigInteger (other)
// y copia los dígitos de esa instancia en el objeto que se está creando.

BigInteger::BigInteger(BigInteger& other) {
    digits = other.digits;
}



//Esta operación "add" suma los dígitos de dos BigInteger y
//los almacena en un nuevo objeto BigInteger,
//teniendo en cuenta el acarreo en caso de que la suma supere el valor de 9 en algún dígito.


BigInteger BigInteger::add(BigInteger& other){
    BigInteger result;
    std::vector<int> sum;
    int carry = 0;
    int maxDigits = std::max(digits.size(), other.digits.size());

    for (int i = 0; i < maxDigits; i++) {
        int digitSum = carry;

        if (i < digits.size())
            digitSum += digits[i];

        if (i < other.digits.size())
            digitSum += other.digits[i];

        sum.push_back(digitSum % 10);
        carry = digitSum / 10;
    }

    if (carry > 0)
        sum.push_back(carry);

    result.digits = sum;
    return result;
}
