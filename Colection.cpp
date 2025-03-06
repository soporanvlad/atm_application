#include "Colection.h"
#include <iostream>
using namespace std;

//IMPLEMENTARE DE LA SEMINAR

void Collection::resize()
{
		this->capacity = this->capacity * 2;
		auto* new_elem = new Element[this->capacity];
		for (int i = 0; i < this->size(); i++) {
			new_elem[i] = this->elements[i];
		}
		delete[] elements;
		this->elements = new_elem;
		
}

Collection::Collection()
{
	this->capacity = 10;
	this->distinctelements = 0;
	this->elements = new Element[this->capacity];
}

void Collection::add(Telem elem)
{
	if (search(elem)) 
	{
		int ok = 1;
		for (int i = 0; i < this->distinctelements && ok; i++)
			if (this->elements[i].valoare == elem)
			{
				this->elements[i].nr_aparitii++;
				ok = 0;
			}
	}
	else 
	{
			if (this->distinctelements == capacity)
				resize();
			this->elements[this->distinctelements].nr_aparitii = 1;
			this->elements[this->distinctelements].valoare = elem;
			this->distinctelements++;
	}
}

bool Collection::remove(Telem elem)
{
   if (search(elem))
	{ 
		int ok = 1;
		for (int i = 0; i < distinctelements && ok==1; i++)
		{
			if (elements[i].valoare == elem && distinctelements > 1)
			{   
				ok = 0;
				for (int j = i; j < distinctelements; j++)
				{
					this->elements[i].valoare = this->elements[i + 1].valoare;
					this->elements[i].nr_aparitii = this->elements[i+1].nr_aparitii;
				}
				this->distinctelements--;
			}
		}

		return true;
	}
	return false;
}



bool Collection::search(Telem elem)
{   
	for (int i = 0; i < this->distinctelements; i++) {
		if (this->elements[i].valoare == elem)
			return true;
	}
	return false;
}

int Collection::size() const
{
	return this->distinctelements;
	
}

int Collection::nroccurrences(Telem elem)
{
	if (search(elem))
	{
		int i = 0;
		while (i < distinctelements)
		{
			if (this->elements[i].valoare == elem)
				return elements[i].nr_aparitii;
			i++;
		}
	}
		return 0;
}

Collection::~Collection()
{
		delete[] elements;
	this->distinctelements = 0;
	this->capacity = 0;
}

int Collection::getAt(int position)
{
	return elements[position].valoare;
}



//################      IMPLEMENTARE IN PLUS



void Collection::set_valoare(Element elem)
{    
	if(search(elem.valoare))
	{
		int i = 0;
		while (this->elements[i].valoare != elem.valoare)
			i++;
		this->elements[i].nr_aparitii = elem.nr_aparitii;
	}
}

int Collection::get_poz(int position)
{
	return elements[position].nr_aparitii;
}

ostream& operator<<(ostream& os, const Collection& a)
{
	cout << "ATM-ul dispune de urmatoarele bancnote:" << endl;
	for (int i = 0; i < a.distinctelements; i++) {
		cout <<"bancnota: "<< a.elements[i].valoare << " in numar de : " << a.elements[i].nr_aparitii <<" exemplare disponibile."<<endl;
	}
	return os;
}

Collection& Collection::operator=(const Collection& colectie) {
    this->distinctelements = colectie.distinctelements;
    this->capacity = colectie.capacity;
    delete[] this->elements;
    this->elements = new Element[this->capacity];
    for (int i = 0; i < this->capacity; i++)
        this->elements[i] = colectie.elements[i];
    return *this;
}