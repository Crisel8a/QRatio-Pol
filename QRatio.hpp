#ifndef QRatio_HPP
#define QRatio_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

class QRatio {
	private:
		double real, imaginaria;
	public:
		QRatio(double r=0.0, double i=0.0);
		double getReal(void) const;
		double getImaginaria(void) const;
};

ostream& operator << (ostream& out, const QRatio& z);
istream& operator >> (istream& out, QRatio& z);
QRatio operator + (const QRatio&, const QRatio&);
QRatio operator - (const QRatio&, const QRatio&);
QRatio operator * (const QRatio&, const QRatio&);
QRatio operator / (const QRatio&, const QRatio&);
#endif