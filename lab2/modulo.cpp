#include <iostream>
#include <cassert>

#include "modulo.hpp"

int ExtendedEuclid(int a, int b, int& x, int& y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = ExtendedEuclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

Modulo operator+(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    Modulo result;
    result.number = (lhs.number % lhs.mod + rhs.number % lhs.mod + lhs.mod) % lhs.mod;
    result.mod = lhs.mod;
    return result;
}

Modulo operator*(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    Modulo result;
    result.number = ((lhs.number % lhs.mod) * (rhs.number % lhs.mod) + lhs.mod) % lhs.mod;
    result.mod = lhs.mod;
    return result;
}

Modulo operator-(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    Modulo result;
    result.number = (lhs.number % lhs.mod - rhs.number % lhs.mod + lhs.mod) % lhs.mod;
    result.mod = lhs.mod;
    return result;
}

Modulo operator/(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    int x, y;
    if(ExtendedEuclid(rhs.number, lhs.mod, x, y) != 1) {
        std::cerr << "Divisor and aren't coprime, therefore division can't be made" << std::endl;
        return {lhs.number, 0};
    }
    Modulo result;
    int ModInverse = (x % lhs.mod + lhs.mod) % lhs.mod;
    result.number = (lhs.number * ModInverse) % lhs.mod;
    result.mod = lhs.mod;
    return result;
}

std::istream& operator>>(std::istream& is, Modulo& m) {
    is >> m.number >> m.mod;
    if(m.number % m.mod >= 0) {
        m.number %= m.mod;
    } else {
        m.number = m.mod + (m.number % m.mod);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Modulo& m) {
    os << m.number << " mod " << m.mod;
    return os;
}

void Modulo::SetNumber(int number) {
    this->number = number;
}

void Modulo::SetMod(int mod) {
    this->mod = mod;
}

int Modulo::GetNumber() const {
    return number;
}

int Modulo::GetMod() const {
    return mod;
}

bool operator==(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    return lhs.number == rhs.number;
}

bool operator>(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    return lhs.number > rhs.number;
}

bool operator<(const Modulo& lhs, const Modulo& rhs) {
    assert(lhs.mod == rhs.mod);
    return lhs.number < rhs.number;
}
