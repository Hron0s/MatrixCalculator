#include <iostream>
#include <conio.h>
#include "Matrix.h"
using namespace std;


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
	int selectedMenu;
	do
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
			cout << "Solution of a system of linear equations" << endl;

			pause();
			break;
		}
		}

	} while (selectedMenu != 27);
	return 0;
}





