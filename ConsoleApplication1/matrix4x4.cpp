#include <iostream>	
#include "matrix4x4.h"

inline double& matrix4x4::operator()(int row, int col)
{
	return matrix[row][col];
}
matrix4x4& matrix4x4::Trans()
{
	for (int i = 0; i < MATRIX_LEN; i++)
	{
		for (int j = 0; j < MATRIX_LEN; j++)
		{
			matrix[i][j] = matrix[j][i];
		}
	}
	return *this;
}
matrix4x4 matrix4x4:: operator+(const matrix4x4  &add)
{
	matrix4x4 temp(*this);
	for (int i = 0; i < MATRIX_LEN; i++)
	{
		for (int j = 0; j < MATRIX_LEN; j++)
		{
			temp.matrix[i][j]= + add.matrix[i][j];
		}
	}
	return temp;
}

matrix4x4 matrix4x4:: operator-(const matrix4x4  &sub)
{
	matrix4x4 temp(*this);
	for (int i = 0; i < MATRIX_LEN; i++)
	{
		for (int j = 0; j < MATRIX_LEN; j++)
		{
			temp.matrix[i][j] -= sub.matrix[i][j];
		}
	}
	return temp;
}

matrix4x4 matrix4x4:: operator*(const matrix4x4  &muti)
{
	matrix4x4 res;
	for (int i = 0; i < MATRIX_LEN; i++)
	{
		for (int j = 0; j < MATRIX_LEN; j++)
		{
			for (int k = 0; k < MATRIX_LEN; k++)
			{
				res.matrix[i][j] = this->matrix[i][k] * muti.matrix[k][j];
			}
		}
	}
	return res;
}

matrix4x4 matrix4x4::operator=(const matrix4x4  &right)
{
	matrix4x4 temp;
}

matrix4x4 matrix4x4::operator^(const int pow)
{
	matrix4x4 res;

	for (int i = 0; i < pow; i++)
	{
		res = res * (*this);
	}
	return res;
}

istream& operator>>(istream& is, matrix4x4& mt)
{
	if (is)		//检查输入流是否成功
	{
		for (int i = 0; i < MATRIX_LEN; i++)
		{
			for (int j = 0; j < MATRIX_LEN; j++)
			{
				is >> mt(i, j);
			}
		}
	}
	else
	{
		cout<<"Input error!"<<endl ;
		mt = matrix4x4();	//发生输入流错误则利用构造函数重置为默认值
		cout << "Matrix is initated with default value !" << endl;
	}
	return is;
}

ostream& operator<<(ostream& os, matrix4x4& mt)
{
	for (int i = 0; i < MATRIX_LEN; i++)
	{
		for (int j = 0; j < MATRIX_LEN; j++)
		{
			os << mt(i, j)<<"  ";
		}
		os << endl;
	}
	return os;
}
