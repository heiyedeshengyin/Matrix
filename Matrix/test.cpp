#include "matrix.cpp"

int main()
{
	matrix<int> m1(true);
	
	std::cout << m1.get_rows_num() << std::endl;
	std::cout << m1.get_cols_num() << std::endl;
	std::cout << m1.get_value(2, 3) << std::endl;

	return 0;
}