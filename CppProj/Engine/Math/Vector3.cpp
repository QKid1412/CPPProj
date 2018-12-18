#include "Vector3.h";

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