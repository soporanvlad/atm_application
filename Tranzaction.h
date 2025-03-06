#pragma once
#include "Colection.h"
#include<iostream>

using namespace std;
typedef int TElem;

class Tranzaction {
private:
	int idTranzactie;
	int suma;
	Element* bacnota;
    int nr_bancnote;
public:
    Tranzaction();                                                        //constructor implicit
    Tranzaction(int id, int suma, Element* bancnote, int nr_bancnote);    //constructor cu parametrii
    ~Tranzaction();                                                       //destructor
    friend ostream& operator<<(ostream& os, const Tranzaction& tranzactie);      //Supra incarcare operator afisare
    Tranzaction& operator=(const Tranzaction& tranzactie);                //operator de atribuire
};
