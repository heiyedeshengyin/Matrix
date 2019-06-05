#include "matrix.cpp"

using namespace std;
int main()
{
	matrix<int> m1(true);
	m1.print();

	matrix<int> m2 = m1.adjoint();
	m2.print();

	matrix<int> m3 = m2 * m1;
	m3.print();

	return 0;
}