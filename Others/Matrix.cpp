#include<iostream>
#include<iomanip>
using namespace std;
class Matrix {
private:
	int r, c;
	float** mat;
public:
	Matrix(int r, int c) {
		this->r = r;
		this->c = c;
		mat = new float*[r];
		for (int i = 0; i < r; i++) {
			mat[i] = new float[c];
			for (int j = 0; j < c; j++) {
				mat[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& m) {
		this->r = m.r;
		this->c = m.c;
		mat = new float*[r];
		for (int i = 0; i < r; i++) {
			mat[i] = new float[c];
			for (int j = 0; j < c; j++) {
				mat[i][j] = m.mat[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& m) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				mat[i][j] = m.mat[i][j];
			}
		}
		return *this;
	}

	// float determinant() {
	// 	return 0;
	// }

	float& operator()(int r, int c) {
		return mat[r][c];
	}

	// Matrix inverse() {
	// 	return *this;
	// }

	Matrix transpose() {
		Matrix temp(this->r, this->c);
		for (int i = 0; i < this->r; i++)
		{
			for (int j = 0; j < this->c; j++)
			{
				temp(j, i) = this->mat[i][j];
			}
		}
		return temp;
	}


	// Matrix operator^(int m) {
	// 	return *this;
	// }

	Matrix operator+(const Matrix& m) {
		if (this->r != m.r || this->c != m.c) throw "Can't be added";
		Matrix temp(this->r, this->c);
		for (int i = 0; i < m.r; i++)
		{
			for (int j = 0; j < m.c; j++)
			{
				temp(i, j) = mat[i][j] + m.mat[i][j];
			}
		}
		return temp;
	}

	Matrix operator-(const Matrix& m) {
		if (this->r != m.r || this->c != m.c) throw "Can't be substracted";
		Matrix temp(this->r, this->c);
		for (int i = 0; i < m.r; i++)
		{
			for (int j = 0; j < m.c; j++)
			{
				temp(i, j) = mat[i][j] - m.mat[i][j];
			}
		}
		return temp;
	}

	Matrix operator*(const Matrix& m) {
		if (this->c != m.r) throw "Can't be multiplied";
		Matrix temp(this->r, this->c);

		for (int i = 0; i < this->r; i++)
		{
			for (int j = 0; j < m.c; j++)
			{
				temp(i, j) = 0;
				for (int k = 0; k < this->c; k++)
				{
					temp(i, j) += (this->mat[i][k] * m.mat[k][j]);
				}
			}
		}
		return temp;
	}

	Matrix operator*(int n) {
		Matrix temp(this->r, this->c);
		for (int i = 0; i < this->r; i++)
		{
			for (int j = 0; j < this->c; j++)
			{
				temp(i, j) = mat[i][j] * n;
			}
		}
		return temp;
	}

	Matrix operator/(int n) {
		Matrix temp(this->r, this->c);
		for (int i = 0; i < this->r; i++)
		{
			for (int j = 0; j < this->c; j++)
			{
				temp(i, j) = mat[i][j] / n;
			}
		}
		return temp;
	}

	friend ostream& operator<<(ostream& out, const Matrix &m);
	friend istream& operator>>(istream& in, Matrix &m);
};

ostream& operator<<(ostream& out,const Matrix &m) {
	for (int i = 0; i < m.r; i++)
	{
		out << endl;
		for (int j = 0; j < m.c; j++)
		{
			// out << setw(10) << setprecision(4) << m(i, j);
			// printf("%10.4g ", m.mat[i][j]);
			out << setw(10) << setprecision(4) << m.mat[i][j];
		}
		out << endl;
	}
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Matrix &m) {
	for (int i = 0; i < m.r; i++)
	{
		for (int j = 0; j < m.c; j++)
		{
			in >> m(i, j);
		}
	}
	return in;
}

class Command {

};

int main() {
	Matrix a(3, 3), b(3, 2);
	// cin>>a;
	// cin>>b;
	try {
		cout << a + b;
	}
	catch (const char* msg) {
		cerr << "ERROR: " << msg << endl;
	}

}