#include<iostream>

using namespace std;

class Matrix
{
	int rows;
	int cols;
	int** arr;
public:
	int get_rows()const;
	int get_cols()const;
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other)
	{
		if (this == &other)return *this;
		this->~Matrix();
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			this->arr[i] = new int[cols] {};
			memcpy(this->arr[i], other.arr[i], cols * sizeof(int));
		}
		return *this;
	}
	const int* operator[](int i)const
	{
		return arr[i];
	}
	int* operator[](int i)
	{
		return arr[i];
	}
	void print()const;
};
int Matrix::get_rows()const
{
	return rows;
}
int Matrix::get_cols() const
{
	return cols;
}
Matrix::Matrix()
{

}
Matrix::Matrix(int rows = 5, int cols = 5)
{
	this->rows = rows;
	this->cols = cols;
	this->arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
}
Matrix::Matrix(const Matrix& other)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = other.arr[i][j];
		}
	}
	*this = other;
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	rows = 0;
	cols = 0;
}
void Matrix::print()const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russin");
	Matrix A(3, 4);
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			A[i][j] = rand() % 100;
		}
	}
	A = A;
	A.print();
	return 0;
}