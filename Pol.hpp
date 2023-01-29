#ifndef POL_HPP
#define POL_HPP

#include <iostream>
#include <cstdlib>
#include "QRatio.hpp"

using namespace std;

class Pol {
	private:
		int n;
		QRatio *p;
	public:
		Pol(int k=0);
		~Pol(void);
		int Gr(void) const;
		QRatio operator[] (int) const;
		QRatio& operator[] (int);
		Pol& operator = (const Pol&  q);
};

ostream& operator << (ostream& out, const Pol& p);
istream& operator >> (istream& out, Pol& p);
Pol operator + (const Pol&, const Pol&);
Pol operator - (const Pol&, const Pol&);
Pol operator * (const Pol&, const Pol&);
Pol operator / (const Pol&, const Pol&);
#endif