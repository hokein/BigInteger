#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>

using std::string;

// Big positive integer in C++ just like BigInteger in Java. 
// Supports arbitrary-precision positive integers operators: +,-,*,/
// Usage:
//   BigInteger a = "123";
//   BigInteger b = "1111";
//   BigInteger c = a+b;
class BigInteger {
 public:
  BigInteger(); 
  BigInteger(const string& s);
  BigInteger(const char* s);
  const string& value() const; 

  friend bool operator<(const BigInteger& x, const BigInteger& y);
  friend bool operator==(const BigInteger& x, const BigInteger& y);
  friend BigInteger operator+(const BigInteger& x, const BigInteger& y);
  // Only supports x >= y, 
  friend BigInteger operator-(const BigInteger& x, const BigInteger& y);
  friend BigInteger operator*(const BigInteger& x, const BigInteger& y);
  friend BigInteger operator/(const BigInteger& x, const BigInteger& y); 

 private:
  string num;
};

#endif // BIGINTEGER_H 
