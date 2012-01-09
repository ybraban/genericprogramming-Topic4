#include <iostream>
#include "functor.cpp"
//#include "functor2.cpp"
//#include "functor3.cpp"

using namespace std;


int maxi(int i, int j)
{
    return (i > j) ? i : j;
}

int main(void)
{	
	int resP;
	int resM;
	int resMax;
	int resN;
	int resE;

	// Construit le foncteur de somme :
	f_plus<int> foncteur_plus;
	f_multiplies<int> foncteur_mult;
	f_negate<int> foncteur_neg;
	f_equal_to<int> foncteur_eq;

	resP = f_call(2, 3, foncteur_plus);
	cout << "2+3 = " << resP << endl;
	resM = f_call(3, 4, foncteur_mult);
	cout << "3*4 = " << resM << endl;
	resN = f_call(resM, foncteur_neg);
	cout << "-" << resM << " = " << resN << endl;
	resE = f_call(resP, resM, foncteur_eq);
	cout << resP << " == " << resM << " = " << resE << endl;
	resMax = f_call(5, 6, maxi);
	cout << "max(5,6) = " << resMax << endl;

	return 0;
}
