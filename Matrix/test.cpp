#include "matrix.cpp"

using namespace std;
int main()
{
	matrix<double> m1(true);

	matrix<double> m2 = m1.adjoint();

	m1.print();
	m2.print();


	return 0;
}