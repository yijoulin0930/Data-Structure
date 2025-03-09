#include "Vector.h"

//TODO: constructor
Vector::Vector() {}
Vector::Vector(float _x, float _y, float _z) {}
 
Vector Vector::operator+(Vector v)
{
	//TODO: Overload the plus operator +.
	//Then we can use more intuitively way to add our vector (like v1 + v2).
	//Return the result of v1 + v2
	
}

Vector Vector::operator-(Vector v)
{
	//TODO: Overload the subtract operator -.
	//Then we can use more intuitively way to subtract out vector (like v1 - v2).
	//Return the result of v1 - v2
	
}


float Vector::operator*(Vector v)
{
	//TODO: Overload the operator * as dot product.
	//Return the dot product result of two vector
	
}

Vector Vector::operator/(Vector v)
{
	//TODO: Overload the operator / as cross product.
	//Return the cross product result of v1 / v2
	
}

Vector Vector::operator-()
{
	//TODO: Overload the negate operator -.
	//Then we can use more intuitively way to negate a vector -v1.
	//Return the result of -v1
	
}

bool Vector::operator>(Vector v) {
	//TODO: Overload the ">" operator.
	//Then we can use more intuitively way to
	//compare the length from the original point(0,0,0) of two vectors (v1 > v2).
	//Return true if the length of v1 is greater than that of v2, return false otherwise. 

}


ifstream& operator>>(ifstream& in, Vector& v)
{
	//TODO: Overload the >> operator.
	//Read the input.txt file and store vector in v

}

ostream& operator<<(ostream& out, const Vector& v)
{
	//TODO: Overload the << operator.
	//Output the vector v

}
