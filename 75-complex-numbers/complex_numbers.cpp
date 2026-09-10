#include "complex_numbers.h"

namespace complex_numbers {

// TODO: add your solution here
Complex Complex::operator+(const Complex& other) const {
    return Complex{_real + other.real(), _imag + other.imag()};
}

Complex Complex::operator-(const Complex& other) const {
    return Complex{_real - other.real(), _imag - other.imag()};
}

Complex Complex::operator*(const Complex& other) const {
    return Complex{(_real * other.real()) - (_imag * other.imag()), other.real() * other.imag() - _real * _imag};
}

Complex Complex::operator/(const Complex& other) const {
    double denom{(other.real() * other.real() + other.imag() * other.imag())};
    return Complex{(_real * other.real() + _imag * other.imag()) / denom,
                   (_imag * other.real() - _real * other.imag()) / denom};
}

double Complex::abs() const {
    return std::sqrt(_real * _real + _imag * _imag);
}

Complex Complex::conj() const {
    return Complex{_real, -_imag};
}

Complex Complex::exp() const { 
    return Complex{std::exp(_real) * std::cos(_imag), std::exp(_real) * std::sin(_imag)};
}

}  // namespace complex_numbers

