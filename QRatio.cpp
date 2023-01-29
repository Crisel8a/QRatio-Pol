#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "./QRatio.hpp"


QRatio::QRatio(double r, double i)
{
    real = r;
    imaginaria = i;
}


double QRatio::getReal(void) const
{
    return real;
}


double QRatio::getImaginaria(void) const
{
    return imaginaria;
}


istream& operator >> (istream& inp, QRatio& z)
{
    // Metodo que lee un numero complejo desde cin
    double r, i;

    // TODO: Implementar lectura de numeros en forma p/q
	// Leyendo la parte real
    cout << "Ingresa parte real: ";
    inp >> r;
    // Leyendo la parte imaginaria
    cout << "Ingresa parte imaginaria: ";
	inp >> i;

    z = QRatio(r, i);
	
    return inp;
}


ostream& operator << (ostream& out, const QRatio& z)
{
    // Metodo que muestra en consola un numero complejo desde cout
	
    // noshowpos 

    // TODO: Optimizar xd y poner el caso cuando imaginaria vale -1
    bool real_zero = z.getReal() == 0;
    bool imaginaria_zero = z.getImaginaria() == 0;

    if(real_zero){
        if(imaginaria_zero){
            out << 0 << endl;
        } else if(z.getImaginaria()){
            out << noshowpos << z.getImaginaria() << "i" << endl;
        }
    }


    if(z.getReal() == 0 && z.getImaginaria() == 0)
        out << 0 << endl;
    else if(z.getImaginaria() == 0)
        out << noshowpos << z.getReal() << endl;
    else if(z.getReal() == 0 && z.getImaginaria() != 1)
        out << noshowpos << z.getImaginaria() << "i" << endl;
    else if(z.getReal() == 0 && z.getImaginaria() == 1)
        out << noshowpos << "i" << endl;
    else if(z.getImaginaria() == 1)
        out <<  noshowpos << z.getReal()  << "+i" << endl;
    else
         out << noshowpos << z.getReal() << showpos << z.getImaginaria() << "i" << endl;
    
	return out;
}


QRatio operator + (const QRatio& z, const QRatio& w)
{
    double r, i;
    r = z.getReal() + w.getReal();
    i = z.getImaginaria() + w.getImaginaria();

    return QRatio(r, i);
}


QRatio operator - (const QRatio& z, const QRatio& w)
{

    double r, i;
    r = z.getReal() - w.getReal();
    i = z.getImaginaria() - w.getImaginaria();

    return QRatio(r, i);
}


QRatio operator * (const QRatio& z, const QRatio& w)
{
    //(a+bi)(c+di) =  a*c + (b*c)i + (a*d)i + (b*d)i^2 = a*c + (b*c)i + (a*d)i + (b*d)(-1) 
    double r, i; 
    r = z.getReal()*w.getReal() - z.getImaginaria()*w.getImaginaria();
    i = z.getImaginaria()*w.getReal() + z.getReal()*w.getImaginaria();

    return QRatio(r, i);
}


QRatio operator / (const QRatio& z, const QRatio& w)
{
 
    double r, i;
    r = (z.getReal()*w.getReal() + z.getImaginaria()*w.getImaginaria())/(w.getReal()*w.getReal() + w.getImaginaria()*w.getImaginaria());
    i = (z.getImaginaria()*w.getReal() - z.getReal()*w.getImaginaria())/(w.getReal()*w.getReal() + w.getImaginaria()*w.getImaginaria());

    return QRatio(r, i);
}