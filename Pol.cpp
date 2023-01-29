#include <iostream>
#include <cstdlib>

#include "Pol.hpp"
#include "QRatio.hpp"

Pol::Pol(int gr) 
{
	if (gr<0) 
		gr= 0;
	n= gr;
	p= new QRatio [n+1];
	for (int k=0; k<=n; ++k)
		p[k]= 0.0;
}

Pol::~Pol(void)
{
	delete [] p;
}

int Pol::Gr(void) const
{
	int g= n;
	while (g>=0 && p[g].imaginaria == 0 && p[g].real == 0)
		--g;
	return g;
}

QRatio Pol::operator[](int k) const
{
	if (k>n)
		return 0.0;
	else
		return p[k];
}

QRatio& Pol::operator[](int k)
{
	return p[k];
}

Pol& Pol::operator = (const Pol& q)
{
	delete [] p;
	n= q.Gr();
	p= new QRatio[n+1];
	for (int k=0; k<=n; ++k)
		p[k]= q[k];	
	return *this;
}

istream& operator>> (istream& inp, Pol& p)
{
	int n;
	inp >> n;
	Pol q(n);
	cout << q << endl;
	for (int k=0; k<=n; ++k)
		inp >> q[k];
	p= q;
	return inp;
}

ostream& operator << (ostream& out, const Pol& p)
{
	if (p.Gr() < 0)
		cout << 0.0;
	else
		for (int k=p.Gr(); k>=0; --k) 
			out << showpos << p[k] << "x^" << noshowpos << k;
	return out;
}

Pol operator + (const Pol& a, const Pol& b)
{
	int g;
	if (a.Gr() > b.Gr())
		g= a.Gr();
	else
		g= b.Gr();
	Pol suma(g);
	for (int k=0; k<=g; ++k)
		suma[k]= a[k] + b[k];
	return suma;
}


