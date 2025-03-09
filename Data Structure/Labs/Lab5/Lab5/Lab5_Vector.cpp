#include "Lab5_Vector.h"
#include<vector>

//TODO: constructor
Vector::Vector() : x(0),y(0),z(0) {}
Vector::Vector(float _x, float _y, float _z) :x(_x),y(_y),z(_z) {}

Vector Vector::operator+(Vector v)
{
	//TODO: Overload the plus operator +.
	//Then we can use more intuitively way to add our vector (like v1 + v2).
	//Return the result of v1 + v2
	
	return { x+v.x,y+v.y,z+v.z };

}

Vector Vector::operator-(Vector v)
{
	//TODO: Overload the subtract operator -.
	//Then we can use more intuitively way to subtract out vector (like v1 - v2).
	//Return the result of v1 - v2

	return{ x - v.x, y - v.y, z - v.z };
}


float Vector::operator*(Vector v)
{
	//TODO: Overload the operator * as dot product.
	//Return the dot product result of two vector

	return{ x * v.x+ y * v.y+ z * v.z };
}

Vector Vector::operator/(Vector v)
{
	//TODO: Overload the operator / as cross product.
	//Return the cross product result of v1 / v2

	return{ (y*v.z-z*v.y),(z * v.x - x * v.z),(x * v.y - y * v.x)};
}

Vector Vector::operator-()
{
	//TODO: Overload the negate operator -.
	//Then we can use more intuitively way to negate a vector -v1.
	//Return the result of -v1

	return { -x,-y,-z };

}

bool Vector::operator>(Vector v) {
	//TODO: Overload the ">" operator.
	//Then we can use more intuitively way to
	//compare the length from the original point(0,0,0) of two vectors (v1 > v2).
	//Return true if the length of v1 is greater than that of v2, return false otherwise. 

	if (x * x + y * y + z * z > v.x * v.x + v.y * v.y + v.z * v.z)
		return 1;
	else
		return 0;
}


ifstream& operator>>(ifstream& in, Vector& v)
{
	//TODO: Overload the >> operator.
	//Read the input.txt file and store vector in v

	in >> v.x >> v.y >> v.z;

	return in;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	//TODO: Overload the << operator.
	//Output the vector v

	out << "(" << v.x << " , " << v.y << " , " << v.z << ")" ;

	return out;
}