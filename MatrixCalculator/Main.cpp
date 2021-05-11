#include <iostream>
#include "Matrix.h"
using namespace std;


void logo()
{
	cout << " /$$      /$$             /$$               /$$                /$$$$         /$$$$" << endl;
	cout << "| $$$    /$$$            | $$              |__/               | $$_/        |_  $$" << endl;
	cout << "| $$$$  /$$$$  /$$$$$$  /$$$$$$    /$$$$$$  /$$ /$$   /$$     | $$            | $$" << endl;
	cout << "| $$ $$/$$ $$ |____  $$|_  $$_/   /$$__  $$| $$|  $$ /$$/     | $$            | $$" << endl;
	cout << "| $$  $$$| $$  /$$$$$$$  | $$    | $$  \\__/| $$ \\  $$$$/      | $$            | $$" << endl;
	cout << "| $$\\  $ | $$ /$$__  $$  | $$ /$$| $$      | $$  >$$  $$      | $$            | $$" << endl;
	cout << "| $$ \\/  | $$|  $$$$$$$  |  $$$$/| $$      | $$ /$$/\\  $$     | $$$$         /$$$$" << endl;
	cout << "|__/     |__/ \\_______/   \\___/  |__/      |__/|__/  \\__/     |____/        |____/" << endl;
}

int main()
{
	Matrix a(3);
	Matrix b(3, 1);
	cin >> a >> b;
	cout << a << endl;
	cout << b << endl;
	cout << GaussMethod(a, b) << endl << endl;
	cout << MatrixMethod(a, b) << endl << endl;
	cout << CramerMethod(a, b) << endl << endl;
	return 0;
}





