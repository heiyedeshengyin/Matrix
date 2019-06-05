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
