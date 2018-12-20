#include "Vector3.h"
#include <math.h>

float Vector3::Dot(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y;
}

Vector3 Vector3::Project(const Vector3& a, const Vector3& b) {
	return Vector3(	(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.x,
					(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.y,
					0);
}

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3::Vector3(float _x) {
	x = _x;
	y = _x;
	z = _x;
}

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector3& Vector3::operator=(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& other) {
	Vector3 res;

	res.x = x + other.x;
	res.y = y + other.y;
	res.z = z + other.z;

	return res;
}

Vector3 Vector3::operator-(const Vector3& other) {
	Vector3 res;

	res.x = x - other.x;
	res.y = y - other.y;
	res.z = z - other.z;

	return res;
}

Vector3 Vector3::operator*(const Vector3& other) {
	Vector3 res;

	res.x = x * other.x;
	res.y = y * other.y;
	res.z = z * other.z;

	return res;
}

Vector3 Vector3::operator*(float _x) {
	Vector3 res;

	res.x = x * _x;
	res.y = y * _x;
	res.z = z * _x;

	return res;
}

bool Vector3::operator==(const Vector3& other) {
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other) {
	return !(x == other.x && y == other.y && z == other.z);
}