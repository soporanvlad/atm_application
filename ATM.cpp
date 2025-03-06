#include "ATM.h"


void ATM::afisare_colectie(const Element *bacnote, int lungime, int indice)
{
	cout << indice << ")     ";
	indice++;
	for (int i = 0; i < lungime; i++) {
		cout<<"bancnota : "<<bacnote[i].valoare << " in numar de " << bacnote[i].nr_aparitii << " exemplare ";
	}
	cout << endl;
}

ATM::ATM()
{
	this->colectie_bancnote;
	this->nr_tranzactii = 0;
	this->tranzactii = nullptr;

}

ATM::ATM(const Collection& colectie, Tranzaction tranzactie[], int nr_tranzactii)
{
	this->colectie_bancnote = colectie;
	this->nr_tranzactii = nr_tranzactii;
	this->tranzactii = new Tranzaction[nr_tranzactii];
	for (int i = 0; i < this->nr_tranzactii; i++) {
		tranzactii[i] = tranzactie[i];
	}
}

void ATM::Retragere_numerar(int id, int suma, int lungime,Element *bancnote)
{
	int ok = 1;
	for (int i = 0; i < lungime; i++)
		if (bancnote[i].nr_aparitii > this->colectie_bancnote.nroccurrences(bancnote[i].valoare)) {
			ok = 0;
		}
	if (!ok)
		cout << "Momentan ATM-ul nu dispune de toate bancnotele necesare tranzactiei" << endl;
	else
	{
		Element a{};
		for (int i = 0; i < lungime; i++) {
			a.valoare = bancnote[i].valoare;
			cout <<"Bancnota "<< a.valoare << " in numar de " << bancnote[i].nr_aparitii <<" exemplare"<< endl;
			a.nr_aparitii = this->colectie_bancnote.nroccurrences(a.valoare) - bancnote[i].nr_aparitii;
			this->colectie_bancnote.set_valoare(a);
		}
		this->tranzactii[this->nr_tranzactii] = Tranzaction(id, suma, bancnote, lungime);
		this->nr_tranzactii++;
	}
}

void ATM::Add_bacnote(TElem valoare)
{

		this->colectie_bancnote.add(valoare);
}

void ATM::Elim_bacnota(TElem valoare)
{
		colectie_bancnote.remove(valoare);
}

void ATM::Get_tranzactia(int& poz_stop, int suma, Element *bancnote, int lungime, int poz)
{
	if (suma == 0)
	{
		poz_stop--;
		bancnote[lungime].valoare = -1;
	}
	else {
		for (int i = poz; i < this->colectie_bancnote.size() && poz_stop; i++) {
			if (poz_stop == 0) break;
			int k = 0;
			TElem bancnota = this->colectie_bancnote.getAt(i);
			while (suma >= 0) {
				suma = suma - bancnota;
				k++;
				bancnote[lungime].valoare = bancnota;
				bancnote[lungime].nr_aparitii = k;
				Get_tranzactia(poz_stop, suma, bancnote, lungime + 1, i + 1);
				if (poz_stop == 0) break;
			}
			if (suma < 0) {
				suma = suma + bancnota;
				k--;
				bancnote[lungime].nr_aparitii = k;
			}
			suma = suma + k * bancnota;
		}
	}
    lungime++;
}

ATM::~ATM()
= default;

void ATM::Generare_Tranzactii(int& indice, int suma,Element *bancnote, int lungime, int poz)
{
	if (suma == 0)
		afisare_colectie(bancnote, lungime, indice);
	else {
		int c = this->colectie_bancnote.size();
		for (int i = poz; i < c; i++) {
			int k = 0;
			TElem bancnota = this->colectie_bancnote.getAt(i);
			while (suma >= 0) {
				suma = suma - bancnota;
				k++;
				bancnote[lungime].valoare = bancnota;
				bancnote[lungime].nr_aparitii = k;
				if (suma == 0) indice++;
				Generare_Tranzactii(indice, suma, bancnote, lungime + 1, i + 1);
			}
			if (suma < 0) {
				suma = suma + bancnota;
				k--;
				bancnote[lungime].nr_aparitii = k;
			}
			suma = suma + k * bancnota;
		}
	}
}

ostream& operator<<(ostream& os,const ATM& atm)
{
	cout << "          ATM      " << endl;
	cout << atm.colectie_bancnote;
	for (int i = 0; i < atm.nr_tranzactii; i++) {
		cout << atm.tranzactii[i]<<" "<<endl;
	}
	return os;
}

