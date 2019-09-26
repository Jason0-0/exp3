#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#define MATRIX_LEN 4	
#include <iostream>

/*
TODO： 赋值或计算后还是求逆时才计算秩？
		二维数组的=重载
		想清楚两个相同类的赋值到底需不需要重载=

*/

using namespace std;

class matrix4x4
{
public:
	matrix4x4();
	template<typename T>
	matrix4x4(T const mat[][MATRIX_LEN] );
	matrix4x4 operator+(const matrix4x4  &add);
	matrix4x4 operator-(const matrix4x4  &sub);
	matrix4x4 operator*(const matrix4x4  &muti);
	matrix4x4 operator^(const int pow);
	matrix4x4 operator=(const matrix4x4  &right);
	double& operator()(const int  row, const int col);
	friend istream & operator>> (istream& is, matrix4x4& mt);
	friend ostream& operator<<(ostream& os, matrix4x4& mt);

	matrix4x4& Trans();
	//matrix4x4 Reverse();
	
	//double Det();


	~matrix4x4();

private:

	double matrix[MATRIX_LEN][MATRIX_LEN];
	double rule;	//矩阵的秩
	//int CalRule();

	//行列式及矩阵求逆
	void ExchangeRow(double* row1,double* row2)
	{
		double* temp=row1;
		row1 = row2;
		row2 = temp;
	}

	

};

istream & operator>> (istream&, matrix4x4&);
ostream& operator<<(ostream&, matrix4x4&);

matrix4x4::matrix4x4()
{
	memset(matrix, 0, sizeof(double) * MATRIX_LEN * MATRIX_LEN);
	for (int  i = 0; i < MATRIX_LEN; i++)
	{
		matrix[i][i] = 1;
	}
	rule = MATRIX_LEN;
}
template<typename T>
matrix4x4::matrix4x4(T const mat[][MATRIX_LEN])
{
	for (int i = 0; i < MATRIX_LEN; i++)
	{
		for (int j = 0; j <MATRIX_LEN; j++)
		{
			matrix[i][j] = mat[i][j];
		}
	}
	//return *this;
}

matrix4x4::~matrix4x4()
{
}
#endif // MATRIX4X4_H
