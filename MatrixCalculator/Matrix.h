class Matrix
{
	int rows;
	int columns;
	float** matrix;

	float findDet(Matrix a);
	int rowMaxElement(int n1, int n2);
	void swapRows(int n1, int n2);

public:
	Matrix();
	Matrix(int rows);
	Matrix(int rows, int columns);
	~Matrix();

	Matrix(const Matrix& other);

	int getRows();
	int getColumns();

	float* operator [] (int i);

	Matrix& operator = (const Matrix& other);
	Matrix operator + (const Matrix& other);
	Matrix operator - (const Matrix& other);
	Matrix operator * (const Matrix& other);
	Matrix operator * (float a);
	Matrix operator / (float a);

	bool operator == (const Matrix& other);

	Matrix transpose();
	Matrix power(int n);
	Matrix algebraicComplement(int a, int b);
	Matrix matrixAlgebraicComplement();
	Matrix inverseMatrix();
	Matrix tringulation();
	float  det();

	friend std::ostream& operator << (std::ostream& out, const Matrix& myMatrix);
	friend std::istream& operator >> (std::istream& in, Matrix& myMatrix);

	friend void CramerMethod(Matrix a, Matrix b);
	friend void MatrixMethod(Matrix a, Matrix b);
	friend void GaussMethod(Matrix a, Matrix b);

};

