#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "./QRatio.hpp"


QRatio::QRatio() 
{
    return;   
}


istream& operator>> (istream& inp, QRatio& z)
{
    // Metodo que lee un numero complejo desde cin
	QRatio w;

    // TODO: Implementar lectura de numeros en forma p/q
	// Leyendo la parte real
    cout << "Ingresa parte real: ";
    inp >> w.real;
    // Leyendo la parte imaginaria
    cout << "Ingresa parte imaginaria: ";
	inp >> w.imaginaria;

    z = w;
	
    return inp;
}


ostream& operator << (ostream& out, const QRatio& z)
{
    // Metodo que muestra en consola un numero complejo desde cout
	
    // noshowpos 

    // TODO: Optimizar xd y poner el caso cuando imaginaria vale -1
    if(z.real == 0 && z.imaginaria == 0)
        out << 0 << endl;
    else if(z.imaginaria == 0)
        out << noshowpos << z.real << endl;
    else if(z.real == 0 && z.imaginaria != 1)
        out << noshowpos << z.imaginaria << "i" << endl;
    else if(z.real == 0 && z.imaginaria == 1)
        out << noshowpos << "i" << endl;
    else if(z.imaginaria == 1)
        out <<  noshowpos << z.real  << "+i" << endl;
    else
         out << noshowpos << z.real << showpos << z.imaginaria << "i" << endl;
    
	return out;
}


QRatio operator + (const QRatio& z, const QRatio& w)
{
	QRatio resultado;

    resultado.real = z.real + w.real;
    resultado.imaginaria = z.imaginaria + w.imaginaria;

    return resultado;
}


QRatio operator - (const QRatio& z, const QRatio& w)
{
	QRatio resultado;

    resultado.real = z.real - w.real;
    resultado.imaginaria = z.imaginaria - w.imaginaria;

    return resultado;
}


QRatio operator * (const QRatio& z, const QRatio& w)
{
    //(a+bi)(c+di) =  a*c + (b*c)i + (a*d)i + (b*d)i^2 = a*c + (b*c)i + (a*d)i + (b*d)(-1) 
	QRatio resultado;

    resultado.real = z.real*w.real - z.imaginaria*w.imaginaria;
    resultado.imaginaria = z.imaginaria*w.real + z.real*w.imaginaria;

    return resultado;
}


QRatio operator / (const QRatio& z, const QRatio& w)
{
 
	QRatio resultado;

    resultado.real = (z.real*w.real + z.imaginaria*w.imaginaria)/(w.real*w.real + w.imaginaria*w.imaginaria);
    resultado.imaginaria = (z.imaginaria*w.real - z.real*w.imaginaria)/(w.real*w.real + w.imaginaria*w.imaginaria);

    return resultado;
}