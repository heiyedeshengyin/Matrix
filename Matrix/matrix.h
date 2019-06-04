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
	matrix<T>& operator=(const matrix& another);
	bool operator==(const matrix& compare);
	bool operator!=(const matrix& compare);
	void print();
};


#endif // !MATRIX_H

