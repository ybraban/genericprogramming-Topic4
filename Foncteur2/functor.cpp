/***************************************************************************************************
 *
 *				    Objets Avances - Sujet4
 *
 *				   Polytech' Paris-Sud - APP5
 *				     * ARENJO LOPEZ David *
 * 				     * BRABAN Yoann       *
 *				     * LE POTTIER Cyril   *
 *				     * MARTON Clement     *
 *				     * NERET Emmanuel     *
 *
 ***************************************************************************************************/

/*
 **************************************************************************************************
 */

/*
 * Il est trop complique, peut etre impossible de faire des foncteurs generiques a tous les types de fonction,
 * par consequent, on ne fait des foncteurs que sur des fonctions qui ne prennent un ou deux paramètres de même type. 
 * On appelle « unaires », les fonctions qui prennent un paramètre,
 * alors que l'on appelle « binaires » les fonctions qui prennent deux paramètres. 
 * On definie donc deux classes correspondants au deux types deux fonctions decrites ci-dessus. Les attributs des
 * classes permettent de stocker tous les elements propres au type de fonction. De maniere generale on considere 
 * qu'une fonction (et non une methode) est un type de retour, une liste de type d'arguments et un pointeur vers des
 * instructions.
 */

//
// Foncteur pour les fonctions « unaires » :
//    Type de retour : Ret
//    Liste d'argument : Arg
//    Pointeur vers instructions : Les instructions seront dans les classes filles
//
template <class Arg, class Ret>
struct f_unary_function
{
    typedef Arg		argument_type;
    typedef Ret 	result_type;
};

//
// Foncteur pour les fonctions « binaires »
//    Type de retour : Ret
//    Liste d'argument : Arg1 et Arg2
//    Pointeur vers instructions : Les instructions seront dans les classes filles
//
template <class Arg1, class Arg2, class Ret>
struct f_binary_function
{
    typedef Arg1	first_argument_type;
    typedef Arg2	second_argument_type;
    typedef Ret		result_type;
};

/*
 **************************************************************************************************
 */

/*
 * On definie un certain nombre de foncteurs standards. Ces foncteurs permettent d'appliquer les 
 * principaux opérateurs du langage comme des fonctions classique dans les algorithmes de la 
 * libraire standard.
 */
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

template <class T>
struct f_multiplies : f_binary_function<T, T, T>
{
    T operator()(const T &operande1, const T &operande2) const	 	{ return operande1 * operande2; }
};

template <class T>
struct f_divides : f_binary_function<T, T, T>
{
    T operator()(const T &operande1, const T &operande2) const	 	{ return operande1 / operande2; }
};

template <class T>
struct f_modulus : f_binary_function<T, T, T>
{
    T operator()(const T &operande1, const T &operande2) const	 	{ return operande1 % operande2; }
};

template <class T>
struct f_negate : f_unary_function<T, T>
{
    T operator()(const T &operande) const				{ return -operande; }
};

template <class T>
struct f_equal_to : f_binary_function<T, T, bool>
{
    bool operator()(const T &operande1, const T &operande2) const	{ return operande1 == operande2; }
};

template <class T>
struct f_not_equal_to : f_binary_function<T, T, bool>
{
    bool operator()(const T &operande1, const T &operande2) const	{ return operande1 != operande2; }
};

template <class T>
struct f_greater : f_binary_function<T, T, bool>
{
    bool operator()(const T &operande1, const T &operande2) const	{ return operande1 > operande2; }
};

template <class T>
struct f_less : f_binary_function<T, T, bool>
{
    bool operator()(const T &operande1, const T &operande2) const	{ return operande1 < operande2; }
};

template <class T>
struct f_greater_equal : f_binary_function<T, T, bool>
{
    bool operator()(const T &operande1, const T &operande2) const	{ return operande1 >= operande2; }
};

template <class T>
struct f_less_equal : f_binary_function<T, T, bool>
{
    bool operator()(const T &operande1, const T &operande2) const	{ return operande1 <= operande2; }
};

/*
 **************************************************************************************************
 */

/*
 * On cree maintenant une fonction f_call qui permet de d'utiliser les foncteurs
 * On surcharge cette fonction autant de fois qu'on a definie de type de fonction
 */
//
// Fonction template pour les fonctions « binaires » prenant en paramètre 
// deux valeurs et un foncteur
//
template <class T, class F>
T f_call(T arg1, T arg2, F functor)
{
	// Applique l'opérateur fonctionnel au foncteur
	// avec comme arguments les deux premiers paramètres :
	return functor(arg1, arg2);
}

//
// Fonction template pour les fonction « unaires » prenant en paramètre 
// une valeur et un foncteur
//
template <class T, class F>
T f_call(T arg, F functor)
{
	// Applique l'opérateur fonctionnel au foncteur
	// avec comme arguments les deux premiers paramètres :
	return functor(arg);
}
