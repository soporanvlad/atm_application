#pragma once

#include <iostream>

using namespace std;
typedef int Telem;

struct Element {                                          //data care stocheaza bancnota si numarul ei de aparitii
    Telem valoare;
    int nr_aparitii;
};

class Collection {
private:
    Element *elements;                                    //sir de elemente
    int distinctelements;                                 //nr de elemente distincte
    int capacity;                                         //capacitatea sirului
    void resize();                                        //actualizeaza dimensiunea sirului
public:
    Collection();                                         //constructor fara parametrii
    void add(Telem elem);                                 //adauga noi obiecte in colectie
    bool remove(Telem elem);                              //elimina un obiect din colectie
    bool search(Telem elem);                              //cauta un element in clasa
    int size() const;                                     //returneaza dimensiunea
    int nroccurrences(Telem elem);                        //returneaza numarul de aparitii al obiectului dat
    ~Collection();                                        //destructor
    int getAt(int position);                              //returneaza valoarea obiectului de pe pozitia mentionata
    void set_valoare(Element elem);                       //atribuie numarul de aparitii al unei noi valori
    int get_poz(int position);                            //returneaza nr de aparitii al elem de pe pozitia mentionata
    Collection &operator=(const Collection &a);                   //atribuie unui obiect de tipul colectie un
                                                                  // alt obiect de acelasi tip
    friend ostream &operator<<(ostream &os, const Collection &a); //supra incarcare operator de afisare
};