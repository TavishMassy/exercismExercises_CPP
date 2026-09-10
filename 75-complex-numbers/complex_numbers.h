#pragma once
#include <cmath>

namespace complex_numbers {

// TODO: add your solution here
class Complex{
    private:
    double _real;
    double _imag;

    public:
    Complex(double real, double imag) : _real(real), _imag(imag) {}
    double real() const { return _real; }
    double imag() const { return _imag; }

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    double abs() const;
    Complex conj() const; 
    Complex exp() const;
    
    Complex operator+(double other) const { return Complex{_real + other, _imag}; }
    Complex operator-(double other) const { return Complex{_real - other, _imag}; }
    Complex operator*(double other) const { return Complex{_real * other, _imag * other}; }
    Complex operator/(double other) const { return Complex{_real / other, _imag / other}; }
};

inline Complex operator+(double lhs, const Complex& rhs) { return Complex{lhs + rhs.real(), rhs.imag()}; }
inline Complex operator-(double lhs, const Complex& rhs) { return Complex{lhs - rhs.real(), - rhs.imag()}; }
inline Complex operator*(double lhs, const Complex& rhs) { return Complex{lhs * rhs.real(), lhs * rhs.imag()}; }
inline Complex operator/(double lhs, const Complex& rhs) {
    double denom{(rhs.real() * rhs.real() + rhs.imag() * rhs.imag())};
    return Complex{ (lhs * rhs.real()) / denom,
                   -(lhs * rhs.imag()) / denom}; 
}

}  // namespace complex_numbers
