#include <iostream>
#include <iostream>
#include <functional>
#include <ostream>
#include <vector>
#include <fstream>
#include <algorithm>
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
    
    //Foncteur de traitement sur structure a l'aide du for_each  
    
    cout << "utilisation du foncteur d'affichage avec la fonction for_each" << endl;
    
    using std::vector;    
	using std::ifstream;    
	using std::for_each;    
    vector<int> v;
    
    // chemin à changer!!!!
	ifstream ifs("/Users/emmanuelneret/Documents/Polytech/spé/Objet avancé/Fonctor_final/Fonctor_final/in.txt");
    
	for (int val; ifs >> val; v.push_back(val));  
    cout << "Size of table :" << v.size() << endl;
    for_each(v.begin(), v.end(), Afficher<int>(cout));
    
    
    
	return 0;
}
