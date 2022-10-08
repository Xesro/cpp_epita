#pragma once

#include <ostream>
#include <vector>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

    Vector(int x, int y, int z);
    Vector(int x, int y);
    Vector(std::vector<float> vect);

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    // More to go

private:
    std::vector<float> coefs_[NDIM];
// Private Member functions here

// Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here