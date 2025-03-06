#include "Tranzaction.h"
#include <iostream>

using namespace std;

Tranzaction::Tranzaction()
{
	this->idTranzactie = -1;
	this->suma = 0;
	this->nr_bancnote = 0;
	this->bacnota = new Element[nr_bancnote];
}

Tranzaction::Tranzaction(int id, int suma, Element* bancnote, int nr_bancnote)
{
	this->idTranzactie = id;
	this->nr_bancnote = nr_bancnote;
	this->suma = suma;
	this->bacnota = new Element[nr_bancnote];
	for (int i = 0; i < nr_bancnote; i++)
	{
        bacnota[i].valoare = bancnote[i].valoare;
		bacnota[i].nr_aparitii = bancnote[i].nr_aparitii;
	}
	delete[] bancnote;
}

Tranzaction& Tranzaction::operator=(const Tranzaction& tranzactie)
{

	this->idTranzactie = tranzactie.idTranzactie;
	this->nr_bancnote = tranzactie.nr_bancnote;
	this->suma = tranzactie.suma;
	this->bacnota = new Element[nr_bancnote];
	for (int i = 0; i < nr_bancnote; i++)
	{
		this->bacnota[i] = tranzactie.bacnota[i];
	}
	return *this;
}

Tranzaction::~Tranzaction()
{
	delete[] bacnota;
}

ostream& operator<<(ostream& os, const Tranzaction& tranzaction)
{
    cout<<endl;
	cout << "id-ul tranzactiei este " << tranzaction.idTranzactie << " iar suma retrasa este  " << tranzaction.suma << endl;
	cout << "Tranzactia s-a efectuat folosind urmatoarele : ";
	for (int i = 0; i < tranzaction.nr_bancnote; i++)
		cout <<"bancnota de "<< tranzaction.bacnota[i].valoare << " retrasa in numar de " << tranzaction.bacnota[i].nr_aparitii << " exemplare , ";
	cout << endl;
	return os;
}
