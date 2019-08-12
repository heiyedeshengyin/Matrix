#include "matrix.cpp"

using namespace std;
int main()
{
	matrix<long double> m1(true);

	if (m1.is_reversible_matrix())
		cout << "¾ØÕó¿ÉÄæ" << endl;
	else
		cout << "¾ØÕó²»¿ÉÄæ" << endl;


	return 0;
}