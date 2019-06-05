#include "matrix.cpp"

using namespace std;
int main()
{
	matrix<int> m1(true);
	
	if (m1.is_zero())
		cout << "zero" << endl;
	else
		cout << "not zero" << endl;

	if (m1.is_diagonal_matrix())
		cout << "diagonal" << endl;
	else
		cout << "not diagonal" << endl;

	if (m1.is_scalar_matrix())
		cout << "scalar" << endl;
	else
		cout << "not scalar" << endl;

	if (m1.is_unit_matrix())
		cout << "unit" << endl;
	else
		cout << "not unit" << endl;

	matrix<int> m2(3, 3, 1);

	if (m1.is_homotype(m2))
		cout << "m1 same m2" << endl;
	else
		cout << "m1 not same m2" << endl;

	return 0;
}