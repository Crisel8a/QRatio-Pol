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
		p[k]= QRatio(0,0);
}

Pol::~Pol(void)
{
	delete [] p;
}

int Pol::Gr(void) const
{
	int g= n;
	while (g>=0 && p[g].getImaginaria() == 0 && p[g].getReal() == 0)
		--g;
	return g;
}

QRatio Pol::operator[](int k) const
{
	if (k>n)
		return QRatio(0,0);  
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
    cout << "Introduce el grado del polinomio: ";
	inp >> n;
	Pol q(n);
	//cout << q << endl;
	for (int k=0; k<=n; ++k){
        cout << "\nIngresa el coeficiente x^" << k << endl;
		inp >> q[k];
    }
	p= q;
	return inp;
}

ostream& operator << (ostream& out, const Pol& p)
{
	if (p.Gr() < 0)
		cout << 0.0;
	else{
		for (int k=p.Gr(); k>0; --k) 
			out << "(" << p[k] << ")" << "x^" << noshowpos << k << " + ";
        out << "(" << p[0] << ")" << "x^" << noshowpos << 0;
    }
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


Pol operator - (const Pol& a, const Pol& b)
{
	int g;
	if (a.Gr() > b.Gr())
		g= a.Gr();
	else
		g= b.Gr();
	Pol resta(g);
	for (int k=0; k<=g; ++k)
		resta[k]= a[k] - b[k];
	return resta;
}


Pol operator * (const Pol& a, const Pol& b)
{
	int g=a.Gr() + b.Gr();
	Pol prod(g);
	for (int k=0; k<=a.Gr(); ++k){
		for (int j=0;j<=b.Gr();j++){
            prod[k+j] = prod[k+j] + a[k]*b[j];

        }
    }    

	return prod;
}


Pol operator / (const Pol& a, const Pol& b)
{
	int g;
	Pol numerador, denominador;
    if(a.Gr()<b.Gr()){
		denominador = a;
		numerador = b;

    }else{
		numerador = a;
		denominador = b;
    }

	g = numerador.Gr() - denominador.Gr();
	Pol cociente(g);

	do {
		cociente[g] = numerador[numerador.Gr()]/denominador[denominador.Gr()];
		Pol nuevo(numerador.Gr());
		nuevo = cociente*denominador;
		numerador = numerador - nuevo;
	} while (numerador.Gr() >= denominador.Gr());

	return cociente + numerador*denominador;
}


Pol operator % (const Pol& a, const Pol& b){
	int g;
	Pol numerador, denominador;
    if(a.Gr()<b.Gr()){
		denominador = a;
		numerador = b;

    }else{
		numerador = a;
		denominador = b;
    }

	g = numerador.Gr() - denominador.Gr();
	Pol cociente(g);

	do {
		cociente[g] = numerador[numerador.Gr()]/denominador[denominador.Gr()];
		Pol nuevo(numerador.Gr());
		nuevo = cociente*denominador;
		numerador = numerador - nuevo;
	} while (numerador.Gr() >= denominador.Gr());

	return numerador;
}


Pol mcd (const Pol& a, const Pol& b){

	Pol aux_a(a.Gr());
	for(int i = 0;  i <= a.Gr(); i++){
		aux_a[i] = a[i];
	}
	Pol aux_b(b.Gr());
	for(int i = 0;  i <= b.Gr(); i++){
		aux_b[i] = b[i];
	}

	Pol r;
	while (true){
		r = aux_a%aux_b;
		if(r.Gr() <= 0){
			return aux_b;
		}
		aux_a = aux_b;
		aux_b = r;
	}
}
