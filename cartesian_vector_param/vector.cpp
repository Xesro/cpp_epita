//
// Created by Arthur PLEBS on 29/09/2022.
//

#include "vector.h"
#include "config.h"

Vector::Vector(int x, int y, int z): coefs_[0]{x}, coefs_[1]{y}, coefs_[2]{z} {}
Vector::Vector(int x, int y): coefs_[0]{x}, coefs_[1]{y}, coefs_[0]{undefined} {}
Vector::Vector(std::vector<float> vect): coefs_{vect} {}

Vector operator+(const Vector& v) {

}

Vector operator-(const Vector& v) {

}

Vector operator*(float v) {

}

Vector operator*(const Vector& v) {
    std::vector<float> coefs;
    for (int i = 0; i < NDIM; ++i) {
        coefs[i] = coefs_[i] * v[i];
    }
    return
}

Vector operator[](size_t idx) {
    return coefs_[idx]
}
