#include <iostream>
#include <cstdlib>
#include "QRatio.hpp"

using namespace std;

int main(void)
{
	QRatio z, w;


	cout << "Dar el complejo z: \n";
	cin >> z;

	cout << "Dar el complejo w: \n";
	cin >> w;

	cout << z + w << endl;
	cout << z - w << endl;
	cout << z*w << endl;
	cout << z/w << endl;

	return 0;
}
 
 