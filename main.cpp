#include <iostream>
#include <cstdlib>
#include "QRatio.hpp"
#include "Pol.hpp"

using namespace std;

int main(void)
{
	QRatio z, w;
	Pol p, q;

	//cout << "Ingresa el grado del polonimio seguido de los coeficientes iniciando por el de grado mayor" << endl;
	cout << "Construyendo el polinomio p \n";
	cin >> p;
	cout << "\nConstruyendo el polinomio q \n";
	cin >> q;
	cout << "\n\nEl polinomio p es: " << p << endl;
	cout << "El polinomio q es: " << q << endl;
	cout << "\nLa suma es: " << p+q << endl;
	cout << "La resta es: " << p-q << endl;
	cout << "El producto es: " << p*q << endl;
	cout << "La division es: " << p/q << endl;
	cout << "El MCD es: " << mcd(p,q) << endl;

	return 0;
}
