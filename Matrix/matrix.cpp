/*
	Copyright 2019 heiyedeshengyin All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "matrix.h"

template <typename T>
void matrix<T>::init()
{
	p = new T * [rows];
	for (int i = 0; i < rows; i++)
		p[i] = new T[cols];
}

template <typename T>
matrix<T>::matrix()
{
	rows = 0;
	cols = 0;
	p = nullptr;
}

template <typename T>
matrix<T>::matrix(int rows_num, int cols_num)
{
	if (rows_num > 0 && cols_num > 0)
	{
		rows = rows_num;
		cols = cols_num;
		init();

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				p[i][j] = 0;
	}
	else
	{
		rows = 0;
		cols = 0;
		p = nullptr;
		std::cout << "构造函数错误,矩阵的行数或列数必须为正数" << std::endl << std::endl;
	}
}

template <typename T>
matrix<T>::matrix(int rows_num, int cols_num, T value)
{
	if (rows_num > 0 && cols_num > 0)
	{
		rows = rows_num;
		cols = cols_num;
		init();

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				p[i][j] = value;
	}
	else
	{
		rows = 0;
		cols = 0;
		p = nullptr;
		std::cout << "构造函数错误,矩阵的行数或列数必须为正数" << std::endl << std::endl;
	}
}

template <typename T>
matrix<T>::~matrix()
{
	if (p)
	{
		for (int i = 0; i < rows; i++)
			delete[] p[i];

		delete[] p;
	}
}

template <typename T>
matrix<T>::matrix(const matrix& another)
{
	rows = another.rows;
	cols = another.cols;

	if (rows > 0 && cols > 0)
	{
		init();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				p[i][j] = another.p[i][j];
	}
	else
		p = nullptr;
}

template <typename T>
matrix<T>::matrix(bool isInit)
{
	if (isInit)
	{
		std::cout << "正在初始化一个矩阵,请输入矩阵的行数:";
		int _rows;
		std::cin >> _rows;
		if (_rows < 1)
		{
			rows = 0;
			cols = 0;
			p = nullptr;
			std::cout << "输入的行数应大于零,矩阵初始化失败" << std::endl << std::endl;
		}
		else if (_rows == 1)
		{
			std::cout << "输入的行数等于一,初始化一个行矩阵,请输入行矩阵的列数:";
			int _cols;
			std::cin >> _cols;
			if (_cols < 1)
			{
				rows = 0;
				cols = 0;
				p = nullptr;
				std::cout << "输入的列数应大于零,矩阵初始化失败" << std::endl << std::endl;
			}
			else if (_cols == 1)
			{
				rows = 1;
				cols = 1;
				init();
				std::cout << "正创建只有一个元素的矩阵,请输入该元素的值:";
				std::cin >> p[0][0];
				std::cout << "矩阵创建成功" << std::endl << std::endl;
			}
			else
			{
				rows = 1;
				cols = _cols;
				init();
				std::cout << "已创建有" << cols << "个元素的行矩阵,请依次输入每个元素的值" << std::endl;
				for (int i = 0; i < cols; i++)
				{
					std::cout << "请输入行矩阵第" << i + 1 << "个元素的值:";
					std::cin >> p[0][i];
				}
				std::cout << "矩阵创建成功" << std::endl << std::endl;
			}
		}
		else
		{
			std::cout << "输入的行数等于" << _rows << ",初始化一个矩阵,请输入矩阵的列数:";
			int _cols;
			std::cin >> _cols;
			if (_cols < 1)
			{
				rows = 0;
				cols = 0;
				p = nullptr;
				std::cout << "输入的列数应大于零,矩阵初始化失败" << std::endl << std::endl;
			}
			else if (_cols == 1)
			{
				rows = _rows;
				cols = 1;
				init();
				std::cout << "已创建有" << rows << "个元素的列矩阵,请依次输入每个元素的值" << std::endl;
				for (int i = 0; i < rows; i++)
				{
					std::cout << "请输入列矩阵第" << i + 1 << "个元素的值:";
					std::cin >> p[i][0];
				}
				std::cout << "矩阵创建成功" << std::endl << std::endl;
			}
			else
			{
				rows = _rows;
				cols = _cols;
				init();
				std::cout << "已创建行数为" << rows << ",列数为" << cols << "的矩阵,请依次输入每个元素的值" << std::endl;
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
					{
						std::cout << "请输入矩阵第" << i + 1 << "行,第" << j + 1 << "列的值:";
						std::cin >> p[i][j];
					}
				std::cout << "矩阵创建成功" << std::endl << std::endl;
			}
		}
	}
	else
	{
		rows = 0;
		cols = 0;
		p = nullptr;
	}
}

template <typename T>
int matrix<T>::get_rows_num()
{
	return rows;
}

template <typename T>
int matrix<T>::get_cols_num()
{
	return cols;
}

template <typename T>
T matrix<T>::get_value(int i, int j)
{
	if (i > 0 && i <= rows && j > 0 && j <= cols)
		return p[i - 1][j - 1];
	else
	{
		std::cout << "get_value函数错误,输入的参数超出范围" << std::endl;
		return NULL;
	}
}

template <typename T>
bool matrix<T>::is_zero()
{
	if (!p)
		return false;
	else
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (p[i][j] != 0)
					return false;

		return true;
	}
}

template <typename T>
bool matrix<T>::is_phalanx()
{
	if (!p)
		return false;
	else
		return rows == cols;
}

template <typename T>
bool matrix<T>::is_diagonal_matrix()
{
	if (!p)
		return false;
	else
	{
		if (rows != cols)
			return false;
		else
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					if (i != j && p[i][j] != 0 || i == j && p[i][j] == 0)
						return false;

			return true;
		}
	}
}

template <typename T>
bool matrix<T>::is_scalar_matrix()
{
	if (!p)
		return false;
	else
	{
		if (rows != cols)
			return false;
		else
		{
			T a = p[0][0];
			if (a == 0)
				return false;
			else
			{
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						if (i != j && p[i][j] != 0 || i == j && p[i][j] != a)
							return false;

				return true;
			}
		}
	}
}

template <typename T>
bool matrix<T>::is_unit_matrix()
{
	if (!p)
		return false;
	else
	{
		if (rows != cols)
			return false;
		else
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					if (i != j && p[i][j] != 0 || i == j && p[i][j] != 1)
						return false;

			return true;
		}
	}
}

template <typename T>
matrix<T>& matrix<T>::operator=(const matrix& another)
{
	if (this == &another)
		return *this;

	if (another.p)
	{
		if (p && rows == another.rows && cols == another.cols)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					p[i][j] = another.p[i][j];

			return *this;
		}
		else if (p && rows == another.rows && cols != another.cols)
		{
			cols = another.cols;
			for (int i = 0; i < rows; i++)
			{
				delete[] p[i];
				p[i] = new T[cols];
			}
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					p[i][j] = another.p[i][j];

			return *this;
		}
		else if (p && rows != another.rows)
		{
			for (int i = 0; i < rows; i++)
				delete[] p[i];
			delete[] p;

			rows = another.rows;
			cols = another.cols;
			init();
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					p[i][j] = another.p[i][j];

			return *this;
		}
		else if (!p)
		{
			rows = another.rows;
			cols = another.cols;
			init();
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					p[i][j] = another.p[i][j];

			return *this;
		}
	}
	else
	{
		if (p)
		{
			for (int i = 0; i < rows; i++)
				delete[] p[i];
			delete[] p;

			rows = 0;
			cols = 0;
			p = nullptr;

			return *this;
		}
		else
			return *this;
	}
}

template <typename T>
matrix<T>& matrix<T>::operator+(const matrix& add)
{
	matrix<T>* result;
	if (is_homotype(add))
	{
		result = new matrix<T>(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->p[i][j] = p[i][j] + add.p[i][j];

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "+号运算符错误,相加的两个矩阵不是同型矩阵" << std::endl << std::endl;
		
		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::operator-(const matrix& sub)
{
	matrix<T>* result;
	if (is_homotype(sub))
	{
		result = new matrix<T>(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->p[i][j] = p[i][j] - sub.p[i][j];

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "-号运算符错误,相减的两个矩阵不是同型矩阵" << std::endl << std::endl;

		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::operator*(const matrix& mul)
{
	matrix<T>* result;
	if (p && mul.p && cols == mul.rows)
	{
		result = new matrix<T>(rows, mul.cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < mul.cols; j++)
				for (int k = 0; k < cols; k++)
					result->p[i][j] += p[i][k] * mul.p[k][j];

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "*号运算符错误,相乘的两个矩阵不符合要求" << std::endl << std::endl;

		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::operator*(const T& mul)
{
	matrix<T>* result;
	if (p)
	{
		result = new matrix<T>(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				result->p[i][j] = p[i][j] * mul;

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "*号运算符错误,矩阵未初始化" << std::endl << std::endl;

		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::operator+=(const matrix& add)
{
	if (is_homotype(add))
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				p[i][j] += add.p[i][j];

		return *this;
	}
	else
	{
		std::cout << "+=号运算符错误,相加的两个矩阵不是同型矩阵" << std::endl << std::endl;

		return *this;
	}
}

template <typename T>
matrix<T>& matrix<T>::operator-=(const matrix& sub)
{
	if (is_homotype(sub))
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				p[i][j] -= sub.p[i][j];

		return *this;
	}
	else
	{
		std::cout << "-=号运算符错误,相加的两个矩阵不是同型矩阵" << std::endl << std::endl;

		return *this;
	}
}

template <typename T>
matrix<T>& matrix<T>::power(int index)
{
	matrix<T>* result;
	if (p && rows == cols && index > 0)
	{
		if (index == 1)
		{
			result = new matrix<T>(*this);

			return *result;
		}
		else
		{
			result = new matrix<T>(rows, cols);
			result->p = power_func(p, rows, index);

			return *result;
		}
	}
	else
	{
		result = new matrix<T>();
		std::cout << "power函数异常" << std::endl << std::endl;

		return *result;
	}
}

template <typename T>
T** power_func(T** p, int n, int index)
{
	if (p && n > 0 && index > 0)
	{
		if (index == 1)
			return p;
		else if (index == 2)
		{
			T** result;
			result = new T * [n];
			for (int i = 0; i < n; i++)
			{
				result[i] = new T[n];
				for (int j = 0; j < n; j++)
					result[i][j] = 0;
			}

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
						result[i][j] += p[i][k] * p[k][j];

			return result;
		}
		else
		{
			T** result;
			T** muled = power_func(p, n, index - 1);
			result = new T * [n];
			for (int i = 0; i < n; i++)
			{
				result[i] = new T[n];
				for (int j = 0; j < n; j++)
					result[i][j] = 0;
			}

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
						result[i][j] += muled[i][k] * p[k][j];

			return result;
		}
	}
	else
		return nullptr;
}

template <typename T>
matrix<T>& matrix<T>::transposed()
{
	matrix<T>* result;
	if (p)
	{
		result = new matrix<T>(cols, rows);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < rows; j++)
				result->p[i][j] = p[j][i];

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "transposed函数异常,矩阵未初始化" << std::endl;

		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::kron(const matrix& mul)
{
	matrix<T>* result;
	if (p && mul.p)
	{
		result = new matrix<T>(rows * mul.rows, cols * mul.cols);
		for (int a_row = 0; a_row < rows; a_row++)
			for (int a_col = 0; a_col < cols; a_col++)
				for (int b_row = 0; b_row < mul.rows; b_row++)
					for (int b_col = 0; b_col < mul.cols; b_col++)
						result->p[a_row * mul.rows + b_row][a_col * mul.cols + b_col] = p[a_row][a_col] * mul.p[b_row][b_col];
		
		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "kron函数异常,矩阵未初始化" << std::endl;

		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::repmat(int m, int n)
{
	matrix<T>* result;
	if (p && m > 0 && n > 0)
	{
		result = new matrix<T>(m * rows, n * cols);
		for (int m_row = 0; m_row < m; m_row++)
			for (int n_col = 0; n_col < n; n_col++)
				for (int ori_row = 0; ori_row < rows; ori_row++)
					for (int ori_col = 0; ori_col < cols; ori_col++)
						result->p[m_row * rows + ori_row][n_col * cols + ori_col] = p[ori_row][ori_col];

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "repmat函数异常" << std::endl;

		return *result;
	}
}

template <typename T>
matrix<T>& matrix<T>::adjoint()
{
	matrix<T>* result;
	if (p && cols == rows)
	{
		result = new matrix<T>(rows, cols);
		T** cofactor;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				cofactor = cofactor_func(p, rows, i, j);
				if ((i + j) % 2 == 0)
					result->p[j][i] = det_func(cofactor, rows - 1);
				else
					result->p[j][i] = det_func(cofactor, rows - 1) * -1;
				
				for (int k = 0; k < rows - 1; k++)
					delete[] cofactor[k];
				delete[] cofactor;
			}

		return *result;
	}
	else
	{
		result = new matrix<T>();
		std::cout << "adjoint函数异常,矩阵应为方阵" << std::endl;

		return *result;
	}
}

template <typename T>
T** cofactor_func(T** p, int n, int i, int j)
{
	if (p && n > 0 && i >= 0 && i < n && j >= 0 && j < n)
	{
		T** result;
		result = new T * [n - 1];
		for (int x = 0; x < n - 1; x++)
			result[x] = new T[n - 1];

		for (int x = 0; x < n - 1; x++)
			for (int y = 0; y < n - 1; y++)
			{
				if (x < i && y < j)
					result[x][y] = p[x][y];
				if (x < i && y >= j)
					result[x][y] = p[x][y + 1];
				if (x >= i && y < j)
					result[x][y] = p[x + 1][y];
				if (x >= i && y >= j)
					result[x][y] = p[x + 1][y + 1];
			}

		return result;
	}
	else
		return nullptr;
}

template <typename T>
T matrix<T>::det()
{
	if (p && rows == cols)
		return det_func(p, rows);
	else
	{
		std::cout << "det函数异常,矩阵应为方阵" << std::endl;

		return NULL;
	}
}

template <typename T>
T det_func(T** p, int n)
{
	if (p && n > 0)
	{
		if (n == 1)
			return p[0][0];
		else if (n == 2)
			return p[0][0] * p[1][1] - p[0][1] * p[1][0];
		else
		{
			T result = 0;
			T** next;
			for (int i = 0; i < n; i++)
			{
				next = new T * [n - 1];
				for (int j = 0; j < n - 1; j++)
					next[j] = new T[n - 1];

				for (int j = 0; j < n - 1; j++)
					for (int k = 0; k < n - 1; k++)
						if (k < i)
							next[j][k] = p[j + 1][k];
						else
							next[j][k] = p[j + 1][k + 1];

				if (i % 2 == 0)
					result += det_func(next, n - 1) * p[0][i];
				else
					result -= det_func(next, n - 1) * p[0][i];
			}

			return result;
		}
	}
	else
		return -1;
}

template <typename T>
bool matrix<T>::is_homotype(const matrix& compare)
{
	if (p && compare.p)
		return rows == compare.rows && cols == compare.cols;
	else
		return false;
}

template <typename T>
bool matrix<T>::operator==(const matrix& compare)
{
	if (rows != compare.rows || cols != compare.cols)
		return false;
	else
	{
		if (!p)
			return true;
		else
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					if (p[i][j] != compare.p[i][j])
						return false;

			return true;
		}
	}
}

template <typename T>
bool matrix<T>::operator!=(const matrix& compare)
{
	if (rows != compare.rows || cols != compare.cols)
		return true;
	else
	{
		if (!p)
			return false;
		else
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					if (p[i][j] != compare.p[i][j])
						return true;

			return false;
		}
	}
}

template <typename T>
void matrix<T>::print()
{
	if (rows > 0 && cols > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols - 1; j++)
				std::cout << p[i][j] << " ";
			std::cout << p[i][cols - 1] << std::endl;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "该矩阵未初始化" << std::endl << std::endl;
}
