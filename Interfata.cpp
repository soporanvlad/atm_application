#include "Interfata.h"
#include "ATM.h"
#include "Colection.h"
#include<iostream>
using namespace std;

int id = 1;

//#######PREDEFINITE############

////------INTERFATA-------
void print_meniu() {
    cout << endl;
    cout<<"             MENIU "<<endl;
    cout<<"________________________________"<<endl;
    cout << "1. Afisare bancnote si istoricul tranzactiilor din ATM" << endl;
    cout << "2. Adaugare bancnote in ATM" << endl;
    cout << "3. Eliminare bancnota din ATM" << endl;
    cout << "4. Efectuare Tranzactie" << endl;
    cout << "5. Exit" << endl;
    cout << "ALEGETI O OPTIUNE: ";
}

///---GENERATOR_BANCNOTE---
void adauga_bacnote(ATM& atm) {
    int i = 1;
    while (i <= 20) {
        atm.Add_bacnote(50);
        atm.Add_bacnote(100);
        atm.Add_bacnote(200);
        i++;
    }
    i = 1;
    while (i <= 20) {
        atm.Add_bacnote(10);
        atm.Add_bacnote(20);
        atm.Add_bacnote(5);
        i++;
    }

}


//###########CERINTE###########

///---ADAUGARE_BANCNOTE---
void add_bacnote(ATM& atm) {
    TElem element;
    cout << "Introduceti valoarea bancnotei: ";
    cin >> element;
    cout << "Introduceti numarul de aparitii: ";
    int nr_aparitii;
    cin >> nr_aparitii;
    int i = 1;
    while (i <= nr_aparitii) {
        atm.Add_bacnote(element);
        i++;
    }
}

///--ELIMINARE-BANCNOTA--
void elim_bancnota(ATM& atm) {
    cout << "Introduceti bancnota pe care doriti sa o eliminati: ";
    TElem element;
    cin >> element;
    atm.Elim_bacnota(element);
}

///-------TRANZACTIE------
void efectuare_tranzactie(ATM& atm) {
    int suma, lungime = 0, poz = 0, indice = 0, int_poz = 0;
    auto* bancnote = new Element[100];
    cout << endl << "Introduceti suma dorita: ";
    cin >> suma;
    cout << "Metodele de plata sunt: " << endl;
    atm.Generare_Tranzactii(indice, suma, bancnote, lungime, poz);

    cout<<endl;
    cout << "Alegeti metoda de plata SAU 0 pentru anulare: ";
    cin >> int_poz;
    cout<<endl;
    indice = 0;
    if (int_poz == 0) {
        cout << "Tranzactie respinsa"<<endl;
    }
    else {
        atm.Get_tranzactia(int_poz, suma, bancnote, lungime, poz);
        cout<<"Tranzactie aprobata cu succes."<<endl<<endl<<"Selectia dumneavoastra a fost"<<endl;

        while (bancnote[lungime].valoare >= 0)
            lungime++;
        atm.Retragere_numerar(id, suma, lungime, bancnote);
        id++;
    }
}

///--------MENIU---------

void Meniu() {
    int opt = 1;
    Collection colectie;
     
    int nr_tranzactii = 0,conditie=1;
    auto* tranzactie = new Tranzaction[100];
    ATM atm(colectie, tranzactie, nr_tranzactii);
    adauga_bacnote(atm);
    while (conditie) {
        print_meniu();
        cin >> opt;
        cout<<endl;
        switch (opt) {
        case 1:
            cout<<atm;
            cout<<endl;
            if(id<=1)
                cout<<"Nu s-au efectuat tranzactii azi!"<<endl;
            break;
        case 2:
            add_bacnote(atm);
            break;
        case 3:
            elim_bancnota(atm);
            break;
        case 4:
            efectuare_tranzactie(atm);
            break;
        default:
            break;
        }
        if (opt == 5)
            conditie = 0;
    }
}