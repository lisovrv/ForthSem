#include "Vector2.h"

/**-----------------------------------------------------------------------------------------------------
 * -------------------------------------------CTORS AND DTOR--------------------------------------------
 * -----------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------*/

Vector2::Vector2()
{
    _coordinate_x = 0;
    _coordinate_y = 0;
}

Vector2::~Vector2()
{
    _coordinate_x = _poison_;
    _coordinate_y = _poison_;
}

Vector2::Vector2(const float& x, const float& y)
{
    _coordinate_x = x;
    _coordinate_y = y;
}

/*Vector2& Vector2::operator=(const Vector2& other)
{
    return Vector2(other._coordinate_x, other._coordinate_y);
}

Vector2::Vector2(const Vector2& other)
{
    return Vector2(other._coordinate_x, other._coordinate_y);
}*/



/**-----------------------------------------------------------------------------------------------------
 * -------------------------------------------MATHS-----------------------------------------------------
 * -----------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------*/


float Vector2::Get_Length() const
{
    return (float) sqrt(_coordinate_x * _coordinate_x + _coordinate_y * _coordinate_y);
    
}

Vector2 Vector2::Get_Normalized() const
{
    return Vector2(_coordinate_x / Get_Length(), _coordinate_y / Get_Length());
}


Vector2 Vector2::Get_Orthogonal() const
{
    return Vector2(_coordinate_y, -_coordinate_x);
}

Vector2 & Vector2::Rotate(float angle)
{
    _coordinate_x = (float)(_coordinate_x * cos(angle) - _coordinate_y * sin(angle));
    _coordinate_y = (float)(_coordinate_x * sin(angle) + _coordinate_y * cos(angle));
    return *this;
}

Vector2 Vector2::Get_Rotated(float angle) const
{
    return Vector2((_coordinate_x * cos(angle) - _coordinate_y * sin(angle)),
                   (_coordinate_x * sin(angle) + _coordinate_y * cos(angle)));
}

const float Vector2::GetX() const
{
    return _coordinate_x;
}
const float Vector2::GetY() const
{
    return _coordinate_y;
}

float & Vector2::GetRX()
{
    return _coordinate_x;
}
float & Vector2::GetRY()
{
    return _coordinate_y;
}



/**-----------------------------------------------------------------------------------------------------
 * -------------------------------------------OPERATORS-------------------------------------------------
 * -----------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------*/

std::ostream & operator<<(std::ostream& stream, const Vector2& v)
{
    return stream << v.GetX() << " " << v.GetY();
}

std::istream & operator>>(std::istream& stream, Vector2& v)
{
    return stream >> v.GetRX() >> v.GetRY();
}


/**-----------------------------------------------------------------------------------------------------
 * -------------------------------------------MATH_OPERATORS--------------------------------------------
 * -----------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------*/

float Vector2::operator*(const Vector2 & other) const
{
    return _coordinate_x * other._coordinate_x + _coordinate_y * other._coordinate_y;
}

float Vector2::operator^(const Vector2 & other) const
{
    return fabs(_coordinate_x * other._coordinate_y - _coordinate_y * other._coordinate_x);
}

Vector2 Vector2::operator+(const Vector2 & other) const
{
    return Vector2(_coordinate_x + other._coordinate_x, _coordinate_y + other._coordinate_y);
}

Vector2 Vector2::operator-(const Vector2 & other) const
{
    return Vector2(_coordinate_x - other._coordinate_x, _coordinate_y - other._coordinate_y);
}

Vector2 Vector2::operator-() const
{
    return Vector2(-_coordinate_x, -_coordinate_y);
}

Vector2 & Vector2::operator+=(const Vector2 & other)
{
    _coordinate_x += other._coordinate_x;
    _coordinate_y += other._coordinate_y;
    return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & other)
{
    _coordinate_x -= other._coordinate_x;
    _coordinate_y -= other._coordinate_y;
    return *this;
}

Vector2 Vector2::operator*(float k)
{
    return Vector2((GetX()) * k, (GetY()) * k);
}

Vector2 operator*(float k, const Vector2 & v)
{
    return Vector2((v.GetX()) * k, (v.GetY()) * k);
}

Vector2 Vector2::operator/(float k)
{
    return Vector2((GetX()) / k, (GetY()) / k);
}
