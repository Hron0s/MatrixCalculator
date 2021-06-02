#include <iostream>
#include <cmath>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
	rows = 0;
	columns = 0;
	matrix = nullptr;
}

Matrix::Matrix(int rows)
{
	this->rows = rows;
	this->columns = rows;
	matrix = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new float[columns];
	}
}

Matrix::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	matrix = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new float[columns];
	}
}

Matrix::~Matrix()
{
	if (this->matrix != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

Matrix::Matrix(const Matrix& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	matrix = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new float[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}


int Matrix::getRows()
{
	return rows;
}

int Matrix::getColumns()
{
	return columns;
}


int Matrix::col_max(int n)
{
	int index = n;
	int max = abs(matrix[n][n]);

	for (int i = n + 1; i < rows; i++)
	{
		if (abs(matrix[i][n]) > max)
		{
			max = abs(matrix[i][n]);
			index = i;
		}
	}
	return index;
}

void Matrix::swapRows(int n1, int n2)
{
	for (int i = 0; i < columns; i++)
	{
		float tmp = matrix[n1][i];
		matrix[n1][i] = matrix[n2][i];
		matrix[n2][i] = tmp;
	}
}


float* Matrix::operator [] (int i)
{
	return matrix[i];
}

Matrix& Matrix::operator = (const Matrix& other)
{
	if (this->matrix != other.matrix)
	{
		if (this->matrix != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		this->rows = other.rows;
		this->columns = other.columns;
		matrix = new float* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new float[columns];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator + (const Matrix& other)
{
	Matrix tmp(this->rows, this->columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			tmp.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::operator - (const Matrix& other)
{
	Matrix tmp(this->rows, this->columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			tmp.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::operator * (const Matrix& other)
{
	Matrix temp(this->rows, other.columns);
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < other.columns; ++j)
		{
			temp[i][j] = 0;
			for (int k = 0; k < this->columns; ++k)
			{
				temp.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	return temp;
}

Matrix Matrix::operator * (float a)
{
	Matrix temp(this->rows, this->columns);
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->columns; ++j)
		{
			temp.matrix[i][j] = (this->matrix[i][j] * a);
		}
	}
	return temp;
}

Matrix Matrix::operator / (float a)
{
	Matrix temp(this->rows, this->columns);
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->columns; ++j)
		{
			temp.matrix[i][j] = (this->matrix[i][j] / a);
		}
	}
	return temp;
}

bool Matrix::operator == (const Matrix& other)
{
	if (this->rows == other.rows && this->columns == other.columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (this->matrix[i][j] != other.matrix[i][j])
					return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}


Matrix Matrix::transpose()
{
	Matrix tmp(columns, rows);
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			tmp.matrix[i][j] = matrix[j][i];
		}
	}
	return tmp;
}

Matrix Matrix::power(int n)
{
	Matrix tmp(*this);
	for (int i = 0; i < n - 1; i++)
	{
		tmp = (tmp * (*this));
	}
	return tmp;
}

Matrix Matrix::algebraicComplement(int a, int b)
{
	Matrix temp(rows - 1, columns - 1);
	int t1 = 0;
	for (int i = 0; i < rows; i++)
	{
		if (i == a)
		{
			continue;
		}

		int t2 = 0;
		for (int j = 0; j < columns; j++)
		{
			if (j == b)
			{
				continue;
			}

			temp[t1][t2] = matrix[i][j];
			t2++;
		}
		t1++;
	}
	return temp;
}

Matrix Matrix::matrixAlgebraicComplement()
{
	Matrix temp(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j] = pow(-1, i + j) * algebraicComplement(i, j).det();
		}
	}
	return temp;
}

Matrix Matrix::inverseMatrix()
{
	return matrixAlgebraicComplement().transpose() * (1 / det());
}

float Matrix::findDet(Matrix a)
{
	if (a.rows == 1)
	{
		return a[0][0];
	}
	else if (a.rows == 2)
	{
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	else
	{
		float d = 0;
		for (int k = 0; k < a.rows; k++)
		{
			Matrix b(a.algebraicComplement(k, 0));
			d += pow(-1, k + 2) * a[k][0] * findDet(b);
		}
		return d;
	}
}

Matrix Matrix::tringulation()
{
	Matrix a(*this);
	for (int i = 0; i < rows; i++)
	{
		int imax = col_max(i);
		if (i != imax)
		{
			a.swapRows(i, imax);
		}

		for (int j = i + 1; j < rows; j++)
		{
			float mul = -a[j][i] / a[i][i];

			for (int k = 0; k < columns; k++)
			{
				a.matrix[j][k] = a.matrix[j][k] + a.matrix[i][k] * mul;
			}
		}
	}
	return a;
}

float Matrix::det()
{
	return findDet(*this);
}


std::ostream& operator << (std::ostream& out, const Matrix& myMatrix)
{
	for (int i = 0; i < myMatrix.rows; i++)
	{
		for (int j = 0; j < myMatrix.columns; j++)
		{
			out << myMatrix.matrix[i][j] << "\t";
		}
		out << endl;
	}
	return out;
}

std::istream& operator >> (std::istream& in, Matrix& myMatrix)
{
	for (int i = 0; i < myMatrix.rows; i++)
	{
		for (int j = 0; j < myMatrix.columns; j++)
		{
			bool inCorrect;
			do
			{
				inCorrect = false;
				cout << "Enter matrix[" << i + 1 << "][" << j + 1 << "]: ";
				in >> myMatrix.matrix[i][j];
				if (in.fail())
				{
					in.clear();
					cout << "Invalid input" << endl;
					inCorrect = true;
				}
				in.ignore(32767, '\n');
			} while (inCorrect);
		}
	}
	return in;
}



