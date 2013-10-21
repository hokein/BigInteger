#include "BigInteger.h"

BigInteger::BigInteger() {
}

BigInteger::BigInteger(const string& s):num(s) {
}

BigInteger::BigInteger(const char* s):num(s) {
}

const string& BigInteger::value() const {
  return num;
}

bool operator<(const BigInteger& x, const BigInteger& y) {
  if (x.value().size() == y.value().size())
    return x.value() < y.value();
  return x.value().size() < y.value().size();
}

bool operator==(const BigInteger& x, const BigInteger& y) {
  return x.value() == y.value();
}

BigInteger operator+(const BigInteger& x, const BigInteger& y) {
  string a(x.value().rbegin(), x.value().rend());
  string b(y.value().rbegin(), y.value().rend()); 
  string res = "";
  int i = 0, add_digit = 0;
  while (i < a.size() || i < b.size()) {
    int sum = 0;
    if (i >= a.size())
      sum = b[i]-'0'+add_digit;
    else if (i >= b.size())
      sum = a[i]-'0'+add_digit;
    else
      sum = a[i]-'0'+b[i]-'0'+add_digit;
    res += string(1, sum%10+'0');
    add_digit = sum/10;
    ++i;
  }
  if (add_digit)
    res += string(1, '0'+add_digit);
  return BigInteger(string(res.rbegin(), res.rend())); 
}

BigInteger operator-(const BigInteger& x, const BigInteger& y) {
  string a(x.value().rbegin(), x.value().rend());
  string b(y.value().rbegin(), y.value().rend()); 
  string res = "";
  int i = 0, minus_digit = 0;
  while (i < a.size() || i < b.size()) {
    int diff = 0;
    if (i >= a.size())
      diff = b[i]-'0'-minus_digit;
    else if (i >= b.size())
      diff = a[i]-'0'-minus_digit;
    else 
      diff = a[i]-'0'-(b[i]-'0')-minus_digit;
    minus_digit = 0;
    if (diff < 0) {
      diff += 10;
      minus_digit = 1;
    }
    res += string(1, diff%10+'0');
    ++i;
  }
  // remove prefix '0'.
  string::reverse_iterator it = res.rbegin();
  while ((res.rend()-it) > 1 && *it == '0')
    ++it;
  return BigInteger(string(it, res.rend())); 
}

BigInteger operator*(const BigInteger& x, const BigInteger& y) {
  BigInteger res("");
  string b = y.value();
  for (int i = 0; i < b.size(); ++i) {
    res = BigInteger(res.value()+"0");
    int add_times = b[i]-'0';
    while (add_times--) {
      res = res+x;  
    }
  }
  string::const_iterator it = res.value().begin();
  while (res.value().end()-it > 1 && *it == '0')
    ++it;
  return BigInteger(string(it, res.value().end()));
}

BigInteger operator/(const BigInteger& x, const BigInteger& y) {
  BigInteger divid;
  string b = x.value();
  string res;
  for (int i = 0; i < b.size(); ++i) {
    divid = BigInteger(divid.value()+string(1, b[i]));
    int times = 0;
    while (!(divid < y)) {
      ++times;
      divid = (divid-y);
    }
    res += string(1, times+'0');
  }
  string::iterator it = res.begin();
  while (res.end()-it > 1 && *it == '0')
    ++it;
  return BigInteger(string(it, res.end()));
}
