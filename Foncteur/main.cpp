//
//  foncteur.cpp
//  traitementImage
//
//  Created by Emmanuel Neret on 07/01/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <iostream>
#include <functional>
#include <ostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


//template d'un foncteur

template <class Arg, class Result>
struct f_unary_function
{
    typedef Arg    argument_type;
    typedef Result result_type;
};

template <class Arg1, class Arg2, class Result>
struct f_binary_function
{
    typedef Arg1   first_argument_type;
    typedef Arg2   second_argument_type;
    typedef Result result_type;
};


// defintion des foncteurs
template <class T>
struct f_plus : f_binary_function<T, T, T>
{
    T operator()(const T &operande1, const T &operande2) const 		{ return operande1 + operande2; }
};

template <class T>
struct f_minus : f_binary_function<T, T, T>
{
    T operator()(const T &operande1, const T &operande2) const 		{ return operande1 - operande2; }
};



//couche d'abstraction pour appeler les fonction a l'aide des templates binaire/ unaire créé plus haut 
template <class T, class F>
T f_call(T i, T j, F foncteur)
{
    // Applique l'opérateur fonctionnel au foncteur
    // avec comme arguments les deux premiers paramètres :
    return foncteur(i, j);
}

template <class T, class F>
T f_call(T arg, F functor)
{
	// Applique l'opérateur fonctionnel au foncteur
	// avec comme arguments le  paramètres :
	return foncteur(arg);
}



template <class T>    
class Afficher    
{       
	std::ostream &os_;    

public:       
	
    Afficher(std::ostream &os) throw(): os_(os){}
    
	void operator()(const T &val)          
	{ 
		os_ << val << ' '; 
	}    
};

int main(void)
{
    // Foncteur basique
    f_plus<int> foncteur_plus;
    f_minus<int> foncteur_minus;
    
    cout << "foncteur addition : resultat : " << f_call(22, 20, foncteur_plus) << endl;
    cout << "foncteur soustraction : resultat : " << f_call(22,20, foncteur_minus) << endl;
    
    
    //Foncteur de traitement sur structure a l'aide du for_each    
    using std::vector;    
	using std::ifstream;    
	using std::for_each;    
    vector<int> v;    
	ifstream ifs("/Users/emmanuelneret/Documents/Polytech/spé/Foncteur/Foncteur/in.txt");
    
	for (int val; ifs >> val; v.push_back(val));  
    cout << "Size of table :" << v.size() << endl;
    for_each(v.begin(), v.end(), Afficher<int>(cout));
    
    return 0;
}