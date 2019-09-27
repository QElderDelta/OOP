#ifndef _MODULO_H_
#define _MODULO_H_


#include <iostream>


class Modulo {
    public:
        Modulo() : number(0), mod(0) {}
        Modulo(int number, int mod) : number(number < 0 ? mod + (number % mod) : number), mod(mod) {}
        friend Modulo operator+(const Modulo& lhs, const Modulo& rhs);
        friend Modulo operator*(const Modulo& lhs, const Modulo& rhs);
        friend Modulo operator-(const Modulo& lhs, const Modulo& rhs);
        friend Modulo operator/(const Modulo& lhs, const Modulo& rhs);
        friend std::istream& operator>>(std::istream& is, Modulo& mod);
        friend std::ostream& operator<<(std::ostream& os, const Modulo& mod);
        void SetNumber(int number);
        void SetMod(int mod);
        int GetNumber() const;
        int GetMod() const;
        friend bool operator==(const Modulo& lhs, const Modulo& rhs);
        friend bool operator>(const Modulo& lhs, const Modulo& rhs);
        friend bool operator<(const Modulo& lhs, const Modulo& rhs);
    private:
        int number;
        int mod;
};

#endif
