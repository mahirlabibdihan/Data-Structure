#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float determinant() {
		return sqrt(x * x + y * y + z * z);
	}

	Vector unit() {
		int r = determinant();
		return Vector(this->x / r, this->y / r, this->z / r);
	}

	Vector operator^(int v) {
		return *this;
	}

	Vector operator+(const Vector& v) {
		return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
	}

	Vector operator-(const Vector& v) {
		return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
	}

	Vector operator*(const Vector& v) {
		return Vector(this->x * v.x, this->y * v.y, this->z * v.z);
	}

	Vector operator*(int n) {
		return Vector(this->x * n, this->y * n, this->z * n);
	}

	Vector operator^(const Vector& v) {
		return Vector(
		           this->y * v.z - this->z * v.y,
		           this->z * v.x - this->x * v.z,
		           this->x * v.y - this->y * v.x
		       );
	}

	Vector operator/(int n) {
		return Vector(this->x / n, this->y / n, this->z / n);
	}

	friend Vector operator*(int n, const Vector &v);
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector &v);
};

Vector operator*(int n, const Vector &v) {
	return Vector(v.x + v.x, v.y + v.y, v.z + v.z);
}
ostream& operator<<(ostream& out, const Vector& v) {
	out << "(" << v.x << "," << v.y << "," << v.z << ")" << endl;
	return out;
}

istream& operator>>(istream& in, Vector &v) {
	in >> v.x >> v.y >> v.z;
	return in;
}

int main() {

}