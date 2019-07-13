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

#pragma once

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cmath>

template<typename T>
class matrix
{
private:
	int rows;
	int cols;
	T** p;
	void init();
public:
	matrix();
	matrix(int rows_num, int cols_num);
	matrix(int rows_num, int cols_num, T value);
	matrix(const matrix& another);
	matrix(bool isInit);
	~matrix();
	int get_rows_num();
	int get_cols_num();
	T get_value(int i, int j);
	bool is_zero();
	bool is_phalanx();	//∑Ω’Û
	bool is_diagonal_matrix();	//∂‘Ω«æÿ’Û
	bool is_scalar_matrix();	//¥ø¡øæÿ’Û
	bool is_unit_matrix();	//µ•Œªæÿ’Û
	matrix<T>& operator=(const matrix& another);
	matrix<T>& operator+(const matrix& add);
	matrix<T>& operator-(const matrix& sub);
	matrix<T>& operator*(const matrix& mul);
	matrix<T>& operator*(const T& mul);
	matrix<T>& operator+=(const matrix& add);
	matrix<T>& operator-=(const matrix& sub);
	matrix<T>& power(int index);	//√›æÿ’Û
	matrix<T>& transposed();	//◊™÷√æÿ’Û
	matrix<T>& kron(const matrix& mul);	//Kronecher≥À∑®
	matrix<T>& repmat(int m, int n);	//¿©’πæÿ’Ûm*n
	matrix<T>& adjoint();	//∞ÈÀÊæÿ’Û
	T det();
	bool is_homotype(const matrix& compare);
	bool operator==(const matrix& compare);
	bool operator!=(const matrix& compare);
	void print();
};

template <typename T>
T** power_func(T** p, int n, int index);

template <typename T>
T** cofactor_func(T** p, int n, int i, int j);

template <typename T>
T det_func(T** p, int n);

#endif // !MATRIX_H

