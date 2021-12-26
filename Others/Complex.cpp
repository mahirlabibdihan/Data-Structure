#include <iostream>
using namespace std;
class Complex
{
private:
	float real, imag;

public:
	Complex(float real, float imag)
	{
		this->real = real;
		this->imag = imag;
	}
	Complex operator+(const Complex &c)
	{
		return Complex(this->real + c.real, this->imag + c.imag);
	}
	Complex operator-(const Complex &c)
	{
		return Complex(this->real - c.real, this->imag - c.imag);
	}
	Complex operator*(const Complex &c)
	{
		return Complex(
			this->real * c.real - this->imag * c.imag,
			this->real * c.imag + this->imag * c.real);
	}
	Complex operator/(const Complex &c)
	{
		float z = (c.real * c.real) + (c.imag * c.imag);
		return Complex(
			(this->real * c.real + this->imag * c.imag) / z,
			(this->imag * c.real - this->real * c.imag) / z);
	}
	Complex operator+(float n)
	{
		return Complex(this->real + n, this->imag);
	}
	Complex operator-(float n)
	{
		return Complex(this->real - n, this->imag);
	}
	Complex operator*(float n)
	{
		return Complex(this->real * n, this->imag * n);
	}
	Complex operator/(float n)
	{
		return Complex(this->real / n, this->imag / n);
	}
	friend Complex operator+(float n, const Complex &v);
	friend Complex operator-(float n, const Complex &v);
	friend Complex operator*(float n, const Complex &v);
	friend Complex operator/(float n, const Complex &v);
	friend ostream &operator<<(ostream &out, const Complex &v);
	friend istream &operator>>(istream &in, Complex &v);
};

Complex operator+(float n, const Complex &c)
{
	return Complex(c.real + n, c.imag);
}
Complex operator-(float n, const Complex &c)
{
	return Complex(c.real - n, c.imag);
}
Complex operator*(float n, const Complex &c)
{
	return Complex(c.real * n, c.imag * n);
}
Complex operator/(float n, const Complex &c)
{
	return Complex(c.real / n, c.imag / n);
}
ostream &operator<<(ostream &out, const Complex &c)
{
	out << "(" << c.real << "," << c.imag << ")" << endl;
	return out;
}

istream &operator>>(istream &in, Complex &c)
{
	in >> c.real >> c.imag;
	return in;
}

int main()
{
}