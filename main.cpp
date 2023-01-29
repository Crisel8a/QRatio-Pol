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
	cout << "La suma es: " << p+q << endl;
	cout << "La resta es: " << p-q << endl;
	cout << "EL producto es: " << p*q << endl;

	return 0;
}
