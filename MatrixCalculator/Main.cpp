#include <iostream>
#include <conio.h>
#include "Matrix.h"
using namespace std;

void CramerMethod(Matrix a, Matrix b)
{
	cout << "Crammer method: " << endl << endl;;
	cout << "|------------------------Crammer Method-----------------------|" << endl << endl;
	float aDet = a.det();
	cout << "A det: " << aDet << endl << endl;
	Matrix x(a.getRows(), 1);
	for (int i = 0; i < a.getRows(); i++)
	{
		Matrix tmp(a.getRows(), a.getColumns());
		for (int j = 0; j < a.getRows(); j++)
		{
			for (int k = 0; k < a.getColumns(); k++)
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

		float tmpDet = tmp.det();
		cout << "Matrix [" << i + 1 << "]:" << endl;
		cout << tmp << endl;
		cout << "Matrix [" << i + 1 << "] det: " << tmpDet << endl;
		cout << "x[" << i + 1 << "] = (" << tmpDet << " / " << aDet << ") = " << (tmpDet / aDet) << endl << endl << endl;
		x[i][0] = tmp.det() / aDet;
	}

	cout << "|------------------------------------------------------------|" << endl << endl;
	cout << "Matrix column unknown: " << endl;
	cout << x << endl;
	cout << "|------------------------------------------------------------|" << endl << endl;
}

void MatrixMethod(Matrix a, Matrix b)
{
	cout << "Matrix Method: " << endl << endl;
	Matrix inverMatrix = (a.inverseMatrix());
	cout << "Inverse Matrix: " << endl;
	cout << inverMatrix << endl;
	cout << "|-----------------------Matrix Method------------------------|" << endl << endl;
	cout << "Matrix column unknown = Inverse matrix(A) * B: " << endl;
	cout << inverMatrix * b << endl;
	cout << "|------------------------------------------------------------|" << endl << endl;
}

void GaussMethod(Matrix a, Matrix b)
{
	cout << "|------------------------Gauss Method------------------------| " << endl << endl;
	Matrix x(a.rows, 1);
	Matrix tmp(a.rows, a.columns + 1);

	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.columns; j++)
		{
			tmp[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < a.rows; i++)
	{
		tmp[i][a.columns] = b[i][0];
	}

	cout << "Let's write the system in the form of an extended matrix: " << endl;
	cout << tmp << endl;

	cout << "Let us reduce the matrix to triangular form: " << endl;
	tmp = tmp.tringulation();
	cout << tmp << endl;


	for (int i = a.rows - 1; i >= 0; i--)
	{
		x[i][0] = tmp[i][a.rows] / tmp[i][i];
		for (int c = a.rows - 1; c > i; c--)
		{
			x[i][0] = x[i][0] - tmp[i][c] * x[c][0] / tmp[i][i];
		}
	}

	cout << "At the second stage, we will solve the obtained equations in the reverse order. We have: " << endl;
	for (int i = a.rows - 1; i >= 0; i--)
	{
		cout << "x[" << i + 1 << "] = " << x[i][0] << endl;
	}
	cout << endl;
	cout << "|------------------------------------------------------------|" << endl << endl;

	cout << "Matrix column unknown: " << endl;
	cout << x << endl;
	cout << "|------------------------------------------------------------|" << endl << endl;

}

void menu()
{
	cout << " /$$      /$$             /$$               /$$                /$$$$         /$$$$" << endl;
	cout << "| $$$    /$$$            | $$              |__/               | $$_/        |_  $$" << endl;
	cout << "| $$$$  /$$$$  /$$$$$$  /$$$$$$    /$$$$$$  /$$ /$$   /$$     | $$            | $$" << endl;
	cout << "| $$ $$/$$ $$ |____  $$|_  $$_/   /$$__  $$| $$|  $$ /$$/     | $$            | $$" << endl;
	cout << "| $$  $$$| $$  /$$$$$$$  | $$    | $$  \\__/| $$ \\  $$$$/      | $$            | $$" << endl;
	cout << "| $$\\  $ | $$ /$$__  $$  | $$ /$$| $$      | $$  >$$  $$      | $$            | $$" << endl;
	cout << "| $$ \\/  | $$|  $$$$$$$  |  $$$$/| $$      | $$ /$$/\\  $$     | $$$$         /$$$$" << endl;
	cout << "|__/     |__/ \\_______/   \\___/  |__/      |__/|__/  \\__/     |____/        |____/" << endl << endl;

	cout << "1. Determinant of a square matrix " << endl;
	cout << "2. Inverse matrix" << endl;
	cout << "3. Transpose matrix" << endl;
	cout << "4. Triangularization " << endl;
	cout << "5. Exponentiation of a matrix" << endl;
	cout << "6. Multiplying a matrix by a Number" << endl;
	cout << "7. Matrix addition" << endl;
	cout << "8. Matrix difference" << endl;
	cout << "9. Matrix multiplication" << endl;
	cout << "0. Solution of a system of linear equations" << endl;
	cout << "Press espace to exit..." << endl;
}

void pause()
{
	int key;
	cout << "Press Enter to continue..." << endl;
	do
	{
		key = _getch();

	} while (key != 13);
}

int main()
{
	cin.exceptions(ios_base::failbit);
	int selectedMenu;
	do
	{
		try
		{
			system("cls");
			menu();
			cout << endl;

			selectedMenu = _getch();
			switch (selectedMenu)
			{
			case 49:
			{
				int n;
				cout << "Matrix[n x n] determinant" << endl;
				cout << "Enter the size of the square matrix [n]: ";
				cin >> n;
				Matrix a(n);
				cout << endl;
				cout << "Enter matrix[" << n << " x " << n << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix[" << n << " x " << n << "]" << endl;
				cout << a << endl;;
				cout << "Matrix det: " << a.det() << endl;

				pause();
				break;
			}
			case 50:
			{
				int n;
				cout << "Inverse matrix[n x n]" << endl;
				cout << "Enter the size of the square matrix [n]: ";
				cin >> n;
				Matrix a(n);
				cout << endl;
				cout << "Enter matrix[" << n << " x " << n << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix[" << n << " x " << n << "]" << endl;
				cout << a << endl;;

				if (a.det() == 0)
				{
					cout << "Square matrix is irrevesible" << endl;
				}
				else
				{
					cout << "Inverse matrix[" << n << " x " << n << "]" << endl;
					cout << a.inverseMatrix() << endl;
				}

				pause();
				break;
			}
			case 51:
			{
				int n;
				int m;
				cout << "Transpose Matrix[n x m]" << endl;
				cout << "Enter the size of [n]: ";
				cin >> n;
				cout << "Enter the size of [m]: ";
				cin >> m;
				Matrix a(n, m);
				cout << endl;
				cout << "Enter matrix[" << n << " x " << m << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix[" << n << " x " << m << "]" << endl;
				cout << a << endl;;
				cout << "Transpose matrix[" << m << " x " << n << "]" << endl;
				cout << a.transpose() << endl;

				pause();
				break;
			}
			case 52:
			{
				int n;
				int m;
				cout << "Triangularization matrix[n x m]" << endl;
				cout << "Enter the size of [n]: ";
				cin >> n;
				cout << "Enter the size of [m]: ";
				cin >> m;
				Matrix a(n, m);
				cout << endl;
				cout << "Enter matrix[" << n << " x " << m << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix[" << n << " x " << m << "]" << endl;
				cout << a << endl;
				cout << "Triangular matrix[" << n << " x " << m << "]" << endl;
				cout << a.tringulation() << endl;

				pause();
				break;
			}
			case 53:
			{
				int n;
				int z;
				cout << "Exponentiation of a matrix[n x n]" << endl;
				cout << "Enter the size of the square matrix [n]: ";
				cin >> n;
				Matrix a(n);
				cout << endl;
				cout << "Enter matrix[" << n << " x " << n << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix[" << n << " x " << n << "]" << endl;
				cout << a << endl;;
				cout << "Enter degree: ";
				cin >> z;
				cout << endl;
				cout << "Matrix[" << n << " x " << n << "] in degree " << z << endl;
				cout << a.power(z);

				pause();
				break;
			}
			case 54:
			{
				int n;
				int m;
				float z;
				cout << "Multiplying a matrix[n x m] by a number" << endl;
				cout << "Enter the size of [n]: ";
				cin >> n;
				cout << "Enter the size of [m]: ";
				cin >> m;
				Matrix a(n, m);
				cout << endl;
				cout << "Enter matrix[" << n << " x " << m << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix[" << n << " x " << m << "]" << endl;
				cout << a << endl;
				cout << "Enter a multiplier: ";
				cin >> z;
				cout << endl;
				cout << "Matrix[" << n << " x " << m << "] multiplied by " << z << endl;
				cout << (a * z);

				pause();
				break;
			}
			case 55:
			{
				int n;
				int m;
				cout << "Matrix A[n x m], Matrix B[n x m] addition" << endl;
				cout << "Enter the size of [n]: ";
				cin >> n;
				cout << "Enter the size of [m]: ";
				cin >> m;
				cout << endl;
				Matrix a(n, m), b(n, m);
				cout << "Enter matrix A[" << n << " x " << m << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix A[" << n << " x " << m << "]" << endl;
				cout << a << endl;
				cout << "Enter matrix B[" << n << " x " << m << "]" << endl;
				cin >> b;
				cout << endl;
				cout << "Matrix B[" << n << " x " << m << "]" << endl;
				cout << b << endl;
				cout << "Matrix result С[" << n << " x " << n << "]" << endl;
				cout << (a + b) << endl;

				pause();
				break;
			}
			case 56:
			{
				int n;
				int m;
				cout << "Matrix A[n x m], Matrix B[n x m] difference" << endl;
				cout << "Enter the size of [n]: ";
				cin >> n;
				cout << "Enter the size of [m]: ";
				cin >> m;
				cout << endl;
				Matrix a(n, m), b(n, m);
				cout << "Enter matrix A[" << n << " x " << m << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix A[" << n << " x " << m << "]" << endl;
				cout << a << endl;
				cout << "Enter matrix B[" << n << " x " << m << "]" << endl;
				cin >> b;
				cout << endl;
				cout << "Matrix B[" << n << " x " << m << "]" << endl;
				cout << b << endl;
				cout << "Matrix result С[" << n << " x " << m << "]" << endl;
				cout << (a - b) << endl;

				pause();
				break;
			}
			case 57:
			{
				int n, k, m;
				cout << "Matrix multiplication" << endl;
				cout << "A[n x k] * B[k x m] = C[n x m]" << endl;
				cout << "Enter [n]: ";
				cin >> n;
				cout << "Enter [k]: ";
				cin >> k;
				cout << "Enter [m]: ";
				cin >> m;
				Matrix a(n, k), b(k, m);
				cout << "Enter matrix A[" << n << " x " << k << "]" << endl;
				cin >> a;
				cout << endl;
				cout << "Matrix A[" << n << " x " << k << "]" << endl;
				cout << a << endl;
				cout << "Enter matrix B[" << k << " x " << m << "]" << endl;
				cin >> b;
				cout << endl;
				cout << "Matrix B[" << k << " x " << m << "]" << endl;
				cout << b << endl;
				cout << "Matrix result C[" << n << " x " << m << "]" << endl;
				cout << (a * b) << endl;

				pause();
				break;
			}
			case 48:
			{
				int n;
				int submenu;
				cout << "Solution of a system of linear equations" << endl;
				cout << "The quadratic system of linear algebraic equations can be represented in matrix form as: " << endl << endl;
				cout << "|a[1][1] a[1][2] ... a[1][n]|   |x[1]|   |b[1]|" << endl;
				cout << "|a[2][1] a[2][2] ... a[2][n]|   |x[2]|   |b[2]|" << endl;
				cout << "|a[3][1] a[3][2] ... a[3][n]| * |x[3]| = |b[3]|" << endl;
				cout << "|   ..      ..          ..  |   | .. |   | .. |" << endl;
				cout << "|a[n][1] a[n][2] ... a[n][n]|   |x[n]|   |b[n]|" << endl << endl;
				cout << "Here A is the matrix of the system, x is the column of unknowns, and b is the column of free members." << endl << endl;

				cout << "Enter the number of unknowns [n]: ";
				cin >> n;

				Matrix a(n, n), b(n, 1);
				cout << "Enter the matrix of the system A" << endl;
				cin >> a;
				cout << endl;
				cout << "Enter the column of free members b" << endl;
				cin >> b;
				cout << endl;
				cout << "Matrix of the system A:" << endl;
				cout << a << endl;
				cout << "Column of the free member b:" << endl;
				cout << b << endl;

				if (a.det() != 0)
				{
					cout << "|-----------------------|" << endl;
					cout << "1.Crammer Method" << endl;
					cout << "2.Gauss Method" << endl;
					cout << "3.Matrix Method" << endl;
					cout << "Press espace to exit..." << endl;
					cout << "|-----------------------|" << endl << endl;

					do {

						submenu = _getch();
						switch (submenu)
						{
						case 49:
						{
							CramerMethod(a, b);
							break;
						}
						case 50:
						{
							GaussMethod(a, b);
							break;
						}
						case 51:
						{
							MatrixMethod(a, b);
							break;
						}
						default:
							break;
						}

					} while (submenu != 27);
				}
				else
				{
					cout << "Determinant matrix of the system = 0" << endl;
					pause();
				}

				break;
			}
			}
		}
		catch (ios_base::failure)
		{
			cin.exceptions(ios_base::goodbit);
			cout << "Error..." << endl;

			cin.clear();
			cin.ignore();
			cin.ignore(32767, '\n');

			pause();
		}

	} while (selectedMenu != 27);
	return 0;
}





