#include "matrix.cpp"

using namespace std;
int main()
{
	matrix<long double> m1(true);

	if (m1.is_reversible_matrix())
		cout << "�������" << endl;
	else
		cout << "���󲻿���" << endl;


	return 0;
}