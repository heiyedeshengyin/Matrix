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
	bool is_diagonal_matrix();	//∂‘Ω«æÿ’Û
	bool is_scalar_matrix();	//¥ø¡øæÿ’Û
	bool is_unit_matrix();	//µ•Œªæÿ’Û
	matrix<T>& operator=(const matrix& another);
	bool is_homotype(const matrix& compare);
	bool operator==(const matrix& compare);
	bool operator!=(const matrix& compare);
	void print();
};


#endif // !MATRIX_H

