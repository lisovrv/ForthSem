#ifndef FORTH_SEM_VECTOR2_H
#define FORTH_SEM_VECTOR2_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

const float _poison_ = NAN;

class Vector2
{
private:
    float _coordinate_x;
    float _coordinate_y;
public:

    explicit Vector2();
    Vector2(const float& x, const float& y);

    //explicit Vector2(const Vector2& other);
    //Vector2& operator=(const Vector2& other);
    ~Vector2();

    float Get_Length() const;
    Vector2 Get_Normalized() const;
    Vector2 Get_Orthogonal() const;
    Vector2& Rotate(float angle);
    Vector2 Get_Rotated(float angle) const;

    const float GetX() const;
    const float GetY() const;
    float & GetRX();
    float & GetRY();

    float operator*(const Vector2& other) const;
    float operator^(const Vector2& other) const;
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator-() const;
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    friend std::ostream & operator<<(std::ostream& stream, const Vector2& v);
    friend std::istream & operator>>(std::istream& stream, Vector2& v);
    Vector2 operator*(float k);
    friend Vector2 operator*(float k, const Vector2& v);
    Vector2 operator/(float k);

};

#endif //FORTH_SEM_VECTOR2_H


