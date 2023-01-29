#ifndef QRatio_HPP
#define QRatio_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

class QRatio {
	public:
		float real, imaginaria;
		QRatio();
};

ostream& operator << (ostream& out, const QRatio& z);
istream& operator >> (istream& out, QRatio& z);
QRatio operator + (const QRatio&, const QRatio&);
QRatio operator - (const QRatio&, const QRatio&);
QRatio operator * (const QRatio&, const QRatio&);
QRatio operator / (const QRatio&, const QRatio&);
#endif