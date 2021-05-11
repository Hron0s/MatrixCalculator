#include <iostream>
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
			cout << "Enter matrix[" << i << "][" << j << "]: ";
			in >> myMatrix.matrix[i][j];
		}
	}
	return in;
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

			temp[t1][t2] =  matrix[i][j];
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

float Matrix::det()
{
	Matrix tmp(*this);
	return findDet(tmp);
}

Matrix GaussMethod(Matrix a, Matrix b)
{

}

Matrix CramerMethod(Matrix a, Matrix b)
{
	float aDet = a.det();
	Matrix x(a.rows, 1);
	for (int i = 0; i < a.rows; i++)
	{
		Matrix tmp(a.rows, a.columns);
		for (int j = 0; j < a.rows; j++)
		{
			for (int k = 0; k < a.columns; k++)
			{
				if (i == k)
				{
					tmp[j][k] = b[j][0];
				}
				else
				{
					tmp[j][k] = a[j][k];
				}
			}
		}

		x[i][0] = tmp.det() / aDet;
		cout << endl << endl;
	}
	return x;
}

Matrix MatrixMethod(Matrix a, Matrix b)
{
	return a.inverseMatrix() * b;
}
