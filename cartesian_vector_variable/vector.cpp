//
// Created by Arthur Plebs on 26/10/2022.
//

#include "vector.h"

Vector::Vector(const Vector& v)
{
    _size = v.size();
    data = std::make_unique<value[]>(_size);
    for (int i = 0; i < _size; i++) {
        data[i] = v[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    _size = v.size();
    data = std::make_unique<value[]>(_size);
    for (int i = 0; i < _size; i++) {
        data[i] = v[i];
    }
    return *this;
}

Vector::Vector(size_t N)
{
    _size = N;
    data = std::make_unique<value[]>(N);
    for(size_t i = 0; i < N; i++) {
        data[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l)
{
    _size = l.size();
    data = std::make_unique<value[]>(_size);
    int i = 0;
    for(auto& val : l)
    {
        data[i++] = val;
    }
}

size_t Vector::size() const
{
    return _size;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    if (_size != rhs.size())
        throw std::runtime_error("Incompatible size");

    for (int i = 0; i < rhs.size(); i++)
        data[i] += rhs[i];
    return *this;
}



Vector& Vector::operator-=(const Vector& rhs)
{
    if (_size != rhs.size())
        throw std::runtime_error("Incompatible size");

    for (int i = 0; i < rhs.size(); i++)
        data[i] -= rhs[i];
    return *this;
}

Vector& Vector::operator+=(value v)
{
    for (int i = 0; i < _size; i++)
        data[i] += v;
    return *this;
}

Vector& Vector::operator*=(value v)
{
    for (int i = 0; i < _size; i++)
        data[i] *= v;
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    if (_size != rhs.size())
        throw std::runtime_error("Incompatible size");

    auto v = Vector(_size);
    for (int i = 0; i < rhs.size(); i++)
        v[i] = rhs[i] + data[i];
    return v;
}

Vector Vector::operator+(value v) const
{
    auto vect = Vector(_size);
    for (int i = 0; i < _size; i++)
        vect[i] = data[i] + v;
    return vect;
}

//Vector Vector::operator-(const Vector& rhs) const
//{
//    auto v = Vector(_size);
//    for (int i = 0; i < rhs.size(); i++)
//        v[i] = rhs[i] - data[i];
//    return v;
//}

value Vector::operator*(const Vector& rhs) const
{
    if (_size != rhs.size())
        throw std::runtime_error("Incompatible size");

    value v = 0;
    for (int i = 0; i < rhs.size(); i++)
        v += rhs[i] * data[i];
    return v;
}

Vector Vector::operator*(value v) const
{
    auto vect = Vector(_size);
    for (int i = 0; i < _size; i++)
        data[i] *= v;
    return vect;
}

value Vector::operator[](size_t i) const
{
    return data[i];
}

value& Vector::operator[](size_t i)
{
    return data[i];
}

Vector operator*(const value& s, const Vector& v)
{
    auto vect = Vector(v.size());
    for (int i = 0; i < v.size(); i++)
        vect[i] = v[i] * s;
    return vect;
}

Vector operator*=(const value& s, const Vector& v)
{
    auto vect = Vector(v.size());
    for (int i = 0; i < v.size(); i++)
        vect[i] = v[i] * s;
    return vect;
}


//Vector operator+=(Vector& rhs, const value a)
//{
//    for (int i = 0; i < rhs.size(); i++)
//        rhs[i] += a;
//    return rhs;
//}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.size(); i++)
        os << rhs[i] << (i == rhs.size() - 1 ? "" : ",");
    return os << "}";
}
